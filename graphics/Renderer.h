#ifndef MARZIPAN_RENDERER_H
#define MARZIPAN_RENDERER_H

#include <fractales/Fractal.h>
#include <graphics/palette/Palette.h>
#include "Canvas.h"

class Renderer {
public:
    virtual void render(Fractal * f, Palette * p, Canvas * c) = 0;
};

#endif