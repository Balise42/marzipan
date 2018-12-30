#include "ColoredPoint.h"

ColoredPoint::ColoredPoint(unsigned int x, unsigned int y) {
    this->x = x;
    this->y = y;
    this->color = Color();
}

ColoredPoint::ColoredPoint() {
    this->x = 0;
    this->y = 0;
    this->color = Color();
}
