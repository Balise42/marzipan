#ifndef MARZIPAN_PALETTE_H
#define MARZIPAN_PALETTE_H

#include "../color.h"

class palette {
public:
    virtual color compute_color(double value) = 0;
};


#endif //MARZIPAN_PALETTE_H
