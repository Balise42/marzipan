#ifndef MARZIPAN_GRADIENTPALETTE_H
#define MARZIPAN_GRADIENTPALETTE_H


#include "../color.h"
#include "palette.h"

class gradient_palette : public palette {
public:
    gradient_palette(double min, double max, color cmin, color cmax);
    color compute_color(int value);
private:
    double min;
    double max;
    color cmin;
    color cmax;
    gradient_palette();

    unsigned char compute_component(int value, unsigned char v1, unsigned char v2);
};


#endif //MARZIPAN_GRADIENTPALETTE_H
