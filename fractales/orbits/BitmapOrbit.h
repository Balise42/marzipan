#ifndef MARZIPAN_BITMAPORBIT_H
#define MARZIPAN_BITMAPORBIT_H


#include "Orbit.h"
#include "CImg.h"
#include <map>

using namespace cimg_library;

class BitmapOrbit : public Orbit {
public:
    double getOrbitFastValue(std::complex<double> z) override;
    double getOrbitValue(double v) override;

    BitmapOrbit(CImg<unsigned char> * img, double max_value);

private:
    CImg<unsigned char> * bitmap;
    std::map<std::pair<int,int>,double> distances;
    double factor;
    double translation;
};


#endif //MARZIPAN_BITMAPORBIT_H
