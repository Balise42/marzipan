#ifndef MARZIPAN_MPCOMPLEX_H
#define MARZIPAN_MPCOMPLEX_H

#include <mpreal.h>
#include <complex>

class MpComplex {
private:
    mpfr::mpreal r, im;

public:
    MpComplex(mpfr::mpreal r, mpfr::mpreal im);
    MpComplex square();
    mpfr::mpreal norm();

    MpComplex& operator+=(const MpComplex& rhs) {
        r += rhs.r;
        im += rhs.im;
        return *this;
    }

    friend MpComplex operator+(MpComplex lhx, const MpComplex& rhs);

    // TODO remove this by actually implementing properly stuff everywhere instead of relying on conversions for backward compatibility
    std::complex<double> toComplex();

    mpfr::mpreal real();

    mpfr::mpreal imag();

    mpfr::mpreal abs();
};


#endif //MARZIPAN_MPCOMPLEX_H
