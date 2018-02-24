#ifndef MARZIPAN_GRADIENTPALETTE_H
#define MARZIPAN_GRADIENTPALETTE_H


#include "../color.h"
#include "palette.h"

class gradient_palette : public palette {
public:
    gradient_palette(int min, int max, color cmin, color cmax);
    color compute_color(int value);

private:
    int min;
    int max;
    color cmin;
    color cmax;
    gradient_palette();

    unsigned char compute_component(int value, unsigned char v1, unsigned char v2);

    void set_iteration_dependent(int iter);

    bool is_iteration_dependent();
};


#endif //MARZIPAN_GRADIENTPALETTE_H
