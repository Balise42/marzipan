#ifndef MARZIPAN_RASTERWINDOW_H
#define MARZIPAN_RASTERWINDOW_H

#include <qt5/QtGui/QtGui>
#include <fractales/Fractal.h>
#include <fractales/Mandelbrot.h>
#include <graphics/Renderer.h>

class RasterWindow : public QWindow {
    Q_OBJECT
public:
    explicit RasterWindow(QWindow * parent = 0);
    virtual void render(QPainter * painter);

public slots:
    void renderLater();
    void renderNow();

protected:
    bool event(QEvent *event);
    void resizeEvent(QResizeEvent *event);
    void exposeEvent(QExposeEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyReleaseEvent(QKeyEvent *);

private:
    QRect rect;
    QBackingStore *backing_store;

    Fractal * fractal;
    Palette * palette;

    //TODO move this away from this class
    int xstart = -1;
    int ystart = -1;

    Renderer *renderer;

    void paintEvent(QEvent *event);
};


#endif //MARZIPAN_RASTERWINDOW_H
