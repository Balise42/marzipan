
#ifndef MARZIPAN_CONTINUOUSPALETTE_H
#define MARZIPAN_CONTINUOUSPALETTE_H


#include "Palette.h"

class ContinuousPalette : public Palette {
public:

    ContinuousPalette(int min, int max, Color cmin, Color cmax, Color inner_color, int num_cols);

    Color compute_color(double value) override;

private:
    int min;
    int max;
    Color cmin;
    Color cmax;
    int num_cols;

    unsigned char compute_component(double value, unsigned char v1, unsigned char v2);

    bool is_iteration_dependent();

    void recompute(Fractal *fractal);

};


#endif //MARZIPAN_CONTINUOUSPALETTE_H
