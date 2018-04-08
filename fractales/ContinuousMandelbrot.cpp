
#include <climits>
#include "ContinuousMandelbrot.h"

#define R 1000

double ContinuousMandelbrot::compute_value(std::complex<double> c) {
    std::complex<double> z = 0 + 0i;
    for (int i = 0; i<maxiter; i++) {
        z = std::pow(z, 2) + c;
        if(abs(z) > R) {
            return i+1 - log(log(std::abs(z)))/log(2);
        }
    }
    return INT_MAX;
}

