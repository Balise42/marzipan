
#include <iostream>
#include <fractales/orbits/util/BitmapMapComputer.h>
#undef Status
#include "BitmapOrbit.h"

double BitmapOrbit::getOrbitFastValue(std::complex<double> z) {
    double x = z.real();
    double y = z.imag();

    int xImg = (( int) ((x + 2) / 3 * 899));

    int yImg = 600- ( int) ((y + 1) / 2 * 599);

    if (distances.count(std::make_pair(xImg, yImg)) == 0) {
        return INT_MAX;
    }
    return distances[std::make_pair(xImg,yImg)];
}

double BitmapOrbit::getOrbitValue(double v) {
    if (v == INT_MAX) {
        return INT_MAX;
    }
    double res =  (v - this->translation) * this->factor;
    return res;
}

BitmapOrbit::BitmapOrbit(CImg<unsigned char> *img, double max_value) {
    this->max_value = max_value;
    this->bitmap = img;
    CImg<unsigned char> * map = new CImg<unsigned char>(900, 600, 1, 3, 0);

    BitmapMapComputer bc;
    bc.computeMap(this->bitmap, &this->distances);

    map->save_bmp("map.bmp");

    double minDist = 0.0;
    double maxDist = 0.0;
    for (auto v : distances) {
        if (v.second > maxDist) {
            maxDist = v.second;
        }
    }

    this->factor = (max_value - minDist) / (maxDist - minDist);
    this->translation = minDist;
}

OrbitProto * BitmapOrbit::serialize() {
    auto bitmapOrbitProto = new BitmapOrbitProto();
    size_t size = bitmap->size() * sizeof(unsigned char);
    const char * data = (char *)(malloc(size));
    memcpy((void *)data, (void *)(bitmap->_data), size);
    bitmapOrbitProto->set_bitmap(data);
    bitmapOrbitProto->set_width(bitmap->width());
    bitmapOrbitProto->set_height(bitmap->height());
    auto res = new OrbitProto();
    res->set_max_value(max_value);
    res->set_allocated_bitmaporbit(bitmapOrbitProto);
    return res;
}

BitmapOrbit * BitmapOrbit::deserialize(OrbitProto *op) {
    auto * img = new CImg<unsigned char>((unsigned char *) op->bitmaporbit().bitmap().c_str(), (unsigned int)(op->bitmaporbit().width()), (unsigned int)(op->bitmaporbit().height()), 1, 3);
    return new BitmapOrbit(img, op->max_value());
}
