#include "gradient_palette.h"

gradient_palette::gradient_palette(int min, int max, color cmin, color cmax) {
    this->min = min;
    this->max = max;
    this->cmin = cmin;
    this->cmax = cmax;
}

color gradient_palette::compute_color(int value) {
    unsigned char R = compute_component(value, cmin.R, cmax.R);
    unsigned char G = compute_component(value, cmin.G, cmax.G);
    unsigned char B = compute_component(value, cmin.B, cmax.B);
    return {R, G, B};
}

gradient_palette::gradient_palette() {
    cmin = color(0,0,0);
    cmax = color(255,255,255);
}

unsigned char gradient_palette::compute_component(int value, unsigned char v1, unsigned char v2) {
    double normalized = (double(value) - min)/(max - min);
    return v1 + (unsigned char)(normalized * (v2-v1));
}

bool gradient_palette::is_iteration_dependent() {
    return true;
}

void gradient_palette::set_iteration_dependent(int iter) {
    this->max = iter;
}