#ifndef MARZIPAN_PALETTE_H
#define MARZIPAN_PALETTE_H

#include "../color.h"

class palette {
public:
    virtual color compute_color(int value) = 0;
    virtual bool is_iteration_dependent() = 0;
    virtual void set_iteration_dependent(int iter) = 0;
};


#endif //MARZIPAN_PALETTE_H
