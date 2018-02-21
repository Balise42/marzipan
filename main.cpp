#include "graphics/canvas.h"
#include "graphics/palette/gradient_palette.h"
#include "fractales/mandelbrot.h"


int main() {

    color black(0,0,0);
    color white(255,255,255);
    auto palette = new gradient_palette(0,1,black, white);

    auto mandel = new mandelbrot(400,400,-1.4, -1.34, 0.03, -0.03);
    mandel->set_maxiter(400);
    canvas canvas = mandel->renderToCanvas(palette);

    canvas.write("plop.bmp");

    return 0;
}