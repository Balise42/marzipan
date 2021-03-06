#ifndef MARZIPAN_HISTO_PALETTE_H
#define MARZIPAN_HISTO_PALETTE_H


#include <vector>
#include "Palette.h"
#include "RepeatingGradientPalette.h"

class HistoPalette : public RepeatingGradientPalette {
public:

    HistoPalette(std::vector<int> histo, Color cmin, Color cmax, int num_cols);

    HistoPalette(std::vector<int> histo, Color cmin, Color cmax, int num_cols, Color inner_color);

    bool is_iteration_dependent() override;

    void recompute(Fractal * fractal) override;

    Color compute_color(double value) override;

private:
    int total = 0;
    std::vector<int> histo;
};


#endif //MARZIPAN_HISTO_PALETTE_H
