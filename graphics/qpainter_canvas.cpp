#include "qpainter_canvas.h"

void qpainter_canvas::paint(unsigned int x, unsigned int y, color c) {
    QColor qColor(c.R, c.B, c.G);
    qPainter->setPen(qColor);
    qPainter->drawPoint(x, y);
}

color qpainter_canvas::read_color(unsigned int x, unsigned int y) {
    return color(0,0,0);
}
