#ifndef MARZIPAN_REPEATING_GRADIENT_PALETTE_H
#define MARZIPAN_REPEATING_GRADIENT_PALETTE_H


#include <graphics/color.h>
#include "palette.h"

class repeating_gradient_palette : public palette {
public:
    repeating_gradient_palette(int min, int max, color cmin, color cmax, int num_cols);
    ~repeating_gradient_palette();
    color compute_color(int value) override;

protected:
    int min, max, num_cols;
    void generate_palette();

private:
    color cmin, cmax;
    color * colors;


    bool is_iteration_dependent() override;

    void set_iteration_dependent(int iter) override;

    unsigned char compute_component(int value, unsigned char v1, unsigned char v2, int num_cols);
};


#endif //MARZIPAN_REPEATING_GRADIENT_PALETTE_H
