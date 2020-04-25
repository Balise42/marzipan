
#include "MpComplex.h"

MpComplex MpComplex::square() {
    mpfr::mpreal newR = r*r - im*im;
    mpfr::mpreal newIm = 2*r*im;
    return MpComplex(newR, newIm);
}

mpfr::mpreal MpComplex::norm() {
    return r*r + im*im;
}

MpComplex::MpComplex(mpfr::mpreal r, mpfr::mpreal im) {
    this->r = r;
    this->im = im;
}

std::complex<double> MpComplex::toComplex() {
    return std::complex<double>(static_cast<double>(r), static_cast<double>(im));
}

mpfr::mpreal MpComplex::real() {
    return r;
}

mpfr::mpreal MpComplex::imag() {
    return im;
}

mpfr::mpreal MpComplex::abs() {
    return mpfr::sqrt(norm());
}

MpComplex operator+(MpComplex lhs, const MpComplex &rhs) {
    return MpComplex(lhs.r + rhs.r, lhs.im + rhs.im);
}
