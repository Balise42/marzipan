
#include <climits>
#include "MandelbrotExperiments.h"

double MandelbrotExperiments::compute_value(std::complex<double> c) {
    double R = 20.0;

    std::complex<double> z = 0 + 0i;
    for (int i = 0; i<maxiter; i++) {
        z = std::pow(z, 2) + c;
        if(abs(z) > R) {
            double err = log(log(std::abs(z)))/log(2);
            double it = i + 1 - err;
            if (err < 0) {
                return INT_MAX;
            }
            if (it < 0) {
                return INT_MAX;
            }
            return it; // - log(log(std::abs(z)))/log(2);
        }
    }
    return INT_MAX;
}
