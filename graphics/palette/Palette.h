#ifndef MARZIPAN_PALETTE_H
#define MARZIPAN_PALETTE_H

#include "graphics/Color.h"

class Palette {
public:
    virtual Color compute_color(int value) = 0;
    virtual bool is_iteration_dependent() = 0;
    virtual void set_iteration_dependent(int iter) = 0;

    Color inner_color;
};


#endif //MARZIPAN_PALETTE_H
