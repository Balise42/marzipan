#include "RasterWindow.h"
#include <qt5/QtGui/QtGui>
#include <fractales/mandelbrot.h>
#include <graphics/palette/random_palette.h>


RasterWindow::RasterWindow(QWindow *parent) :QWindow(parent), m_backingStore(new QBackingStore(this)) {
    setGeometry(100, 100, 300,200);
}

void RasterWindow::exposeEvent(QExposeEvent *event) {
    if (isExposed()) {
        renderNow();
    }
}

void RasterWindow::resizeEvent(QResizeEvent *resizeEvent) {
    m_backingStore->resize(resizeEvent->size());
    if (isExposed()) {
        renderNow();
    }
}

void RasterWindow::renderNow() {
    if (!isExposed()) {
        return;
    }

    QRect rect(0, 0, width(), height());
    m_backingStore->beginPaint(rect);

    QPaintDevice * device = m_backingStore->paintDevice();
    QPainter painter(device);

    painter.fillRect(0, 0, width(), height(), Qt::white);
    render(&painter);
    painter.end();

    m_backingStore->endPaint();
    m_backingStore->flush(rect);
}

void RasterWindow::render(QPainter * painter) {
    QPixmap pixmap("plop.bmp");
    painter->drawPixmap(QRect(0, 0, width(), height()), pixmap);
}

void RasterWindow::renderLater() {
    requestUpdate();
}

bool RasterWindow::event(QEvent * event) {
    if (event->type() == QEvent::UpdateRequest) {
        renderNow();
        return true;
    }
    return QWindow::event(event);
}

void RasterWindow::mousePressEvent(QMouseEvent *event) {
    xstart = event->x();
    ystart = event->y();
}

void RasterWindow::mouseReleaseEvent(QMouseEvent * event) {
    int xend = event->x();
    int yend = event->y();
    if (xstart > 0 && ystart > 0 && xend > xstart & yend > ystart) {
        double left = double(xstart)/width();
        double right = double(xend)/width();
        double top = double(ystart)/height();
        double bottom = double(yend)/height();
        mandelbrot m(width(), height(), left, right, top, bottom);
        m.set_maxiter(10);
        random_palette * palette = new random_palette(0, 50);
        canvas c = m.renderToCanvas(palette);
        c.write();
    }
    renderNow();
}
