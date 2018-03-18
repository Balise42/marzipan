//
// Created by isa on 2/26/18.
//

#include <climits>
#include "RepeatingGradientPalette.h"
#include "GradientPalette.h"

RepeatingGradientPalette::RepeatingGradientPalette(int min, int max, Color cmin, Color cmax, int num_cols,
                                                       Color inner_color) {
    this->min = min;
    this->max = max;
    this->cmin = cmin;
    this->cmax = cmax;
    this->num_cols = num_cols;
    this->inner_color = inner_color;
    generate_palette();
}

Color RepeatingGradientPalette::compute_color(int value) {
    if (value == INT_MAX) {
        return inner_color;
    }
    return colors[value + min];
}

void RepeatingGradientPalette::generate_palette() {
    this->colors = new Color[max - min + 1];
    for (int i = min; i <= max; i++) {
        unsigned char R = compute_component(i, cmin.R, cmax.R, num_cols);
        unsigned char G = compute_component(i, cmin.G, cmax.G, num_cols);
        unsigned char B = compute_component(i, cmin.B, cmax.B, num_cols);
        colors[i - min] = Color{R, G, B};
    }
}

unsigned char
RepeatingGradientPalette::compute_component(int value, unsigned char v1, unsigned char v2, int num_cols) {
    double normalized = double((value - min) % num_cols) / (num_cols - 1);
    return v1 + (unsigned char) (normalized * (v2 - v1));
}

bool RepeatingGradientPalette::is_iteration_dependent() {
    return true;
}

void RepeatingGradientPalette::recompute(Fractal * fractal) {
    this->max = fractal->get_maxiter();
    generate_palette();
}

RepeatingGradientPalette::~RepeatingGradientPalette() {
    delete[] colors;
}

RepeatingGradientPalette::RepeatingGradientPalette(int min, int max, Color cmin, Color cmax, int num_cols)
        : RepeatingGradientPalette(min, max, cmin, cmax, num_cols, Color(0, 0, 0)) {

}

