#ifndef MARZIPAN_MANDELBROT_H
#define MARZIPAN_MANDELBROT_H


#include <complex>
#include "../graphics/canvas.h"
#include "../graphics/palette/gradient_palette.h"

class mandelbrot {

public:
    mandelbrot();
    mandelbrot(unsigned int width, unsigned int height);
    mandelbrot(unsigned int width, unsigned int height, double left, double right, double top, double bottom);
    canvas renderToCanvas(palette * palette);
    std::complex<double> scale(unsigned int x, unsigned int y);

    void set_maxiter(int iter) {
        this->maxiter = iter;
    }

private:
    unsigned int width = 900;
    unsigned int height = 600;
    double left = -2;
    double right = 1;
    double top = 1;
    double bottom = -1;
    int maxiter = 100;

    int computeValue(std::complex<double> z);
};


#endif //MARZIPAN_MANDELBROT_H
