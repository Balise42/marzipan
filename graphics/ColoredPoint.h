#ifndef MARZIPAN_COLOREDPOINT_H
#define MARZIPAN_COLOREDPOINT_H


#include "Color.h"

class ColoredPoint {
public:
    ColoredPoint();
    ColoredPoint(unsigned int x, unsigned int y);

    unsigned int x;
    unsigned int y;
    Color color;

};


#endif //MARZIPAN_COLOREDPOINT_H
