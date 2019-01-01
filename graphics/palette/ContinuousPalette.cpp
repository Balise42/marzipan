
#include <climits>
#include "ContinuousPalette.h"

ContinuousPalette::ContinuousPalette(int min, int max, Color cmin, Color cmax,
                                                   Color inner_color, int num_cols) {
    this->min = min;
    this->max = max;
    this->cmin = cmin;
    this->cmax = cmax;
    this->inner_color = inner_color;
    this->num_cols = num_cols;
}

Color ContinuousPalette::compute_color(double value) {
    auto valuei = (int) value;
    if (valuei == INT_MAX) {
        return inner_color;
    }

    unsigned char R = compute_component(value, cmin.R, cmax.R);
    unsigned char G = compute_component(value, cmin.G, cmax.G);
    unsigned char B = compute_component(value, cmin.B, cmax.B);


    return Color(R, G, B);
}

unsigned char ContinuousPalette::compute_component(double value, unsigned char v1, unsigned char v2) {
    double normalized = (value - min) / (max - min);
    normalized = (std::pow(normalized - 0.5, 3) + 0.125)/0.250;
    unsigned char val = v1 + (unsigned char) (normalized * (v2 - v1));
    return val;
}

bool ContinuousPalette::is_iteration_dependent() {
    return true;
}

void ContinuousPalette::recompute(Fractal * fractal) {
    this->max = fractal->get_maxiter();
}
