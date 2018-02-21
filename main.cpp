#include "graphics/canvas.h"
#include "graphics/palette/gradient_palette.h"
#include "fractales/mandelbrot.h"

color black(0,0,0);
color yellow(255,255,0);
color red(255,0,0);
color white(255,255,255);
color blue(0,0,255);
color green(0,255,0);
color pink(255,0,255);

int main() {


    auto palette = new gradient_palette(0,800,white, pink);

    auto mandel = new mandelbrot(800,800,-1.4, -1.3994, -0.0001, -0.0007);
    mandel->set_maxiter(800);
    canvas canvas = mandel->renderToCanvas(palette);

    canvas.write("plop.bmp");

    return 0;
}