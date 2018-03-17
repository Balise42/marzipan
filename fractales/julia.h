#ifndef MARZIPAN_JULIA_H
#define MARZIPAN_JULIA_H


#include <complex>
#include "graphics/image_canvas.h"
#include "../graphics/palette/palette.h"
#include "fractal.h"

class julia : public fractal {

public:
    julia() : fractal() {}

    julia(unsigned int width, unsigned int height) : fractal(width, height, -1.5, 1.5, 1.2, -1.2) {}

    julia(unsigned int width, unsigned int height, double left, double right, double top, double bottom)
            : fractal(width, height, left, right, top, bottom) {}

    image_canvas renderToCanvas();

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


#endif //MARZIPAN_JULIA_H
