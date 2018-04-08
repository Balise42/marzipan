#include <assert.h>
#include "QuadtreeRenderer.h"

void QuadtreeRenderer::render(Fractal * f, Palette * p, Canvas * c) {
    assert(f->height <= c->height);
    assert(f->width <= c->width);

    fill_rectangle(0, f->width, 0, f->height, c, f, p);
}

void QuadtreeRenderer::fill_rectangle(unsigned int xstart, unsigned int xend, unsigned  int ystart, unsigned int yend, Canvas * pCanvas, Fractal * f, Palette * p) {
    if (xstart >= pCanvas->width || xend < 0 || ystart >= pCanvas->height || yend < 0 || ystart > yend || xstart > xend) {
        return;
    }

    if (xstart == xend) {
        for (unsigned int y = ystart+1; y < yend-1; y++) {
            int value = (int) f->compute_value(f->scale(xstart, y));
            pCanvas->paint(xstart, y, p->compute_color(value));
        }
        return;
    }

    if (ystart == yend) {
        for (unsigned int x = xstart+1; x<xend-1; x++) {
            int value = (int) f->compute_value(f->scale(x, ystart));
            pCanvas->paint(x, ystart, p->compute_color(value));
        }
        return;
    }

    bool fillable = compute_border(xstart, xend, ystart, yend, pCanvas, f, p);
    if (fillable) {
        Color c = p->compute_color((int) f->compute_value(f->scale(xstart, ystart)));
        for (unsigned int x = xstart+1; x<xend-1; x++) {
            for (unsigned int y = ystart+1; y<yend-1; y++) {
                pCanvas->paint(x, y, c);
            }
        }
    } else {
        fill_rectangle(xstart+1, xstart + (xend - xstart)/2, ystart+1, ystart + (yend - ystart)/2, pCanvas, f, p);
        fill_rectangle(xstart + (xend - xstart)/2, xend-1, ystart + (yend - ystart)/2, yend-1, pCanvas, f, p);
        fill_rectangle(xstart+1, xstart + (xend - xstart)/2, ystart + (yend - ystart)/2, yend-1, pCanvas, f, p);
        fill_rectangle(xstart + (xend - xstart)/2, xend-1, ystart+1, ystart + (yend - ystart)/2, pCanvas, f, p);
    }
}

bool QuadtreeRenderer::compute_border(unsigned int xstart, unsigned int xend, unsigned int ystart, unsigned int yend, Canvas *pCanvas, Fractal * f, Palette * p) {
    int init = (int) f->compute_value(f->scale(xstart, ystart));

    if (xstart >= xend && ystart >= yend) {
        return true;
    }

    bool ret = true;

    for (unsigned int x = xstart; x<xend; x++) {
        int value = (int) f->compute_value(f->scale(x, ystart));
        pCanvas->paint(x, ystart, p->compute_color(value));
        ret = ret & (value == init);
        if (ystart != yend - 1) {
            value = (int) f->compute_value(f->scale(x, yend - 1));
            pCanvas->paint(x, yend - 1, p->compute_color(value));
            ret = ret & (value == init);
        }
    }

    for (unsigned int y = ystart+1; y<yend-1; y++) {
        int value = (int) f->compute_value(f->scale(xstart, y));
        pCanvas->paint(xstart, y, p->compute_color(value));
        ret = ret & (value == init);
        if (ystart != yend - 1) {
            value = (int) f->compute_value(f->scale(xend - 1, y));
            pCanvas->paint(xend - 1, y, p->compute_color(value));
            ret = ret & (value == init);
        }
    }
    return ret;
}
