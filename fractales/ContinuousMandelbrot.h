
#ifndef MARZIPAN_CONTINUOUSMANDELBROT_H
#define MARZIPAN_CONTINUOUSMANDELBROT_H

#include "Fractal.h"

class ContinuousMandelbrot : public Fractal {
public:
    ContinuousMandelbrot() : Fractal() {}

    ContinuousMandelbrot(unsigned int width, unsigned int height) : Fractal(width, height) {}

    ContinuousMandelbrot(unsigned int width, unsigned int height, double left, double right, double top, double bottom)
            : Fractal(width, height, left, right, top, bottom) {}

    double compute_value(std::complex<double> c) override;

    Fractal * clone() override;

    FractalProto * serialize() override;

    static ContinuousMandelbrot * deserialize(FractalProto *fp);
};


#endif //MARZIPAN_CONTINUOUSMANDELBROT_H
