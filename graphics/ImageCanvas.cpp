#include "ImageCanvas.h"
#include <gflags/gflags.h>
#include <stdexcept>

DEFINE_string(output, "plop.bmp", "Image file to write");

using namespace cimg_library;

ImageCanvas::ImageCanvas() : ImageCanvas(900, 600) {
}

ImageCanvas::ImageCanvas(unsigned int width, unsigned int height) {
    img = new CImg<unsigned char>(width, height, 1, 3, 0);
    this->width = width;
    this->height = height;
}

ImageCanvas::~ImageCanvas() {
    delete img;
}

void ImageCanvas::paint(const unsigned int x, const unsigned int y, const Color c) {
    (*img)(x, y, 0) = c.R;
    (*img)(x, y, 1) = c.G;
    (*img)(x, y, 2) = c.B;
}

Color ImageCanvas::read_color(unsigned int x, unsigned int y) {
    return {(*img)(x, y, 0), (*img)(x, y, 1), (*img)(x, y, 2)};
}

void ImageCanvas::write() {
    write(FLAGS_output.c_str());
}

void ImageCanvas::write(const char *filename) {
    img->save_bmp(filename);
}

