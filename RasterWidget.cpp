#include "RasterWidget.h"
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
#include <QMenu>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>


Color black(0, 0, 0);
Color yellow(255, 255, 0);
Color red(255, 0, 0);
Color white(255, 255, 255);
Color blue(0, 0, 255);
Color darkgreen(0, 100, 0);
Color pink(255, 0, 255);
Color champagne(247, 231, 206);
Color dark_champagne(41, 25, 0);
Color orange(255, 127, 0);
Color violet(139, 0, 255);
Color lightpink(255, 182, 193);
Color lightgreen(172, 225, 175);

Color purple(148, 0, 211);
Color indigo(75, 0, 130);
Color green(0, 255, 0);
Color teal(0, 128, 128);
Color darkblue(0, 0, 128);
Color softpink(255, 221, 244);


RasterWidget::RasterWidget(QWidget *parent) : QWidget(parent) {

    //Orbit * o = new LineOrbit(1, 0, -2, 100);
    CImg<unsigned char> img("/home/isa/projets/marzipan/marzipan.bmp");
    //std::vector<Orbit *> o = {new BitmapOrbit(&img, 100)};
    //std::vector<Orbit *> o = {new PointOrbit(0.5, -0.25, 100)};
    //fractal = new OrbitMandelbrot(o);
    fractal = new ContinuousMandelbrot();
    fractal->set_maxiter(100);

    //std::vector<Color*> colors = {&black, &yellow, &white, &yellow, &black};
    //std::vector<Color*> colors = {&green, &darkgreen, &teal, &darkblue, &teal, &darkgreen, &green};
    std::vector<Color *> colors = {&softpink, &teal, &white, &teal, &softpink};

    palette = new ContinuousFixedPalette(0, 100, colors, black);
    //palette = new RandomPalette(0, 100, black);
    renderer = new LinearRenderer();
    computeFractal();
}

void RasterWidget::resizeEvent(QResizeEvent *resizeEvent) {
    //backing_store->resize(resizeEvent->size());
}

void RasterWidget::renderNow() {
    this->update();
}

void RasterWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.fillRect(0, 0, width(), height(), Qt::white);
    QPixmap pixmap("plop.bmp");
    painter.drawPixmap(QRect(0, 0, width(), height()), pixmap);
}

bool RasterWidget::event(QEvent *event) {
    if (event->type() == QEvent::UpdateRequest) {
        renderNow();
        return true;
    }
    return QWidget::event(event);
}

void RasterWidget::mousePressEvent(QMouseEvent *event) {
    xstart = event->x();
    ystart = event->y();
}

void RasterWidget::mouseReleaseEvent(QMouseEvent *event) {
    int xend = event->x();
    int yend = event->y();


    int xtmp = xstart + int((yend - ystart) * ((double) width()) / ((double) height()));
    int ytmp = ystart + int((xend - xstart) * ((double) height()) / ((double) width()));

    if (xtmp > xend) {
        xend = xtmp;
    } else {
        yend = ytmp;
    }

    if (xstart > 0 && ystart > 0 && xend > xstart && yend > ystart) {
        saveStateToStack(fractal);
        fractal->zoom(width(), height(), xstart, ystart, xend, yend);
        if (palette->is_iteration_dependent()) {
            palette->recompute(fractal);
        }
    }
    computeFractal();
    renderNow();
}


void RasterWidget::processKeyEvent(int key) {
    switch (key) {
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

void RasterWidget::computeFractal() {
    fractal->set_width(width());
    fractal->set_height(height());
    auto canvas = new ImageCanvas(width(), height());
    renderer->render(fractal, palette, canvas);
    canvas->write();
    delete canvas;
}

void RasterWidget::saveStateToStack(Fractal *fractal) {
    undoStack.push(fractal->clone());
}

void RasterWidget::undo() {
    if (!undoStack.empty()) {
        redoStack.push(fractal->clone());
        fractal = undoStack.top();
        undoStack.pop();
        computeFractal();
        renderNow();
    }
}

void RasterWidget::redo() {
    if (!redoStack.empty()) {
        undoStack.push(fractal->clone());
        fractal = redoStack.top();
        redoStack.pop();
        computeFractal();
        renderNow();
    }
}

// Implement basic save. Right now it just copies the "backing" image to the designated file. Good enough for now ;)
void RasterWidget::saveImage() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save image", "", "BMP (*.bmp);;All Files (*)");
    if (fileName.isEmpty()) {
        return;
    } else {
        if (!fileName.endsWith(".bmp", Qt::CaseInsensitive)) {
            fileName = fileName + ".bmp";
        }
        if (QFile::exists(fileName)) {
            QFile::remove(fileName);
        }
        QFile::copy("plop.bmp", fileName);
    }
}