#include "canvas.h"
#include <gflags/gflags.h>

DEFINE_string(output, "plop.bmp", "Image file to write");

using namespace cimg_library;

canvas::canvas() : canvas(900, 600) {
}

canvas::canvas(unsigned int width, unsigned int height) {
    img = new CImg<unsigned char>(width, height, 1, 3, 0);
}

canvas::~canvas() {
    delete img;
}

void canvas::paint(const unsigned int x, const unsigned int y, const color c) {
    (*img)(x, y, 0) = c.R;
    (*img)(x, y, 1) = c.G;
    (*img)(x, y, 2) = c.B;
}

color canvas::read_color(unsigned int x, unsigned int y) {
    return {(*img)(x, y, 0), (*img)(x, y, 1), (*img)(x, y, 2)};
}

void canvas::write() {
    write(FLAGS_output.c_str());
}

void canvas::write(const char *filename) {
    img->save_bmp(filename);
}

