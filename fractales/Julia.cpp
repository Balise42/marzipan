#include <complex>
#include "Julia.h"

double Julia::compute_value(MpComplex z) {
    int i = 0;
    MpComplex c(-0.4, 0.6);
    while((z.square() + c).norm() < 4 && i < maxiter) {
        z = z.square() + c;
        i = i+1;
    }
    return i;
}
