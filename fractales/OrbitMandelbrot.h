#ifndef MARZIPAN_ORBITMANDELBROT_H
#define MARZIPAN_ORBITMANDELBROT_H


#include <fractales/orbits/Orbit.h>
#include "ContinuousMandelbrot.h"

class OrbitMandelbrot : public ContinuousMandelbrot {
public:
    double compute_value(std::complex<double> c) override;

    explicit OrbitMandelbrot(Orbit * o) : ContinuousMandelbrot() {
        this->orbit = o;
    }

    OrbitMandelbrot(Orbit * o, unsigned int width, unsigned int height) : ContinuousMandelbrot(width, height) {
        this->orbit = o;
    }

    OrbitMandelbrot(Orbit * o, unsigned int width, unsigned int height, double left, double right, double top, double bottom)
            : ContinuousMandelbrot(width, height, left, right, top, bottom) {
        this->orbit = o;
    }

private:
    Orbit * orbit;
};


#endif //MARZIPAN_ORBITMANDELBROT_H
