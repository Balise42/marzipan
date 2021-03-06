#ifndef MARZIPAN_FRACTALE_H
#define MARZIPAN_FRACTALE_H


#include <complex>
#undef Status
#include <protobuf/marzipanstate.pb.h>
#include "MpComplex.h"

class Fractal {

public:
    Fractal();
    Fractal(unsigned int width, unsigned int height);
    Fractal(unsigned int width, unsigned int height, double left, double right, double top, double bottom);
    virtual void zoom(unsigned int width, unsigned int height, int startx, int starty, int endx, int endy);
    MpComplex scale(unsigned int x, unsigned int y);
    virtual Fractal * clone() = 0;
    void set_width(unsigned int width) {
        this->width = width;
    }
    void set_height(unsigned int height) {
        this->height = height;
    }
    void set_maxiter(int iter) {
        this->maxiter = iter;
    }
    int get_maxiter() {
        return maxiter;
    }
    virtual double compute_value(MpComplex z) = 0;

    unsigned int width = 900;
    unsigned int height = 600;

    virtual FractalProto * serialize();

protected:
    mpfr::mpreal bottom = -1;
    mpfr::mpreal left = -2;
    int maxiter = 100;
    mpfr::mpreal right = 1;
    mpfr::mpreal top = 1;

};


#endif //MARZIPAN_FRACTALE_H
