#ifndef MARZIPAN_PALETTE_H
#define MARZIPAN_PALETTE_H

#include "Color.h"

class Palette {
public:
    virtual Color computeColor(double value) = 0;
};


#endif //MARZIPAN_PALETTE_H
