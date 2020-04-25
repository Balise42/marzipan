
#include <climits>
#include "ContinuousMandelbrot.h"

#define R 1000

double ContinuousMandelbrot::compute_value(MpComplex c) {
    MpComplex z(0, 0);
    for (int i = 0; i<maxiter; i++) {
        z = z.square() + c;
        mpfr::mpreal absz = z.abs();
        if(absz > R) {
            return static_cast<double>(i + 1 - log(log(absz)) / log(2));
        }
    }
    return INT_MAX;
}

Fractal *ContinuousMandelbrot::clone() {
    return new ContinuousMandelbrot(*this);
}

FractalProto * ContinuousMandelbrot::serialize() {
    auto fp = Fractal::serialize();
    fp->set_allocated_continuous(new ContinuousFractalProto());
    return fp;
}

ContinuousMandelbrot * ContinuousMandelbrot::deserialize(FractalProto *fp) {
    auto mandel = new ContinuousMandelbrot(fp->width(), fp->height(), fp->left(), fp->right(), fp->top(), fp->bottom());
    mandel->set_maxiter(fp->maxiter());
}