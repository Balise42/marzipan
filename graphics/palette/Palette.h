#ifndef MARZIPAN_PALETTE_H
#define MARZIPAN_PALETTE_H

#include <fractales/Fractal.h>
#include "graphics/Color.h"

class Palette {
public:
    virtual Color compute_color(double value) = 0;
    virtual bool is_iteration_dependent() = 0;
    virtual void recompute(Fractal * fractal) = 0;

    Color inner_color;
};


#endif //MARZIPAN_PALETTE_H
