#include <utility>

#include <utility>

#include <utility>

#ifndef MARZIPAN_ORBITMANDELBROT_H
#define MARZIPAN_ORBITMANDELBROT_H


#include <fractales/orbits/Orbit.h>
#include <vector>
#include "ContinuousMandelbrot.h"

class OrbitMandelbrot : public ContinuousMandelbrot {
public:
    double compute_value(std::complex<double> c) override;

    explicit OrbitMandelbrot(std::vector<Orbit *> o) : ContinuousMandelbrot() {
        this->orbits = std::move(o);
    }

    OrbitMandelbrot(std::vector<Orbit *> o, unsigned int width, unsigned int height) : ContinuousMandelbrot(width, height) {
        this->orbits = std::move(o);
    }

    OrbitMandelbrot(std::vector<Orbit *> o, unsigned int width, unsigned int height, double left, double right, double top, double bottom)
            : ContinuousMandelbrot(width, height, left, right, top, bottom) {
        this->orbits = std::move(o);
    }

    Fractal * clone() override;

    FractalProto * serialize() override;

    static OrbitMandelbrot * deserialize(FractalProto * ofp);

private:
    std::vector<Orbit *> orbits;
};


#endif //MARZIPAN_ORBITMANDELBROT_H
