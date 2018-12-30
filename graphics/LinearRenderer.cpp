
#include <cassert>
#include "LinearRenderer.h"
#include "LinearRendererThreading.h"

void LinearRenderer::render(Fractal * f, Palette * p, Canvas * c) {
    assert(f->height <= c->height);
    assert(f->width <= c->width);

    auto *lrt = new LinearRendererThreading(f->width, f->height);
    lrt->computeColorsThreaded(f, p);

    for (unsigned int x = 0; x<f->width; x++) {
        for (unsigned int y = 0; y<f->height; y++) {
            c->paint(x, y, lrt->getColor(x, y));
        }
    }

}
