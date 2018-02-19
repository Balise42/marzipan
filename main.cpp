#include "Canvas.h"
#include "GradientPalette.h"
#include "Mandelbrot.h"


int main() {

    auto canvas = new Canvas();
    Color black(0,0,0);
    Color white(255,255,255);
    auto palette = new GradientPalette(0,1,black, white);

    auto mandel = new Mandelbrot();
    mandel->render(canvas, palette);

    canvas->write("plop.bmp");

    delete canvas;

    return 0;
}