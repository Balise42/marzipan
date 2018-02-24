#ifndef MARZIPAN_MANDELBROT_H
#define MARZIPAN_MANDELBROT_H


#include <complex>
#include "../graphics/canvas.h"
#include "../graphics/palette/palette.h"
#include "fractale.h"

class mandelbrot : public fractale {

public:
    mandelbrot() : fractale() {}

    mandelbrot(unsigned int width, unsigned int height) : fractale(width, height) {}

    mandelbrot(unsigned int width, unsigned int height, double left, double right, double top, double bottom)
            : fractale(width, height, left, right, top, bottom) {}

    canvas renderToCanvas();

    void set_maxiter(int iter) {
        this->maxiter = iter;
    }

    void set_palette(palette * pal) {
        this->pal = pal;
    }

    void renderToFile();

private:
    palette * pal;
    int computeValue(std::complex<double> z);
};


#endif //MARZIPAN_MANDELBROT_H
