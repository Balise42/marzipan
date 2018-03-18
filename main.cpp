#include <gflags/gflags.h>
#include <graphics/palette/HistoPalette.h>
#include <graphics/QuadtreeRenderer.h>
#include "graphics/ImageCanvas.h"
#include "graphics/palette/GradientPalette.h"
#include "fractales/Mandelbrot.h"
#include "graphics/palette/RandomPalette.h"

Color black(0,0,0);
Color yellow(255,255,0);
Color red(255,0,0);
Color white(255,255,255);
Color blue(0,0,255);
Color green(0,100,0);
Color pink(255,0,255);

int main(int argc, char** argv) {

    gflags::ParseCommandLineFlags(&argc, &argv, true);

    //auto palette = new random_palette(0,4000);

    auto mandel = new Mandelbrot();
    auto palette = new HistoPalette(mandel->compute_histo(), white, green, 430, black);
    //auto palette = new repeating_gradient_palette(0, 400, pink, white, 64, white);
    auto renderer = new QuadtreeRenderer();
    auto canvas = new ImageCanvas(mandel->width, mandel->height);
    renderer->render(mandel, palette, canvas);
    canvas->write();

    return 0;
}