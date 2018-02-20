#include "gtest/gtest.h"
#include "Mandelbrot.h"

TEST(MandelbrotTest, ScaleTest) {
    Mandelbrot *m = new Mandelbrot();
    std::complex<double> expected = 0 + 0*1i;
    ASSERT_NEAR(m->scale(600,150,900,300).real(), expected.real(), 1e-30);
    ASSERT_NEAR(m->scale(600,150,900,300).imag(), expected.imag(), 1e-30);

    expected = 0 + 1*1i;
    ASSERT_NEAR(m->scale(600,0,900,300).real(), expected.real(), 1e-30);
    ASSERT_NEAR(m->scale(600,0,900,300).imag(), expected.imag(), 1e-30);
}