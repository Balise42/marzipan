#include <graphics/canvas.h>
#include "mandelbrot_quadtree.h"

canvas mandelbrot_quadtree::renderToCanvas() {
    canvas c(width, height);
    fill_rectangle(0, width, 0, height, &c);
    return c;
}

void mandelbrot_quadtree::fill_rectangle(unsigned int xstart, unsigned int xend, unsigned  int ystart, unsigned int yend, canvas * pCanvas) {
    bool fillable = compute_border(xstart, xend, ystart, yend, pCanvas);
    if (fillable) {
        for (int x = xstart; x<xend; x++) {
            for (int y = ystart; y<yend; y++) {
                pCanvas->paint(x, y, pCanvas->read_color(xstart, ystart));
            }
        }
    } else {
        fill_rectangle(xstart, xstart + (xend - xstart)/2, ystart, ystart + (yend - ystart)/2, pCanvas);
        fill_rectangle(xstart + (xend - xstart)/2, xend, ystart + (yend - ystart)/2, yend, pCanvas);
        fill_rectangle(xstart, xstart + (xend - xstart)/2, ystart + (yend - ystart)/2, yend, pCanvas);
        fill_rectangle(xstart + (xend - xstart)/2, xend, ystart, ystart + (yend - ystart)/2, pCanvas);
    }
}

bool mandelbrot_quadtree::compute_border(unsigned int xstart, unsigned int xend, unsigned int ystart, unsigned int yend, canvas *pCanvas) {
    int init = compute_value(scale(xstart, ystart));
    pCanvas->paint(xstart, ystart, pal->compute_color(init));

    if (xstart == xend && ystart && yend) {
        return true;
    }

    bool ret = true;

    for (unsigned int x = xstart; x<xend; x++) {
        int value = compute_value(scale(x, ystart));
        pCanvas->paint(x, ystart, pal->compute_color(value));
        ret = ret & (value == init);
        value = compute_value(scale(x, yend-1));
        pCanvas->paint(x, yend-1, pal->compute_color(value));
        ret = ret & (value == init);
    }

    for (unsigned int y = ystart; y<yend; y++) {
        int value = compute_value(scale(xstart, y));
        pCanvas->paint(xstart, y, pal->compute_color(value));
        ret = ret & (value == init);
        value = compute_value(scale(xend-1, y));
        pCanvas->paint(xend-1, y, pal->compute_color(value));
        ret = ret & (value == init);
    }

    return ret;
}
