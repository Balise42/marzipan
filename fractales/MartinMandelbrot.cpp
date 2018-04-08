
#include "MartinMandelbrot.h"

void MartinMandelbrot::compute_seed(std::complex<double> s) {
    X = s;

    seed = std::vector<std::complex<double>>(maxiter);
    seed[0] = X;
    for (int i = 1; i<maxiter; i++) {
        seed[i] = std::pow(seed[i-1], 2) + X;
    }

    A = std::vector<std::complex<double>>(maxiter);
    B = std::vector<std::complex<double>>(maxiter);
    C = std::vector<std::complex<double>>(maxiter);

    A[0] = 1;
    B[0] = 0;
    C[0] = 0;

    std::complex<double> two(2,0);

    for (int i = 1; i<maxiter; i++) {
        A[i] = two*seed[i]*A[i-1] + 1.0;
        B[i] = two*seed[i]*B[i-1] + std::pow(A[i-1], 2);
        C[i] = two*seed[i]*C[i-1] + two*A[i-1]*B[i-1];
    }
}

double MartinMandelbrot::compute_value(std::complex<double> z) {
    std::complex<double> delta = z - X;
    if (std::norm(delta) != 0 && std::norm(std::pow(delta, 3)) * 1000 > std::norm(std::pow(delta,2))) {
        compute_seed(z);
        delta = 0;
    }
    for (int i = 0; i<maxiter; i++) {
        std::complex<double> diff = A[i] * delta + B[i] * std::pow(delta, 2) + C[i] * std::pow(delta, 3);
        if (std::norm(seed[i] + diff) >= 4) {
            return i;
        }
    }
    return INT_MAX;
}
