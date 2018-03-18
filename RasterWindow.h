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
    bool event(QEvent * event) override;
    void resizeEvent(QResizeEvent *event) override;
    void exposeEvent(QExposeEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void keyReleaseEvent(QKeyEvent *) override;

private:
    QBackingStore *backing_store;

    Fractal * fractal;
    Palette * palette;

    //TODO move this away from this class
    int xstart = -1;
    int ystart = -1;

    Renderer *renderer;
};


#endif //MARZIPAN_RASTERWINDOW_H
