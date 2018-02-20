#ifndef MARZIPAN_MANDELBROT_H
#define MARZIPAN_MANDELBROT_H


#include <complex>
#include "Canvas.h"
#include "GradientPalette.h"

class Mandelbrot {

public:
    void render(Canvas * canvas, GradientPalette * palette);
    std::complex<double> scale(unsigned int x, unsigned int y, unsigned int sizex, unsigned int sizey);

private:



    double computeValue(std::complex<double> z);
};


#endif //MARZIPAN_MANDELBROT_H
