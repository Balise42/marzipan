
#include <climits>
#include "ContinuousMandelbrot.h"

#define R 1000

double ContinuousMandelbrot::compute_value(std::complex<double> c) {
    std::complex<double> z = 0 + 0i;
    for (int i = 0; i<maxiter; i++) {
        z = std::pow(z, 2) + c;
        if(abs(z) > R) {
            return i+1 - log(log(std::abs(z)))/log(2);
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