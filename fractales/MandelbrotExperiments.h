
#ifndef MARZIPAN_MANDELBROTEXPERIMENTS_H
#define MARZIPAN_MANDELBROTEXPERIMENTS_H


#include "Fractal.h"

class MandelbrotExperiments : public Fractal {
    double compute_value(std::complex<double> c) override;
};


#endif //MARZIPAN_MANDELBROTEXPERIMENTS_H
