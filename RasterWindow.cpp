#include "RasterWindow.h"
#include <graphics/palette/GradientPalette.h>
#include <graphics/palette/RandomPalette.h>
#include <fractales/Julia.h>
#include <graphics/QPainterCanvas.h>
#include <graphics/QuadtreeRenderer.h>
#include <graphics/palette/HistoPalette.h>
#include <QtGui/QWindow>


Color black(0,0,0);
Color yellow(255,255,0);
Color red(255,0,0);
Color white(255,255,255);
Color blue(0,0,255);
Color green(0,100,0);
Color pink(255,0,255);

RasterWindow::RasterWindow(QWindow *parent) : QWindow(parent), backing_store(new QBackingStore(this)) {
    setGeometry(100, 100, 900, 600);
    fractal = new Mandelbrot();
    palette = new HistoPalette(((Mandelbrot *)fractal)->compute_histo(), pink, white, 100, black);
    renderer = new QuadtreeRenderer();
}

void RasterWindow::exposeEvent(QExposeEvent *event) {
    if (isExposed()) {
        renderNow();
    }
}

void RasterWindow::resizeEvent(QResizeEvent *resizeEvent) {
    backing_store->resize(resizeEvent->size());
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
    auto canvas = new QPainterCanvas(painter, width(), height());
    fractal->height = height();
    fractal->width = width();
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
        if (palette->is_iteration_dependent()) {
            palette->recompute(fractal);
        }
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
        palette->recompute(fractal);
    }
    renderNow();
}