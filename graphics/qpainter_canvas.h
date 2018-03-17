#ifndef MARZIPAN_QPAINTER_CANVAS_H
#define MARZIPAN_QPAINTER_CANVAS_H

#include <qt5/QtGui/QtGui>
#include "canvas.h"

class qpainter_canvas : public canvas {

public:

    qpainter_canvas(QPainter * qPainter, unsigned int width, unsigned int height) : canvas() {
        this->qPainter = qPainter;
        this->width = width;
        this->height = height;
    }

    void paint(unsigned int x, unsigned int y, color c) override;
    color read_color(unsigned int x, unsigned int y) override;

private:
    QPainter * qPainter;
};


#endif //MARZIPAN_QPAINTER_CANVAS_H
