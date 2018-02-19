#ifndef MARZIPAN_MANDELBROT_H
#define MARZIPAN_MANDELBROT_H


#include "Canvas.h"
#include "GradientPalette.h"

class Mandelbrot {

public:
    void render(Canvas * canvas, GradientPalette * palette);

private:
    double computeValue(double x, double y);

    double scale(unsigned int coord, unsigned int size);
};


#endif //MARZIPAN_MANDELBROT_H
