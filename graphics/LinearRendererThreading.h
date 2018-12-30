#ifndef MARZIPAN_LINEARRENDERERTHREADING_H
#define MARZIPAN_LINEARRENDERERTHREADING_H


#include <vector>
#include "Color.h"
#include "ColoredPoint.h"

class LinearRendererThreading {
public:
    LinearRendererThreading(unsigned int width, unsigned int height);

    Color getColor(unsigned int x, unsigned int y);
    void computeColorsThreaded(Fractal *fractal, Palette *palette);
    static void computeValue(std::vector<ColoredPoint *> points, Fractal *fractal, Palette *palette);


private:
    std::vector<std::vector<ColoredPoint*>> computedColors;

};


#endif //MARZIPAN_LINEARRENDERERTHREADING_H
