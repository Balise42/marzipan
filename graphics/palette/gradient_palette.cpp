#include "gradient_palette.h"

gradient_palette::gradient_palette(double min, double max, color cmin, color cmax) {
    this->min = min;
    this->max = max;
    this->cmin = cmin;
    this->cmax = cmax;
}

color gradient_palette::compute_color(double value) {
    unsigned char R = compute_component(value, cmin.R, cmax.R);
    unsigned char G = compute_component(value, cmin.G, cmax.G);
    unsigned char B = compute_component(value, cmin.B, cmax.B);
    return {R, G, B};
}

gradient_palette::gradient_palette() {
    cmin = color(0,0,0);
    cmax = color(255,255,255);
}

unsigned char gradient_palette::compute_component(double value, unsigned char v1, unsigned char v2) {
    double normalized = (value - min)/(max - min);
    return v1 + (unsigned char)(normalized * (v2-v1));
}
