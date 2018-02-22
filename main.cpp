#include <gflags/gflags.h>
#include "graphics/canvas.h"
#include "graphics/palette/gradient_palette.h"
#include "fractales/mandelbrot.h"
#include "graphics/palette/random_palette.h"

color black(0,0,0);
color yellow(255,255,0);
color red(255,0,0);
color white(255,255,255);
color blue(0,0,255);
color green(0,255,0);
color pink(255,0,255);

int main(int argc, char** argv) {

    gflags::ParseCommandLineFlags(&argc, &argv, true);

    auto palette = new random_palette(0,1000);

    auto mandel = new mandelbrot();
    canvas canvas = mandel->renderToCanvas(palette);

    canvas.write();

    return 0;
}