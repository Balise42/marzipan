#include <complex>
#include "Mandelbrot.h"


void Mandelbrot::render(Canvas * canvas, GradientPalette * palette) {
    for (unsigned int x = 0; x<canvas->width; x++) {
        for (unsigned int y = 0; y<canvas->height; y++) {
            double value = computeValue(scale(x, y, canvas->width, canvas->height));
            canvas->paint(x, y, palette->computeColor(value));
        }
    }
}

double Mandelbrot::computeValue(std::complex<double> z) {
    /*int i = 0;
    int maxiter = 100;

    double zr = x;
    double zi = y;
    while(zi*zi+zr+zr <= 4 && i < maxiter){
        double zrtmp = zr*zr-zi*zi + x;
        zi = 2*zr*zi + y;
        zr = zrtmp;
        i += 1;
    }

    if (i == maxiter) {
        return 0;
    }*/
    return 1;
}

std::complex<double> Mandelbrot::scale(unsigned int x, unsigned int y, unsigned int sizex, unsigned int sizey) {
    double re = 3*double(x)/double(sizex) - 2;
    double im = -(2*double(y)/double(sizey) - 1);
    return re + im*1i;
}
