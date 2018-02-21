#include <complex>
#include "mandelbrot.h"

mandelbrot::mandelbrot() : mandelbrot(900, 600) {
}

mandelbrot::mandelbrot(unsigned int width, unsigned int height) {
    this->width = width;
    this->height = height;
}

canvas mandelbrot::renderToCanvas(gradient_palette * palette) {
    canvas c(width, height);
    for (unsigned int x = 0; x<width; x++) {
        for (unsigned int y = 0; y<height; y++) {
            double value = computeValue(scale(x, y));
            c.paint(x, y, palette->compute_color(value));
        }
    }
    return c;
}

double mandelbrot::computeValue(std::complex<double> c) {
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

std::complex<double> mandelbrot::scale(unsigned int x, unsigned int y) {
    double re = 3*double(x)/double(width) - 2;
    double im = -(2*double(y)/double(height) - 1);
    return re + im*1i;
}
