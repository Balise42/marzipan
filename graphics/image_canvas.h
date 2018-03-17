#ifndef MARZIPAN_IMAGE_CANVAS_H
#define MARZIPAN_IMAGE_CANVAS_H

#include "CImg.h"
#include "color.h"
#include "canvas.h"

using namespace cimg_library;

class image_canvas : public canvas {
public:
    image_canvas();

    image_canvas(unsigned int width, unsigned int height);

    ~image_canvas();

    void paint(unsigned int x, unsigned int y, color c) override;

    color read_color(unsigned int x, unsigned int y) override;


    void write();

    void write(const char * filename);


private:
    CImg<unsigned char> *img;
};


#endif //MARZIPAN_IMAGE_CANVAS_H
