#ifndef MARZIPAN_MANDELBROT_H
#define MARZIPAN_MANDELBROT_H


#include <complex>
#include <vector>
#include "graphics/image_canvas.h"
#include "../graphics/palette/palette.h"
#include "fractal.h"

class mandelbrot : public fractal {

public:
    mandelbrot() : fractal() {}

    mandelbrot(unsigned int width, unsigned int height) : fractal(width, height) {}

    mandelbrot(unsigned int width, unsigned int height, double left, double right, double top, double bottom)
            : fractal(width, height, left, right, top, bottom) {}

    virtual image_canvas renderToCanvas();

    std::vector<int> compute_histo();

    void set_palette(palette * pal) {
        this->pal = pal;
    }

    palette * get_palette() {
        return pal;
    }

    void renderToFile();

protected:
    int compute_value(std::complex<double> z);

    palette * pal;
};


#endif //MARZIPAN_MANDELBROT_H
