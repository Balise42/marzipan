
#ifndef MARZIPAN_LINEORBIT_H
#define MARZIPAN_LINEORBIT_H


#include "Orbit.h"

class LineOrbit : public Orbit {
public:
    LineOrbit(double a, double b, double c, double value);
    double getOrbitFastValue(std::complex<double> z) override;

    double getOrbitValue(double v) override;

private:
    //line is given by ax + by + c = 0
    double a, b, c;
    double sqrtab;
    double factor;
    double translation;

};


#endif //MARZIPAN_LINEORBIT_H
