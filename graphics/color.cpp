#include "color.h"

color::color() {
    this->R = 0;
    this->G = 0;
    this->B = 0;
}

color::color(unsigned char R, unsigned char G, unsigned char B) {
    this->R = R;
    this->G = G;
    this->B = B;
}

bool operator==(const color lhs, const color rhs) {
    return lhs.R == rhs.R && lhs.B == rhs.B && lhs.G == rhs.G;
}