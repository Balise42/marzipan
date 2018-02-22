#include "palette.h"

#ifndef MARZIPAN_RANDOM_PALETTE_H
#define MARZIPAN_RANDOM_PALETTE_H


class random_palette : public palette {
private:
    color * colors;
    int min;

public:
    random_palette(int min, int max);
    color compute_color(int value);
};


#endif //MARZIPAN_RANDOM_PALETTE_H
