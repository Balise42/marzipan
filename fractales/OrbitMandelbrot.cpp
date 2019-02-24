#include "OrbitMandelbrot.h"
#include <climits>

double OrbitMandelbrot::compute_value(std::complex<double> c) {
    double dist = INT_MAX;
    int i = 0;
    std::complex<double> z = 0 + 0i;
    while (std::norm(std::pow(z, 2) + c) < 4 && i < maxiter) {
        z = std::pow(z, 2) + c;
        for (auto orbit : orbits) {
            dist = std::min(dist, orbit->getOrbitValue(orbit->getOrbitFastValue(z)));
        }
        i = i+1;
    }
    if (i == maxiter || dist == INT_MAX) {
        return INT_MAX;
    }
    //dist  = orbit->getOrbitValue(dist);

    return dist;
}

OrbitMandelbrot *OrbitMandelbrot::clone() {
    auto * f = new OrbitMandelbrot(*this);
    return f;
}
