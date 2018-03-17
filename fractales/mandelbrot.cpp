#include <complex>
#include "mandelbrot.h"


image_canvas mandelbrot::renderToCanvas() {
    image_canvas c(width, height);
    for (unsigned int x = 0; x<width; x++) {
        for (unsigned int y = 0; y<height; y++) {
            int value = compute_value(scale(x, y));
            c.paint(x, y, pal->compute_color(value));
        }
    }
    return c;
}

int mandelbrot::compute_value(std::complex<double> c) {
    int i = 0;
    std::complex<double> z = 0 + 0i;
    while (std::norm(std::pow(z, 2) + c) < 4 && i < maxiter) {
        z = std::pow(z, 2) + c;
        i = i+1;
    }
    if (i == maxiter) {
        i = INT_MAX;
    }
    return i;
}

void mandelbrot::renderToFile() {
    image_canvas c = renderToCanvas();
    c.write();
}

std::vector<int> mandelbrot::compute_histo() {
    std::vector<int> v(maxiter, 0);
    for (unsigned int x = 0; x<width; x++) {
        for (unsigned int y = 0; y < height; y++) {
            int value = compute_value(scale(x, y));
            if (value != INT_MAX) {
                v[value] = v[value] + 1;
            }
        }
    }
    return v;
}
