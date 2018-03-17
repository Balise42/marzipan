//
// Created by isa on 2/26/18.
//

#include <climits>
#include "repeating_gradient_palette.h"
#include "gradient_palette.h"

repeating_gradient_palette::repeating_gradient_palette(int min, int max, color cmin, color cmax, int num_cols,
                                                       color inner_color) {
    this->min = min;
    this->max = max;
    this->cmin = cmin;
    this->cmax = cmax;
    this->num_cols = num_cols;
    this->inner_color = inner_color;
    generate_palette();
}

color repeating_gradient_palette::compute_color(int value) {
    if (value == INT_MAX) {
        return inner_color;
    }
    return colors[value + min];
}

void repeating_gradient_palette::generate_palette() {
    this->colors = new color[max - min + 1];
    for (int i = min; i <= max; i++) {
        unsigned char R = compute_component(i, cmin.R, cmax.R, num_cols);
        unsigned char G = compute_component(i, cmin.G, cmax.G, num_cols);
        unsigned char B = compute_component(i, cmin.B, cmax.B, num_cols);
        colors[i - min] = color{R, G, B};
    }
}

unsigned char
repeating_gradient_palette::compute_component(int value, unsigned char v1, unsigned char v2, int num_cols) {
    double normalized = double((value - min) % num_cols) / (num_cols - 1);
    return v1 + (unsigned char) (normalized * (v2 - v1));
}

bool repeating_gradient_palette::is_iteration_dependent() {
    return true;
}

void repeating_gradient_palette::set_iteration_dependent(int iter) {
    this->max = iter;
    generate_palette();
}

repeating_gradient_palette::~repeating_gradient_palette() {
    delete[] colors;
}

repeating_gradient_palette::repeating_gradient_palette(int min, int max, color cmin, color cmax, int num_cols)
        : repeating_gradient_palette(min, max, cmin, cmax, num_cols, color(0, 0, 0)) {

}

