#include <complex>
#include "Mandelbrot.h"
#include "MpComplex.h"


double Mandelbrot::compute_value(MpComplex c) {
    int i = 0;
    MpComplex z(0, 0);
    MpComplex nextZ = z.square() + c;
    while (nextZ.norm() < 4 && i < maxiter) {
        z = nextZ + c;
        i = i+1;
        nextZ = z.square() + c;
    }
    if (i == maxiter) {
        i = INT_MAX;
    }
    return i;
}

std::vector<int> Mandelbrot::compute_histo() {
    std::vector<int> v(maxiter, 0);
    for (unsigned int x = 0; x<width; x++) {
        for (unsigned int y = 0; y < height; y++) {
            int value = (int) compute_value(scale(x, y));
            if (value != INT_MAX) {
                v[value] = v[value] + 1;
            }
        }
    }
    return v;
}

Fractal * Mandelbrot::clone() {
    return new Mandelbrot(*this);
}

FractalProto * Mandelbrot::serialize() {
    auto fp = Fractal::serialize();
    fp->set_allocated_mandelbrot(new MandelbrotFractalProto());
    return fp;
}

Mandelbrot * Mandelbrot::deserialize(FractalProto *fp) {
    auto mandel = new Mandelbrot(fp->width(), fp->height(), fp->left(), fp->right(), fp->top(), fp->bottom());
    mandel->set_maxiter(fp->maxiter());
}
