#ifndef MARZIPAN_JULIA_H
#define MARZIPAN_JULIA_H


#include <complex>
#include "graphics/ImageCanvas.h"
#include "graphics/palette/Palette.h"
#include "Fractal.h"

class Julia : public Fractal {

public:
    Julia() : Fractal() {}

    Julia(unsigned int width, unsigned int height) : Fractal(width, height, -1.5, 1.5, 1.2, -1.2) {}

    Julia(unsigned int width, unsigned int height, double left, double right, double top, double bottom)
            : Fractal(width, height, left, right, top, bottom) {}

    double compute_value(std::complex<double> z) override;
};


#endif //MARZIPAN_JULIA_H
