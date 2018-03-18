
#ifndef MARZIPAN_QUADTREE_RENDERER_H
#define MARZIPAN_QUADTREE_RENDERER_H


#include "Renderer.h"

class QuadtreeRenderer : public Renderer {
public:
    void render(Fractal * f, Palette * p, Canvas * c) override;
private:

    void fill_rectangle(unsigned int xstart, unsigned int xend, unsigned int ystart, unsigned int yend, Canvas *pCanvas,
                        Fractal *f, Palette *p);

    bool compute_border(unsigned int xstart, unsigned int xend, unsigned int ystart, unsigned int yend, Canvas *pCanvas,
                        Fractal *f, Palette *p);
};


#endif //MARZIPAN_QUADTREE_RENDERER_H
