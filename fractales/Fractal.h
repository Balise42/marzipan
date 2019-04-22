#ifndef MARZIPAN_FRACTALE_H
#define MARZIPAN_FRACTALE_H


#include <complex>
#undef Status
#include <protobuf/marzipanstate.pb.h>

class Fractal {

public:
    Fractal();
    Fractal(unsigned int width, unsigned int height);
    Fractal(unsigned int width, unsigned int height, double left, double right, double top, double bottom);
    virtual void zoom(unsigned int width, unsigned int height, int startx, int starty, int endx, int endy);
    std::complex<double> scale(unsigned int x, unsigned int y);
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
    virtual double compute_value(std::complex<double> z) = 0;

    unsigned int width = 900;
    unsigned int height = 600;

    void serialize(FractalProto * fp);
    void deserialize(FractalProto * fp);

protected:
    double bottom = -1;
    double left = -2;
    int maxiter = 100;
    double right = 1;
    double top = 1;

};


#endif //MARZIPAN_FRACTALE_H
