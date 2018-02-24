#include <cstdlib>
#include "random_palette.h"
#include <ctime>

random_palette::random_palette(int min, int max) {
    srand(time(NULL));
    colors = new color[max - min + 1];
    this->min = min;
}

random_palette::~random_palette() {
    delete colors;
};

color random_palette::compute_color(int value) {
    if (colors[value-min] == color{0,0,0}) {
        colors[value - min] = color((unsigned char) (std::rand() % 256), (unsigned char) (std::rand() % 256),
                                        (unsigned char) (std::rand() % 256));
    }
    return colors[value - min];
}
