#ifndef MARZIPAN_MANDELBROT_H
#define MARZIPAN_MANDELBROT_H


#include <complex>
#include "../graphics/canvas.h"
#include "../graphics/palette/palette.h"
#include "fractal.h"

class mandelbrot : public fractal {

public:
    mandelbrot() : fractal() {}

    mandelbrot(unsigned int width, unsigned int height) : fractal(width, height) {}

    mandelbrot(unsigned int width, unsigned int height, double left, double right, double top, double bottom)
            : fractal(width, height, left, right, top, bottom) {}

    canvas renderToCanvas();

    void set_palette(palette * pal) {
        this->pal = pal;
    }

    palette * get_palette() {
        return pal;
    }

    void renderToFile();

private:
    palette * pal;
    int computeValue(std::complex<double> z);
};


#endif //MARZIPAN_MANDELBROT_H
