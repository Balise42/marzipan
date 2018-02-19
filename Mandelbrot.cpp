#include "Mandelbrot.h"


void Mandelbrot::render(Canvas * canvas, GradientPalette * palette) {
    for (unsigned int x = 0; x<canvas->width; x++) {
        for (unsigned int y = 0; y<canvas->height; y++) {
            double value = computeValue(scale(x, canvas->width), scale(y, canvas->height));
            canvas->paint(x, y, palette->computeColor(value));
        }
    }
}

double Mandelbrot::computeValue(double x, double y) {
    int i = 0;
    int maxiter = 100;

    double zr = x;
    double zi = y;
    while(zi*zi+zr+zr <= 4 && i < maxiter){
        double zrtmp = zr*zr-zi*zi + x;
        zi = 2*zr*zi + y;
        zr = zrtmp;
        i += 1;
    }

    if (i == maxiter) {
        return 0;
    }
    return 1;
}

double Mandelbrot::scale(unsigned int coord, unsigned int size) {
    return ((double)coord - (double)size/2)/(double)(size);
}
