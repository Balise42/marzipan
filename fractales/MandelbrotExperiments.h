
#ifndef MARZIPAN_MANDELBROTEXPERIMENTS_H
#define MARZIPAN_MANDELBROTEXPERIMENTS_H


#include "Fractal.h"

class MandelbrotExperiments : public Fractal {
    double compute_value(MpComplex c) override;
};


#endif //MARZIPAN_MANDELBROTEXPERIMENTS_H
