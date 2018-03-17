#include <complex>
#include "julia.h"


image_canvas julia::renderToCanvas() {
    image_canvas c(width, height);
    for (unsigned int x = 0; x<width; x++) {
        for (unsigned int y = 0; y<height; y++) {
            int value = computeValue(scale(x, y));
            c.paint(x, y, pal->compute_color(value));
        }
    }
    return c;
}

int julia::computeValue(std::complex<double> z) {
    int i = 0;
    std::complex<double> c = -0.4 + 0.6i;
    while (std::norm(std::pow(z, 2) + c) < 4 && i < maxiter) {
        z = std::pow(z, 2) + c;
        i = i+1;
    }
    return i;
}

void julia::renderToFile() {
    image_canvas c = renderToCanvas();
    c.write();
}
