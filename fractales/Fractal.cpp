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

MpComplex Fractal::scale(unsigned int x, unsigned int y) {
    mpfr::mpreal re = left + mpfr::mpreal(x)/mpfr::mpreal(width) * (right - left);
    mpfr::mpreal im = top + mpfr::mpreal(y)/mpfr::mpreal(height) * (bottom - top);
    return MpComplex(re, im);
}

void Fractal::zoom(unsigned int width, unsigned int height, int startx, int starty, int endx, int endy) {
    this->width = width;
    this->height = height;
    MpComplex topleft = scale(startx, starty);
    MpComplex bottomright = scale(endx, endy);
    left = topleft.real();
    top = topleft.imag();
    right = bottomright.real();
    bottom = bottomright.imag();
}

FractalProto * Fractal::serialize() {
    // TODO fix serialization (because right now i'm losing all my precision with mpfr - just serializing double instead!)
    auto fp = new FractalProto();
    fp->set_bottom(static_cast<double>(bottom));
    fp->set_height(height);
    fp->set_left(static_cast<double>(left));
    fp->set_right(static_cast<double>(right));
    fp->set_width(width);
    fp->set_top(static_cast<double>(top));
    fp->set_maxiter(maxiter);
    return fp;
}

/*void Fractal::deserialize(FractalProto *fp) {
    bottom = fp->bottom();
    height = fp->height();
    left = fp->left();
    right = fp->right();
    width = fp->width();
    height = fp->height();
    top = fp->top();
}*/