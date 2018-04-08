#include <complex>
#include "Mandelbrot.h"


double Mandelbrot::compute_value(std::complex<double> c) {
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

std::vector<int> Mandelbrot::compute_histo() {
    std::vector<int> v(maxiter, 0);
    for (unsigned int x = 0; x<width; x++) {
        for (unsigned int y = 0; y < height; y++) {
            int value = (int) compute_value(scale(x, y));
            if (value != INT_MAX) {
                v[value] = v[value] + 1;
            }
        }
    }
    return v;
}