#include "graphics/canvas.h"
#include "graphics/palette/gradient_palette.h"
#include "fractales/mandelbrot.h"


int main() {

    color black(0,0,0);
    color white(255,255,255);
    auto palette = new gradient_palette(0,1,black, white);

    auto mandel = new mandelbrot();
    canvas canvas = mandel->renderToCanvas(palette);

    canvas.write("plop.bmp");

    return 0;
}