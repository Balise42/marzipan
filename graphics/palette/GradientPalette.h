#ifndef MARZIPAN_GRADIENTPALETTE_H
#define MARZIPAN_GRADIENTPALETTE_H


#include "graphics/Color.h"
#include "Palette.h"
#include "RepeatingGradientPalette.h"

class GradientPalette : public RepeatingGradientPalette {
public:
    GradientPalette(int min, int max, Color cmin, Color cmax);

    void set_iteration_dependent(int iter);
};


#endif //MARZIPAN_GRADIENTPALETTE_H
