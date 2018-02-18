#include "Canvas.h"

using namespace cimg_library;

Canvas::Canvas() : Canvas(800, 600) {
}

Canvas::Canvas(unsigned int width, unsigned int height) {
    img = new CImg<unsigned char>(width, height, 1, 3, 0);
}

Canvas::~Canvas() {
    delete img;
}

void Canvas::paint(const unsigned int x, const unsigned int y, const Color c) {
    (*img)(x, y, 0) = c.R;
    (*img)(x, y, 1) = c.G;
    (*img)(x, y, 2) = c.B;
}

Color Canvas::readColor(unsigned int x, unsigned int y) {
    return {(*img)(x, y, 0), (*img)(x, y, 1), (*img)(x, y, 2)};
}

void Canvas::write(const char *filename) {
    img->save_bmp(filename);
}

