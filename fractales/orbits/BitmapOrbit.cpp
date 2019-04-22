
#include <iostream>
#include <fractales/orbits/util/BitmapMapComputer.h>
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
