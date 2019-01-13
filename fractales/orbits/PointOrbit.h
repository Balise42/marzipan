
#ifndef MARZIPAN_POINTORBIT_H
#define MARZIPAN_POINTORBIT_H


#include "Orbit.h"

class PointOrbit : public Orbit {
public:
    PointOrbit(double x, double y, double max_value);
    double getOrbitFastValue(std::complex<double> z) override;
    double getOrbitValue(double v) override;


private:
    double orbitX;
    double orbitY;
    double factor;
    double translation;

    double squared_dist_to_orbit(std::complex<double> complex);
};


#endif //MARZIPAN_POINTORBIT_H
