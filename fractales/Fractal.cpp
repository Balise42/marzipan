#include "Fractal.h"
#include <gflags/gflags.h>

DEFINE_uint32(width, 900, "Width of the generated image");
DEFINE_uint32(height, 600, "Height of the generated image");
DEFINE_double(left, -2, "Left-most coordinate");
DEFINE_double(right, 1, "Right-most coordinate");
DEFINE_double(top, 1, "Top-most coordinate");
DEFINE_double(bottom, -1, "Bottom-most coordinate");
DEFINE_uint32(iter, 100, "Number of iterations");

Fractal::Fractal(unsigned int width, unsigned int height) : Fractal() {
    this->width = width;
    this->height = height;
}

Fractal::Fractal(unsigned int width, unsigned int height, double left, double right, double top, double bottom) : Fractal(width, height){
    this->left = left;
    this->right = right;
    this->top = top;
    this->bottom = bottom;
}

Fractal::Fractal() {
    this->width = FLAGS_width;
    this->height = FLAGS_height;
    this->left = FLAGS_left;
    this->right = FLAGS_right;
    this->top = FLAGS_top;
    this->bottom = FLAGS_bottom;
    this->maxiter = FLAGS_iter;
}

std::complex<double> Fractal::scale(unsigned int x, unsigned int y) {
    double re = (right - left)*double(x)/double(width) + left;
    double im = -((top - bottom)*double(y)/double(height) + bottom);
    return re + im*1i;
}

void Fractal::zoom(unsigned int width, unsigned int height, int startx, int starty, int endx, int endy) {
    this->width = width;
    this->height = height;
    std::complex<double> topleft = scale(startx, endy);
    std::complex<double> bottomright = scale(endx, starty);
    left = topleft.real();
    top = topleft.imag();
    right = bottomright.real();
    bottom = bottomright.imag();
    this->width = 900;
    this->height = 600;
}