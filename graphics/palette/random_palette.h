#include "palette.h"

#ifndef MARZIPAN_RANDOM_PALETTE_H
#define MARZIPAN_RANDOM_PALETTE_H


class random_palette : public palette {
private:
    color * colors;
    int min;

public:
    random_palette(int min, int max);
    random_palette(int min, int max, color inner_color);
    ~random_palette();
    color compute_color(int value) override;

    bool is_iteration_dependent() override;

    void set_iteration_dependent(int iter);
};


#endif //MARZIPAN_RANDOM_PALETTE_H
