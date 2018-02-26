#include "gradient_palette.h"
#include "repeating_gradient_palette.h"

gradient_palette::gradient_palette(int min, int max, color cmin, color cmax) : repeating_gradient_palette(min, max, cmin, cmax, max - min + 1) {
}

void gradient_palette::set_iteration_dependent(int iter) {
    this->max = iter;
    this->num_cols = max - min + 1;
    generate_palette();
}