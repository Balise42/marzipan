#ifndef MARZIPAN_CANVAS_H
#define MARZIPAN_CANVAS_H

#include "CImg.h"
#include "Color.h"

using namespace cimg_library;

class Canvas {
public:
    Canvas();

    Canvas(unsigned int width, unsigned int height);

    ~Canvas();

    void paint(unsigned int x, unsigned int y, Color c);

    Color readColor(unsigned int x, unsigned int y);

    void write(const char * filename);

private:
    CImg<unsigned char> *img;
};


#endif //MARZIPAN_CANVAS_H
