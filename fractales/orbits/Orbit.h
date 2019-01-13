
#ifndef MARZIPAN_ORBIT_H
#define MARZIPAN_ORBIT_H


#include <complex>

class Orbit {
public:
    virtual double getOrbitFastValue(std::complex<double> z) = 0;
    virtual double getOrbitValue(double v) = 0;
};


#endif //MARZIPAN_ORBIT_H
