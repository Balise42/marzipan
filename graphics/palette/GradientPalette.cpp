#include "GradientPalette.h"
#include "RepeatingGradientPalette.h"

GradientPalette::GradientPalette(int min, int max, Color cmin, Color cmax) : RepeatingGradientPalette(min, max, cmin, cmax, max - min + 1) {
}

void GradientPalette::recompute(Fractal * fractal) {
    this->max = fractal->get_maxiter();
    this->num_cols = max - min + 1;
    generate_palette();
}