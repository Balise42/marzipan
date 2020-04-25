#ifndef MARZIPAN_MANDELBROT_H
#define MARZIPAN_MANDELBROT_H


#include <complex>
#include <vector>
#include "graphics/ImageCanvas.h"
#include "graphics/palette/Palette.h"
#include "Fractal.h"
#include "MpComplex.h"

class Mandelbrot : public Fractal {

public:
    Mandelbrot() : Fractal() {}

    Mandelbrot(unsigned int width, unsigned int height) : Fractal(width, height) {}

    Mandelbrot(unsigned int width, unsigned int height, double left, double right, double top, double bottom)
            : Fractal(width, height, left, right, top, bottom) {}

    std::vector<int> compute_histo();

    double compute_value(MpComplex z) override;

    Fractal * clone() override;

    FractalProto * serialize() override;

    static Mandelbrot * deserialize(FractalProto *fp);
};


#endif //MARZIPAN_MANDELBROT_H
