#include "QPainterCanvas.h"

void QPainterCanvas::paint(unsigned int x, unsigned int y, Color c) {
    QColor qColor(c.R, c.B, c.G);
    qPainter->setPen(qColor);
    qPainter->drawPoint(x, y);
}

Color QPainterCanvas::read_color(unsigned int x, unsigned int y) {
    return Color(0,0,0);
}
