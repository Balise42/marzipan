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

double Mandelbrot::computeValue(std::complex<double> c) {
    int i = 0;
    int maxiter = 100;
    std::complex<double> z = 0 + 0i;
    while (std::norm(std::pow(z, 2) + c) < 4 && i < maxiter) {
        z = std::pow(z, 2) + c;
        i = i+1;
    }

    if (i == maxiter) {
        return 0;
    }
    return 1;
}

std::complex<double> Mandelbrot::scale(unsigned int x, unsigned int y, unsigned int sizex, unsigned int sizey) {
    double re = 3*double(x)/double(sizex) - 2;
    double im = -(2*double(y)/double(sizey) - 1);
    return re + im*1i;
}
