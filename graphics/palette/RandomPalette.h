#include "Palette.h"

#ifndef MARZIPAN_RANDOM_PALETTE_H
#define MARZIPAN_RANDOM_PALETTE_H


class RandomPalette : public Palette {
private:
    Color * colors;
    int min;

public:
    RandomPalette(int min, int max);
    RandomPalette(int min, int max, Color inner_color);
    ~RandomPalette();
    Color compute_color(int value) override;

    bool is_iteration_dependent() override;

    void set_iteration_dependent(int iter) override;
};


#endif //MARZIPAN_RANDOM_PALETTE_H
