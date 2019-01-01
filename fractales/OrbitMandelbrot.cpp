#include "OrbitMandelbrot.h"
#include <cmath>
#include <climits>

void OrbitMandelbrot::set_orbit(double x, double y, double max_value) {
    this->orbitX = x;
    this->orbitY = y;

    double minDist = 0.0;
    //double minDist = squared_dist_to_orbit(std::complex<double>(-2.0, -1.0));
    double maxDist = squared_dist_to_orbit(std::complex<double>(-2.0, -1.0));

    maxDist = std::max(maxDist, squared_dist_to_orbit(std::complex<double>(-2.0, 1.0)));
    maxDist = std::max(maxDist, squared_dist_to_orbit(std::complex<double>(1.0, 1.0)));
    maxDist = std::max(maxDist, squared_dist_to_orbit(std::complex<double>(1.0, -1.0)));

    minDist = std::min(minDist, squared_dist_to_orbit(std::complex<double>(-2.0, 1.0)));
    minDist = std::min(minDist, squared_dist_to_orbit(std::complex<double>(1.0, 1.0)));
    minDist = std::min(minDist, squared_dist_to_orbit(std::complex<double>(1.0, -1.0)));

    maxDist = std::sqrt(maxDist);
    minDist = std::sqrt(minDist);

    this->factor = (max_value - minDist)/(maxDist - minDist);
    this->translation = minDist;

}

double OrbitMandelbrot::compute_value(std::complex<double> c) {
    double dist = INT_MAX;
    int i = 0;
    std::complex<double> z = 0 + 0i;
    while (std::norm(std::pow(z, 2) + c) < 4 && i < maxiter) {
        z = std::pow(z, 2) + c;
        dist = std::min(dist, squared_dist_to_orbit(z));
        i = i+1;
    }
    if (i == maxiter || dist == INT_MAX) {
        return INT_MAX;
    }
    dist  =  (std::sqrt(dist) - this->translation) * this->factor;

    return dist;
}

double OrbitMandelbrot::squared_dist_to_orbit(std::complex<double> z) {
    return std::pow(z.real() - orbitX, 2) + std::pow(z.imag() - orbitY, 2);
}
