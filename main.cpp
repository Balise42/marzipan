#include <gflags/gflags.h>
#include <fractales/mandelbrot_quadtree.h>
#include <graphics/palette/histo_palette.h>
#include "graphics/image_canvas.h"
#include "graphics/palette/gradient_palette.h"
#include "fractales/mandelbrot.h"
#include "graphics/palette/random_palette.h"

color black(0,0,0);
color yellow(255,255,0);
color red(255,0,0);
color white(255,255,255);
color blue(0,0,255);
color green(0,100,0);
color pink(255,0,255);

int main(int argc, char** argv) {

    gflags::ParseCommandLineFlags(&argc, &argv, true);

    //auto palette = new random_palette(0,4000);

    auto mandel = new mandelbrot_quadtree();
    auto palette = new histo_palette(mandel->compute_histo(), white, green, 430, black);
    //auto palette = new repeating_gradient_palette(0, 400, pink, white, 64, white);
    mandel->set_palette(palette);
    image_canvas canvas = mandel->renderToCanvas();

    canvas.write();

    return 0;
}