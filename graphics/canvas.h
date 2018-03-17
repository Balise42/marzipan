#ifndef MARZIPAN_CANVAS_H
#define MARZIPAN_CANVAS_H


#include "color.h"

class canvas {
public:
    virtual void paint(unsigned int x, unsigned int y, color c) = 0;

    virtual color read_color(unsigned int x, unsigned int y) = 0;

    unsigned int width, height;
};


#endif //MARZIPAN_CANVAS_H
