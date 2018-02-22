#ifndef MARZIPAN_CANVAS_H
#define MARZIPAN_CANVAS_H

#include "CImg.h"
#include "color.h"

using namespace cimg_library;

class canvas {
public:
    canvas();

    canvas(unsigned int width, unsigned int height);

    ~canvas();

    void paint(unsigned int x, unsigned int y, color c);

    color read_color(unsigned int x, unsigned int y);

    void write();

private:
    CImg<unsigned char> *img;
};


#endif //MARZIPAN_CANVAS_H
