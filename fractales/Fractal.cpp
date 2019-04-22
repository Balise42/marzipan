#include "Fractal.h"
#include <gflags/gflags.h>
#include <protobuf/marzipanstate.pb.h>

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
    double re = left + double(x)/double(width) * (right - left);
    double im = top + double(y)/double(height) * (bottom - top);
    return re + im*1i;
}

void Fractal::zoom(unsigned int width, unsigned int height, int startx, int starty, int endx, int endy) {
    this->width = width;
    this->height = height;
    std::complex<double> topleft = scale(startx, starty);
    std::complex<double> bottomright = scale(endx, endy);
    left = topleft.real();
    top = topleft.imag();
    right = bottomright.real();
    bottom = bottomright.imag();
}

void Fractal::serialize(FractalProto * fp) {
    fp->set_bottom(bottom);
    fp->set_height(height);
    fp->set_left(left);
    fp->set_right(right);
    fp->set_width(width);
    fp->set_top(top);
}

void Fractal::deserialize(FractalProto *fp) {
    bottom = fp->bottom();
    height = fp->height();
    left = fp->left();
    right = fp->right();
    width = fp->width();
    height = fp->height();
    top = fp->top();
}
