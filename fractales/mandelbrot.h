#ifndef MARZIPAN_MANDELBROT_H
#define MARZIPAN_MANDELBROT_H


#include <complex>
#include "../graphics/canvas.h"
#include "../graphics/palette/gradient_palette.h"

class mandelbrot {

public:
    mandelbrot();
    mandelbrot(unsigned int width, unsigned int height);
    canvas renderToCanvas(gradient_palette * palette);
    std::complex<double> scale(unsigned int x, unsigned int y);

private:
    unsigned int width = 900;
    unsigned int height = 600;

    double computeValue(std::complex<double> z);
};


#endif //MARZIPAN_MANDELBROT_H
