//
// Created by isa on 3/17/18.
//

#include <numeric>
#include <climits>
#include "histo_palette.h"

bool histo_palette::is_iteration_dependent() {
    return false;
}

histo_palette::histo_palette(std::vector<int> histo, color cmin, color cmax, int num_cols, color inner_color) : repeating_gradient_palette(
        0, (int) histo.size(), cmin, cmax, num_cols, inner_color) {
    this->histo = histo;
    this->total = std::accumulate(histo.begin(), histo.end(), 0);
}

color histo_palette::compute_color(int value) {
    if (value == INT_MAX) {
        return inner_color;
    }
    double percentile = 0.0;
    for (int i = 0; i<value; i++) {
        percentile += (double)histo[i] / (double)total;
    }
    return colors[int(percentile * (max - min + 1))];
}

histo_palette::histo_palette(std::vector<int> histo, color cmin, color cmax, int num_cols) : histo_palette(histo, cmin, cmax, num_cols, color(0,0,0)) {
}
