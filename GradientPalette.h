#ifndef MARZIPAN_GRADIENTPALETTE_H
#define MARZIPAN_GRADIENTPALETTE_H


#include "Color.h"
#include "Palette.h"

class GradientPalette : Palette {
public:
    GradientPalette(double min, double max, Color cmin, Color cmax);
    Color computeColor(double value);
private:
    double min;
    double max;
    Color cmin;
    Color cmax;
    GradientPalette();

    unsigned char computeComponent(double value, unsigned char v1, unsigned char v2);
};


#endif //MARZIPAN_GRADIENTPALETTE_H
