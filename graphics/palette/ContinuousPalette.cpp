
#include <climits>
#include "ContinuousPalette.h"

ContinuousPalette::ContinuousPalette(int min, int max, std::vector<Color *> colors,
                                                   Color inner_color) {
    this->min = min;
    this->max = max;
    this->inner_color = inner_color;
    this->R = std::vector<unsigned char>(colors.size());
    this->G = std::vector<unsigned char>(colors.size());
    this->B = std::vector<unsigned char>(colors.size());

    for (int i = 0; i<colors.size(); i++) {
        this->R[i] = colors[i]->R;
        this->G[i] = colors[i]->G;
        this->B[i] = colors[i]->B;
    }
}

Color ContinuousPalette::compute_color(double value) {
    auto valuei = (int) value;
    if (valuei == INT_MAX) {
        return inner_color;
    }

    while (value > max) {
        value -= max;
    };

    unsigned char R = compute_component(value, this->R);
    unsigned char G = compute_component(value, this->G);
    unsigned char B = compute_component(value, this->B);


    return Color(R, G, B);
}

unsigned char ContinuousPalette::compute_component(double value, std::vector<unsigned char> v) {
    double normalized = (value - min) / (max - min);
    normalized = (std::pow(normalized - 0.5, 3) + 0.125)/0.250;
    unsigned char v1, v2;
    auto colorIndex = (int)((v.size()-1) * normalized);
    double normalizedColor = ((v.size()-1) * normalized - colorIndex);
    v1 = v[colorIndex];
    v2 = v[colorIndex + 1];

    unsigned char val = v1 + (unsigned char) ((normalizedColor) * (v2 - v1));
    return val;
}

bool ContinuousPalette::is_iteration_dependent() {
    return true;
}

void ContinuousPalette::recompute(Fractal * fractal) {
    this->max = fractal->get_maxiter();
}
