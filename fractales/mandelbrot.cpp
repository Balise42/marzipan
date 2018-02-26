#include <complex>
#include "mandelbrot.h"


canvas mandelbrot::renderToCanvas() {
    canvas c(width, height);
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
    return i;
}

void mandelbrot::renderToFile() {
    canvas c = renderToCanvas();
    c.write();
}
