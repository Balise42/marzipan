#ifndef MARZIPAN_HISTO_PALETTE_H
#define MARZIPAN_HISTO_PALETTE_H


#include <vector>
#include "palette.h"
#include "repeating_gradient_palette.h"

class histo_palette : public repeating_gradient_palette {
public:

    histo_palette(std::vector<int> histo, color cmin, color cmax, int num_cols);

    histo_palette(std::vector<int> histo, color cmin, color cmax, int num_cols, color inner_color);

    bool is_iteration_dependent() override;

    void set_iteration_dependent(int iter) override {
        //nop
    }

    color compute_color(int value) override;

private:
    int total = 0;
    std::vector<int> histo;
};


#endif //MARZIPAN_HISTO_PALETTE_H
