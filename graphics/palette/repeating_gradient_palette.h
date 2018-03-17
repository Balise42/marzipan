#ifndef MARZIPAN_REPEATING_GRADIENT_PALETTE_H
#define MARZIPAN_REPEATING_GRADIENT_PALETTE_H


#include <graphics/color.h>
#include "palette.h"

class repeating_gradient_palette : public palette {
public:
    repeating_gradient_palette(int min, int max, color cmin, color cmax, int num_cols);

    repeating_gradient_palette(int min, int max, color cmin, color cmax, int num_cols, color inner_color);

    ~repeating_gradient_palette();
    virtual color compute_color(int value) override;
    bool is_iteration_dependent() override;
    void set_iteration_dependent(int iter) override;

protected:
    int min, max, num_cols;
    color * colors;
    void generate_palette();

private:
    color cmin, cmax;
    unsigned char compute_component(int value, unsigned char v1, unsigned char v2, int num_cols);
};


#endif //MARZIPAN_REPEATING_GRADIENT_PALETTE_H
