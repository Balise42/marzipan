#include "GradientPalette.h"

GradientPalette::GradientPalette(double min, double max, Color cmin, Color cmax) {
    this->min = min;
    this->max = max;
    this->cmin = cmin;
    this->cmax = cmax;
}

Color GradientPalette::computeColor(double value) {
    unsigned char R = computeComponent(value, cmin.R, cmax.R);
    unsigned char G = computeComponent(value, cmin.G, cmax.G);
    unsigned char B = computeComponent(value, cmin.B, cmax.B);
    return {R, G, B};
}

GradientPalette::GradientPalette() {
    cmin = Color(0,0,0);
    cmax = Color(255,255,255);
}

unsigned char GradientPalette::computeComponent(double value, unsigned char v1, unsigned char v2) {
    double normalized = (value - min)/(max - min);
    if (normalized < 0.0001) {
        return 0;
    }
    return 255;
    /*if (v1 < v2) {
        return (unsigned char)(normalized * v1/(v2-v1));
    } else {
        return (unsigned char)(normalized * v2/(v1-v2));
    }*/
}
