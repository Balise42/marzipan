#ifndef MARZIPAN_ORBITMANDELBROT_H
#define MARZIPAN_ORBITMANDELBROT_H


#include "ContinuousMandelbrot.h"

class OrbitMandelbrot : public ContinuousMandelbrot {
public:
    void set_orbit(double x, double y, double max_value);
    double compute_value(std::complex<double> c) override;

    OrbitMandelbrot() : ContinuousMandelbrot() {}

    OrbitMandelbrot(unsigned int width, unsigned int height) : ContinuousMandelbrot(width, height) {}

    OrbitMandelbrot(unsigned int width, unsigned int height, double left, double right, double top, double bottom)
            : ContinuousMandelbrot(width, height, left, right, top, bottom) {}

private:
    double orbitX = 0.0;
    double orbitY = 0.0;
    double factor = 25.0;
    double translation = 0.0;

    double squared_dist_to_orbit(std::complex<double> z);
};


#endif //MARZIPAN_ORBITMANDELBROT_H
