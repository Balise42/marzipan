//
// Created by isa on 2/24/18.
//

#ifndef MARZIPAN_FRACTALE_H
#define MARZIPAN_FRACTALE_H


#include <complex>

class fractal {

public:
    fractal();
    fractal(unsigned int width, unsigned int height);
    fractal(unsigned int width, unsigned int height, double left, double right, double top, double bottom);
    void zoom(unsigned int width, unsigned int height, int startx, int starty, int endx, int endy);
    std::complex<double> scale(unsigned int x, unsigned int y);
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

protected:
    double bottom = -1;
    unsigned int height = 600;
    double left = -2;
    int maxiter = 100;
    double right = 1;
    double top = 1;
    unsigned int width = 900;

};


#endif //MARZIPAN_FRACTALE_H
