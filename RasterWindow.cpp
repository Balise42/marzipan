#include "RasterWindow.h"
#include <graphics/palette/gradient_palette.h>
#include <graphics/palette/random_palette.h>
#include <fractales/julia.h>


RasterWindow::RasterWindow(QWindow *parent) : QWindow(parent), m_backingStore(new QBackingStore(this)) {
    setGeometry(100, 100, 900, 600);
    frac = julia(900, 600);
    //auto palette = new random_palette(0, 1000);
    //auto palette = new repeating_gradient_palette(0,  100, color{255,255,0}, color{0,0,255}, 30);
    auto palette = new gradient_palette(0, 100, color{255, 255, 255}, color{255,0,120});
    frac.set_palette(palette);
    frac.renderToFile();
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
        frac.zoom(width(), height(), xstart, ystart, xend, yend);
        frac.renderToFile();
    }
    renderNow();
}

void RasterWindow::keyReleaseEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_R:
            frac.set_width(width());
            frac.set_height(height());
            break;

        case Qt::Key_M:
            frac.set_maxiter(frac.get_maxiter() * 2);
            break;

        case Qt::Key_D:
            frac.set_maxiter(frac.get_maxiter() / 2);
            break;
        default:
            return;
    }
    if (frac.get_palette()->is_iteration_dependent()) {
            frac.get_palette()->set_iteration_dependent(frac.get_maxiter());
    }
    frac.renderToFile();
    renderNow();
}