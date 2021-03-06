#include "Color.h"

Color::Color() {
    this->R = 0;
    this->G = 0;
    this->B = 0;
}

Color::Color(unsigned char R, unsigned char G, unsigned char B) {
    this->R = R;
    this->G = G;
    this->B = B;
}

bool operator==(const Color lhs, const Color rhs) {
    return lhs.R == rhs.R && lhs.B == rhs.B && lhs.G == rhs.G;
}