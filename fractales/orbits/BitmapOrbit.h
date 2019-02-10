#ifndef MARZIPAN_BITMAPORBIT_H
#define MARZIPAN_BITMAPORBIT_H


#include "Orbit.h"
#include "CImg.h"

using namespace cimg_library;

class BitmapOrbit : public Orbit {
public:
    double getOrbitFastValue(std::complex<double> z) override;
    double getOrbitValue(double v) override;

    BitmapOrbit(CImg<unsigned char> * img, double max_value);

private:
    CImg<unsigned char> * bitmap;
    double** distances = new double*[900];
    double factor;
    double translation;
    double precompute_distance(const int x, const  int y);
};


#endif //MARZIPAN_BITMAPORBIT_H
