#include "RasterWindow.h"
#include <graphics/palette/GradientPalette.h>
#include <graphics/palette/RandomPalette.h>
#include <fractales/Julia.h>
#include <graphics/QPainterCanvas.h>
#include <graphics/QuadtreeRenderer.h>


RasterWindow::RasterWindow(QWindow *parent) : QWindow(parent), backing_store(new QBackingStore(this)) {
    setGeometry(100, 100, 900, 600);
    palette = new RandomPalette(0, 1000);
    fractal = new Mandelbrot(128,128);
    renderer = new QuadtreeRenderer();
}

void RasterWindow::exposeEvent(QExposeEvent *event) {
    if (isExposed()) {
        renderNow();
    }
}

void RasterWindow::resizeEvent(QResizeEvent *resizeEvent) {
    backing_store->resize(resizeEvent->size());
    if (isExposed()) {
        renderNow();
    }
}

void RasterWindow::renderNow() {
    if (!isExposed()) {
        return;
    }

    QRect rect(0, 0, width(), height());
    backing_store->beginPaint(rect);

    QPaintDevice *device = backing_store->paintDevice();
    QPainter painter(device);

    painter.fillRect(0, 0, width(), height(), Qt::white);
    render(&painter);
    painter.end();

    backing_store->endPaint();
    backing_store->flush(rect);
}

void RasterWindow::render(QPainter *painter) {
    //frac.renderToPainter(painter);
    auto canvas = new QPainterCanvas(painter, width(), height());
    renderer->render(fractal, palette, canvas);

}

void RasterWindow::renderLater() {
    requestUpdate();
}

bool RasterWindow::event(QEvent *event) {
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

void RasterWindow::mouseReleaseEvent(QMouseEvent *event) {
    int xend = event->x();
    int yend = event->y();
    if (xstart > 0 && ystart > 0 && xend > xstart && yend > ystart) {
        fractal->zoom(width(), height(), xstart, ystart, xend, yend);
    }
    renderNow();
}

void RasterWindow::keyReleaseEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_R:
            fractal->set_width(width());
            fractal->set_height(height());
            break;

        case Qt::Key_M:
            fractal->set_maxiter(fractal->get_maxiter() * 2);
            break;

        case Qt::Key_D:
            fractal->set_maxiter(fractal->get_maxiter() / 2);
            break;
        default:
            return;
    }
    if (palette->is_iteration_dependent()) {
            palette->set_iteration_dependent(fractal->get_maxiter());
    }
    renderNow();
}