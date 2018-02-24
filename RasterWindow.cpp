#include "RasterWindow.h"
#include <graphics/palette/gradient_palette.h>


RasterWindow::RasterWindow(QWindow *parent) : QWindow(parent), m_backingStore(new QBackingStore(this)) {
    setGeometry(100, 100, 900, 600);
    mandel = mandelbrot(900, 600);
    //auto palette = new random_palette(0, 1000);
    auto palette = new gradient_palette(0,  100, color{255,0,120}, color{255,255,255});
    mandel.set_palette(palette);
    mandel.renderToFile();
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

    QPaintDevice *device = m_backingStore->paintDevice();
    QPainter painter(device);

    painter.fillRect(0, 0, width(), height(), Qt::white);
    render(&painter);
    painter.end();

    m_backingStore->endPaint();
    m_backingStore->flush(rect);
}

void RasterWindow::render(QPainter *painter) {
    QPixmap pixmap("plop.bmp");
    painter->drawPixmap(QRect(0, 0, width(), height()), pixmap);
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
        mandel.zoom(width(), height(), xstart, ystart, xend, yend);
        mandel.renderToFile();
    }
    renderNow();
}

void RasterWindow::keyReleaseEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_R:
            mandel.set_width(width());
            mandel.set_height(height());
            break;

        case Qt::Key_M:
            mandel.set_maxiter(mandel.get_maxiter() * 2);
            break;

        case Qt::Key_D:
            mandel.set_maxiter(mandel.get_maxiter() / 2);
            break;
        default:
            return;
    }
    if (mandel.get_palette()->is_iteration_dependent()) {
            mandel.get_palette()->set_iteration_dependent(mandel.get_maxiter());
    }
    mandel.renderToFile();
    renderNow();
}