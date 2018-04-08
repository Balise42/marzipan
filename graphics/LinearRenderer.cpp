
#include <assert.h>
#include "LinearRenderer.h"

void LinearRenderer::render(Fractal * f, Palette * p, Canvas * c) {
    assert(f->height <= c->height);
    assert(f->width <= c->width);

    for (unsigned int x = 0; x<f->width; x++) {
        for (unsigned int y = 0; y<f->height; y++) {
            double value = f->compute_value(f->scale(x, y));
            c->paint(x, y, p->compute_color(value));
        }
    }

}
