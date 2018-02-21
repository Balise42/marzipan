#include <complex>
#include "mandelbrot.h"

mandelbrot::mandelbrot() : mandelbrot(900, 600) {
}

mandelbrot::mandelbrot(unsigned int width, unsigned int height) : mandelbrot(width, height, -2, 1, 1, -1) {

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
    std::complex<double> z = 0 + 0i;
    while (std::norm(std::pow(z, 2) + c) < 4 && i < maxiter) {
        z = std::pow(z, 2) + c;
        i = i+1;
    }

    return i;
}

std::complex<double> mandelbrot::scale(unsigned int x, unsigned int y) {
    double re = (right - left)*double(x)/double(width) + left;
    double im = -((top - bottom)*double(y)/double(height) + bottom);
    return re + im*1i;
}

mandelbrot::mandelbrot(unsigned int width, unsigned int height, double left, double right, double top, double bottom) {
    this->width = width;
    this->height = height;
    this->left = left;
    this->right = right;
    this->top = top;
    this->bottom = bottom;
}
