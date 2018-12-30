#include <fractales/Fractal.h>
#include <graphics/palette/Palette.h>
#include <qt5/QtConcurrent/QtConcurrentMap>
#include "LinearRendererThreading.h"
#include "ColoredPoint.h"


Color LinearRendererThreading::getColor(unsigned int x, unsigned int y) {
    return computedColors[x][y]->color;
}

LinearRendererThreading::LinearRendererThreading(unsigned int width, unsigned int height) {
    computedColors = std::vector<std::vector<ColoredPoint *>>(width, std::vector<ColoredPoint*>(height));
    for (unsigned int x = 0; x<width; x++) {
        for (unsigned int y = 0; y<height; y++) {
            computedColors[x][y] = new ColoredPoint(x, y);
        }
    }
}

void LinearRendererThreading::computeValue(std::vector<ColoredPoint *> points, Fractal * fractal, Palette * palette) {
    std::vector<ColoredPoint *> res = std::vector<ColoredPoint *>(points.size());
    for (auto point : points) {
        double value = fractal->compute_value(fractal->scale(point->x, point->y));
        Color color = palette->compute_color(value);
        point->color = color;
    }
}

struct ColorComputer {
    Fractal * fractal;
    Palette * palette;

    ColorComputer(Fractal * f, Palette * p) : fractal(f), palette(p) {
    }

    void operator()(std::vector<ColoredPoint*> points) {
        LinearRendererThreading::computeValue(points, fractal, palette);
    }


};


void LinearRendererThreading::computeColorsThreaded(Fractal *fractal, Palette *palette) {
    QtConcurrent::blockingMap(computedColors.begin(), computedColors.end(), ColorComputer(fractal, palette));
}



