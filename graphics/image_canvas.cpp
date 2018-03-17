#include "image_canvas.h"
#include <gflags/gflags.h>
#include <stdexcept>

DEFINE_string(output, "plop.bmp", "Image file to write");

using namespace cimg_library;

image_canvas::image_canvas() : image_canvas(900, 600) {
}

image_canvas::image_canvas(unsigned int width, unsigned int height) {
    img = new CImg<unsigned char>(width, height, 1, 3, 0);
    this->width = width;
    this->height = height;
}

image_canvas::~image_canvas() {
    delete img;
}

void image_canvas::paint(const unsigned int x, const unsigned int y, const color c) {
    (*img)(x, y, 0) = c.R;
    (*img)(x, y, 1) = c.G;
    (*img)(x, y, 2) = c.B;
}

color image_canvas::read_color(unsigned int x, unsigned int y) {
    return {(*img)(x, y, 0), (*img)(x, y, 1), (*img)(x, y, 2)};
}

void image_canvas::write() {
    write(FLAGS_output.c_str());
}

void image_canvas::write(const char *filename) {
    img->save_bmp(filename);
}

