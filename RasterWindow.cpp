#include "RasterWindow.h"
#include <graphics/palette/GradientPalette.h>
#include <graphics/palette/RandomPalette.h>
#include <fractales/Julia.h>
#include <graphics/QuadtreeRenderer.h>
#include <graphics/palette/HistoPalette.h>
#include <QtGui/QWindow>
#include <fractales/MartinMandelbrot.h>
#include <graphics/LinearRenderer.h>
#include <fractales/ContinuousMandelbrot.h>
#include <graphics/palette/ContinuousPalette.h>
#include <fractales/OrbitMandelbrot.h>
#include <graphics/palette/ContinuousFixedPalette.h>
#include <fractales/MandelbrotExperiments.h>
#include <fractales/orbits/PointOrbit.h>
#include <fractales/orbits/LineOrbit.h>
#include <fractales/orbits/BitmapOrbit.h>


Color black(0,0,0);
Color yellow(255,255,0);
Color red(255,0,0);
Color white(255,255,255);
Color blue(0,0,255);
Color green(0,100,0);
Color pink(255,0,255);
Color champagne(247,231,206);
Color dark_champagne(41 ,25, 0);
Color orange(255, 127, 0);
Color violet(139,0,255);
Color lightpink(255, 182, 193);
Color lightgreen(172, 225, 175);


RasterWindow::RasterWindow(QWindow *parent) : QWindow(parent), backing_store(new QBackingStore(this)) {
    setGeometry(100, 100, 900, 600);
    //Orbit * o = new LineOrbit(1, 0, -2, 100);
    CImg<unsigned char> img("/home/isa/projets/marzipan/marzipan.bmp");
    std::vector<Orbit *> o = {new BitmapOrbit(&img, 100)};
    //std::vector<Orbit *> o = {new PointOrbit(0.5, -0.25, 100)};
    fractal = new OrbitMandelbrot(o);
    //fractal = new ContinuousMandelbrot();
    fractal->set_maxiter(100);

    std::vector<Color*> colors = {&white, &lightpink, &white, &lightgreen, &white, &lightpink, &white};

    palette = new ContinuousFixedPalette(0, 100, colors, black);
    //palette = new RandomPalette(0, 100, black);
    renderer = new LinearRenderer();
    computeFractal();
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


/*    int xtmp = xstart + int((yend - ystart)*((double)width())/((double)height()));
    int ytmp = ystart + int((xend - xstart)*((double)height())/((double)width()));

    if (xtmp > xend) {
        xend = xtmp;
    } else {
        yend = ytmp;
    }*/

    if (xstart > 0 && ystart > 0 && xend > xstart && yend > ystart) {
        fractal->zoom(width(), height(), xstart, ystart, xend, yend);
        if (palette->is_iteration_dependent()) {
            palette->recompute(fractal);
        }
    }
    computeFractal();
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
    computeFractal();
    renderNow();
}

void RasterWindow::computeFractal() {
    fractal->set_width(width());
    fractal->set_height(height());
    auto canvas = new ImageCanvas(width(), height());
    renderer->render(fractal, palette, canvas);
    canvas->write();
    delete canvas;
}