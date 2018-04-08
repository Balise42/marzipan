#include <numeric>
#include <climits>
#include <fractales/Mandelbrot.h>
#include "HistoPalette.h"

bool HistoPalette::is_iteration_dependent() {
    return true;
}

void HistoPalette::recompute(Fractal * fractal) {
    this->num_cols =  fractal->get_maxiter() / 2;
    RepeatingGradientPalette::recompute(fractal);
    this->histo = ((Mandelbrot *)fractal)->compute_histo();
    this->total = std::accumulate(histo.begin(), histo.end(), 0);
}

HistoPalette::HistoPalette(std::vector<int> histo, Color cmin, Color cmax, int num_cols, Color inner_color) : RepeatingGradientPalette(
        0, (int) histo.size(), cmin, cmax, num_cols, inner_color) {
    this->histo = histo;
    this->total = std::accumulate(histo.begin(), histo.end(), 0);
}

Color HistoPalette::compute_color(double value) {
    auto valuei = (int) value;
    if (valuei == INT_MAX) {
        return inner_color;
    }
    double percentile = 0.0;
    for (int i = 0; i<valuei; i++) {
        percentile += (double)histo[i] / (double)total;
    }
    return colors[int(percentile * (max - min + 1))];
}

HistoPalette::HistoPalette(std::vector<int> histo, Color cmin, Color cmax, int num_cols) : HistoPalette(histo, cmin, cmax, num_cols, Color(0,0,0)) {
}
