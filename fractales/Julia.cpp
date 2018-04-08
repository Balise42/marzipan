#include <complex>
#include "Julia.h"

double Julia::compute_value(std::complex<double> z) {
    int i = 0;
    std::complex<double> c = -0.4 + 0.6i;
    while (std::norm(std::pow(z, 2) + c) < 4 && i < maxiter) {
        z = std::pow(z, 2) + c;
        i = i+1;
    }
    return i;
}
