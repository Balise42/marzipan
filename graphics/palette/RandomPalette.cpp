#include <cstdlib>
#include "RandomPalette.h"
#include <ctime>
#include <climits>

RandomPalette::RandomPalette(int min, int max) : RandomPalette(min, max, Color(0,0,0)) {
}

RandomPalette::~RandomPalette() {
    delete colors;
};

Color RandomPalette::compute_color(int value) {
    if (value == INT_MAX) {
        return inner_color;
    }
    if (colors[value-min] == Color{0,0,0}) {
        colors[value - min] = Color((unsigned char) (std::rand() % 256), (unsigned char) (std::rand() % 256),
                                        (unsigned char) (std::rand() % 256));
    }
    return colors[value - min];
}

bool RandomPalette::is_iteration_dependent() {
    return false;
}

void RandomPalette::set_iteration_dependent(int iter) {
    //nop
}

RandomPalette::RandomPalette(int min, int max, Color inner_color) {
    srand(time(NULL));
    colors = new Color[max - min + 1];
    this->min = min;
    this->inner_color = inner_color;
}
