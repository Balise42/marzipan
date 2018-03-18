#include "GradientPalette.h"
#include "RepeatingGradientPalette.h"

GradientPalette::GradientPalette(int min, int max, Color cmin, Color cmax) : RepeatingGradientPalette(min, max, cmin, cmax, max - min + 1) {
}

void GradientPalette::set_iteration_dependent(int iter) {
    this->max = iter;
    this->num_cols = max - min + 1;
    generate_palette();
}