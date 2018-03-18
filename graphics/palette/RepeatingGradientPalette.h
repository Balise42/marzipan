#ifndef MARZIPAN_REPEATING_GRADIENT_PALETTE_H
#define MARZIPAN_REPEATING_GRADIENT_PALETTE_H


#include <graphics/Color.h>
#include "Palette.h"

class RepeatingGradientPalette : public Palette {
public:
    RepeatingGradientPalette(int min, int max, Color cmin, Color cmax, int num_cols);

    RepeatingGradientPalette(int min, int max, Color cmin, Color cmax, int num_cols, Color inner_color);

    ~RepeatingGradientPalette();
    virtual Color compute_color(int value) override;
    bool is_iteration_dependent() override;
    void recompute(Fractal * fractal) override;

protected:
    int min, max, num_cols;
    Color * colors;
    virtual void generate_palette();

private:
    Color cmin, cmax;
    unsigned char compute_component(int value, unsigned char v1, unsigned char v2, int num_cols);
};


#endif //MARZIPAN_REPEATING_GRADIENT_PALETTE_H
