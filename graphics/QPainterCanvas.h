#ifndef MARZIPAN_QPAINTER_CANVAS_H
#define MARZIPAN_QPAINTER_CANVAS_H

#include <qt5/QtGui/QtGui>
#include "Canvas.h"

class QPainterCanvas : public Canvas {

public:

    QPainterCanvas(QPainter * qPainter, unsigned int width, unsigned int height) : Canvas() {
        this->qPainter = qPainter;
        this->width = width;
        this->height = height;
    }

    void paint(unsigned int x, unsigned int y, Color c) override;
    Color read_color(unsigned int x, unsigned int y) override;

private:
    QPainter * qPainter;
};


#endif //MARZIPAN_QPAINTER_CANVAS_H
