#ifndef MARZIPAN_FRACTALE_H
#define MARZIPAN_FRACTALE_H


#include <complex>

class Fractal {

public:
    Fractal();
    Fractal(unsigned int width, unsigned int height);
    Fractal(unsigned int width, unsigned int height, double left, double right, double top, double bottom);
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
    virtual int compute_value(std::complex<double> z) = 0;

    unsigned int width = 900;
    unsigned int height = 600;

protected:
    double bottom = -1;
    double left = -2;
    int maxiter = 100;
    double right = 1;
    double top = 1;

};


#endif //MARZIPAN_FRACTALE_H
