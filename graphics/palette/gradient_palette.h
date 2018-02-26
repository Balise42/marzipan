#ifndef MARZIPAN_GRADIENTPALETTE_H
#define MARZIPAN_GRADIENTPALETTE_H


#include "../color.h"
#include "palette.h"
#include "repeating_gradient_palette.h"

class gradient_palette : public repeating_gradient_palette {
public:
    gradient_palette(int min, int max, color cmin, color cmax);

    void set_iteration_dependent(int iter);
};


#endif //MARZIPAN_GRADIENTPALETTE_H
