//
// Created by isa on 3/17/18.
//

#include <numeric>
#include <climits>
#include "HistoPalette.h"

bool HistoPalette::is_iteration_dependent() {
    return false;
}

HistoPalette::HistoPalette(std::vector<int> histo, Color cmin, Color cmax, int num_cols, Color inner_color) : RepeatingGradientPalette(
        0, (int) histo.size(), cmin, cmax, num_cols, inner_color) {
    this->histo = histo;
    this->total = std::accumulate(histo.begin(), histo.end(), 0);
}

Color HistoPalette::compute_color(int value) {
    if (value == INT_MAX) {
        return inner_color;
    }
    double percentile = 0.0;
    for (int i = 0; i<value; i++) {
        percentile += (double)histo[i] / (double)total;
    }
    return colors[int(percentile * (max - min + 1))];
}

HistoPalette::HistoPalette(std::vector<int> histo, Color cmin, Color cmax, int num_cols) : HistoPalette(histo, cmin, cmax, num_cols, Color(0,0,0)) {
}
