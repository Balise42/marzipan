#ifndef MARZIPAN_IMAGE_CANVAS_H
#define MARZIPAN_IMAGE_CANVAS_H

#include "CImg.h"
#include "Color.h"
#include "Canvas.h"

using namespace cimg_library;

class ImageCanvas : public Canvas {
public:
    ImageCanvas();

    ImageCanvas(unsigned int width, unsigned int height);

    ~ImageCanvas();

    void paint(unsigned int x, unsigned int y, Color c) override;

    Color read_color(unsigned int x, unsigned int y) override;


    void write();

    void write(const char * filename);


private:
    CImg<unsigned char> *img;
};


#endif //MARZIPAN_IMAGE_CANVAS_H
