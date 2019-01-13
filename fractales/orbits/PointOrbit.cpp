
#include "PointOrbit.h"

double PointOrbit::getOrbitFastValue(std::complex<double> z) {
    return squared_dist_to_orbit(z);
}

double PointOrbit::getOrbitValue(double v) {
    return (std::sqrt(v) - this->translation) * this->factor;
}

PointOrbit::PointOrbit(double x, double y, double max_value) {
    this->orbitX = x;
    this->orbitY = y;

    double minDist = 0.0;
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

double PointOrbit::squared_dist_to_orbit(std::complex<double> z) {
    return std::pow(z.real() - orbitX, 2) + std::pow(z.imag() - orbitY, 2);
}
