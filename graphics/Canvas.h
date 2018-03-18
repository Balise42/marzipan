#ifndef MARZIPAN_CANVAS_H
#define MARZIPAN_CANVAS_H


#include "Color.h"

class Canvas {
public:
    virtual void paint(unsigned int x, unsigned int y, Color c) = 0;

    virtual Color read_color(unsigned int x, unsigned int y) = 0;

    unsigned int width, height;
};


#endif //MARZIPAN_CANVAS_H
