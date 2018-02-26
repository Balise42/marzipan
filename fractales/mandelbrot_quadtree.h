//
// Created by isa on 2/26/18.
//

#ifndef MARZIPAN_MANDELBROT_QUADTREE_H
#define MARZIPAN_MANDELBROT_QUADTREE_H

#include "mandelbrot.h"

class mandelbrot_quadtree : public mandelbrot {

public:
    mandelbrot_quadtree() : mandelbrot() {}

    mandelbrot_quadtree(unsigned int width, unsigned int height) : mandelbrot(width, height) {}

    mandelbrot_quadtree(unsigned int width, unsigned int height, double left, double right, double top, double bottom)
            : mandelbrot(width, height, left, right, top, bottom) {}

    canvas renderToCanvas() override;

    void fill_rectangle(unsigned int xstart, unsigned int xend, unsigned int ystart, unsigned int yend, canvas *pCanvas);

    bool compute_border(unsigned int xstart, unsigned int xend, unsigned int ystart, unsigned int yend, canvas *pCanvas);
};

#endif //MARZIPAN_MANDELBROT_QUADTREE_H
