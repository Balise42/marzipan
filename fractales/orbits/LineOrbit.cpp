
#include "LineOrbit.h"

double LineOrbit::getOrbitFastValue(std::complex<double> z) {
    return std::pow(a*z.real() + b * z.imag() + c, 2);
}

double LineOrbit::getOrbitValue(double v) {
    return (std::sqrt(v) / sqrtab - this->translation) * this->factor;
}

LineOrbit::LineOrbit(double a, double b, double c, double max_value) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->sqrtab = std::sqrt(a*a + b*b);

    double minDist = 0.0;
    double maxDist = getOrbitFastValue(std::complex<double>(-2.0, -1.0));

    maxDist = std::max(maxDist, getOrbitFastValue(std::complex<double>(-2.0, 1.0)));
    maxDist = std::max(maxDist, getOrbitFastValue(std::complex<double>(1.0, 1.0)));
    maxDist = std::max(maxDist, getOrbitFastValue(std::complex<double>(1.0, -1.0)));

    minDist = std::min(minDist, getOrbitFastValue(std::complex<double>(-2.0, 1.0)));
    minDist = std::min(minDist, getOrbitFastValue(std::complex<double>(1.0, 1.0)));
    minDist = std::min(minDist, getOrbitFastValue(std::complex<double>(1.0, -1.0)));

    maxDist = std::sqrt(maxDist)/sqrtab;
    minDist = std::sqrt(minDist)/sqrtab;

    this->factor = (max_value - minDist)/(maxDist - minDist);
    this->translation = minDist;
}
