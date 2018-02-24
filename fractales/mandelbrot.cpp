#include <complex>
#include "mandelbrot.h"

#include <gflags/gflags.h>

DEFINE_uint32(width, 900, "Width of the generated image");
DEFINE_uint32(height, 600, "Height of the generated image");
DEFINE_double(left, -2, "Left-most coordinate");
DEFINE_double(right, 1, "Right-most coordinate");
DEFINE_double(top, 1, "Top-most coordinate");
DEFINE_double(bottom, -1, "Bottom-most coordinate");
DEFINE_uint32(iter, 100, "Number of iterations");

mandelbrot::mandelbrot() {
    this->width = FLAGS_width;
    this->height = FLAGS_height;
    this->left = FLAGS_left;
    this->right = FLAGS_right;
    this->top = FLAGS_top;
    this->bottom = FLAGS_bottom;
    this->maxiter = FLAGS_iter;
}

canvas mandelbrot::renderToCanvas(palette * palette) {
    canvas c(width, height);
    for (unsigned int x = 0; x<width; x++) {
        for (unsigned int y = 0; y<height; y++) {
            int value = computeValue(scale(x, y));
            c.paint(x, y, palette->compute_color(value));
        }
    }
    return c;
}

int mandelbrot::computeValue(std::complex<double> c) {
    int i = 0;
    std::complex<double> z = 0 + 0i;
    while (std::norm(std::pow(z, 2) + c) < 4 && i < maxiter) {
        z = std::pow(z, 2) + c;
        i = i+1;
    }

    return i;
}

std::complex<double> mandelbrot::scale(unsigned int x, unsigned int y) {
    double re = (right - left)*double(x)/double(width) + left;
    double im = -((top - bottom)*double(y)/double(height) + bottom);
    return re + im*1i;
}

mandelbrot::mandelbrot(unsigned int width, unsigned int height) : mandelbrot() {
    this->width = width;
    this->height = height;
}

mandelbrot::mandelbrot(unsigned int width, unsigned int height, double left, double right, double top, double bottom) : mandelbrot(width, height){
    this->left = left;
    this->right = right;
    this->top = top;
    this->bottom = bottom;
}
