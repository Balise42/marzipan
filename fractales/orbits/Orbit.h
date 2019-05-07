
#ifndef MARZIPAN_ORBIT_H
#define MARZIPAN_ORBIT_H


#include <complex>
#include <protobuf/marzipanstate.pb.h>

class Orbit {
public:
    virtual double getOrbitFastValue(std::complex<double> z) = 0;
    virtual double getOrbitValue(double v) = 0;
    virtual OrbitProto * serialize() = 0;
protected:
    double max_value;
    double factor;
    double translation;
};


#endif //MARZIPAN_ORBIT_H
