#ifndef MARZIPAN_MARTINMANDELBROT_H
#define MARZIPAN_MARTINMANDELBROT_H

#include "Mandelbrot.h"

class MartinMandelbrot : public Mandelbrot {

public:
    MartinMandelbrot() : Mandelbrot() {
        compute_seed(std::complex<double>((left + right)/2, (top+bottom)/2));
    }

    MartinMandelbrot(unsigned int width, unsigned int height) : Mandelbrot(width, height) {
        compute_seed(std::complex<double>((left + right)/2, (top+bottom)/2));
    }

    MartinMandelbrot(unsigned int width, unsigned int height, double left, double right, double top, double bottom)
            : Mandelbrot(width, height, left, right, top, bottom) {
        compute_seed(std::complex<double>((left + right)/2, (top+bottom)/2));
    }

    double compute_value(std::complex<double> z) override;

    void zoom(unsigned int width, unsigned int height, int startx, int starty, int endx, int endy) {
        Fractal::zoom(width, height, startx, starty, endx, endy);
        compute_seed(std::complex<double>((left + right)/2, (top+bottom)/2));
    }

private:
    std::complex<double> X;
    std::vector<std::complex<double>> seed;
    std::vector<std::complex<double>> A;
    std::vector<std::complex<double>> B;
    std::vector<std::complex<double>> C;
    void compute_seed(std::complex<double> s);
};


#endif //MARZIPAN_MARTINMANDELBROT_H
