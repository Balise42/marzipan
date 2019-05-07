
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
    this->max_value = max_value;

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

OrbitProto * PointOrbit::serialize() {
    auto ret = new OrbitProto();
    ret->set_max_value(max_value);
    auto pop = new PointOrbitProto();
    pop->set_orbitx(orbitX);
    pop->set_orbity(orbitY);
    ret->set_allocated_pointorbit(pop);
    return ret;
}

PointOrbit * PointOrbit::deserialize(OrbitProto *op) {
    return new PointOrbit(op->pointorbit().orbitx(), op->pointorbit().orbity(), op->max_value());
}
