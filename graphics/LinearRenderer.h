
#ifndef MARZIPAN_LINEAR_RENDERER_H
#define MARZIPAN_LINEAR_RENDERER_H


#include "Renderer.h"

class LinearRenderer : public Renderer {
public:
    void render(Fractal * f, Palette * p, Canvas * c) override;
};


#endif //MARZIPAN_LINEAR_RENDERER_H
