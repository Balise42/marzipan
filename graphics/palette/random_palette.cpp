#include <cstdlib>
#include "random_palette.h"
#include <ctime>
#include <climits>

random_palette::random_palette(int min, int max) : random_palette(min, max, color(0,0,0)) {
}

random_palette::~random_palette() {
    delete colors;
};

color random_palette::compute_color(int value) {
    if (value == INT_MAX) {
        return inner_color;
    }
    if (colors[value-min] == color{0,0,0}) {
        colors[value - min] = color((unsigned char) (std::rand() % 256), (unsigned char) (std::rand() % 256),
                                        (unsigned char) (std::rand() % 256));
    }
    return colors[value - min];
}

bool random_palette::is_iteration_dependent() {
    return false;
}

void random_palette::set_iteration_dependent(int iter) {
    //nop
}

random_palette::random_palette(int min, int max, color inner_color) {
    srand(time(NULL));
    colors = new color[max - min + 1];
    this->min = min;
    this->inner_color = inner_color;
}
