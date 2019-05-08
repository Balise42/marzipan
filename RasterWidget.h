#ifndef MARZIPAN_RASTERWIDGET_H
#define MARZIPAN_RASTERWIDGET_H

#include <qt5/QtGui/QtGui>
#include <fractales/Fractal.h>
#include <fractales/Mandelbrot.h>
#include <graphics/Renderer.h>
#include <stack>
#include <QMenu>
#include <QMainWindow>


class RasterWidget : public QWidget {
    Q_OBJECT
public:
    explicit RasterWidget(QWidget * parent = 0);
    void saveStateToStack(Fractal *pFractal);
    void undo();
    void redo();
    void saveImage();
    void saveParams();
    void loadParams();
    void processKeyEvent(int key);

public slots:
    void renderNow();

protected:
    bool event(QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


private:
    QRect rect;

    Fractal * fractal;
    Palette * palette;
    std::stack<Fractal *> undoStack;
    std::stack<Fractal *> redoStack;

    //TODO move this away from this class
    int xstart = -1;
    int ystart = -1;

    Renderer *renderer;
    void computeFractal();

    void paintEvent(QPaintEvent *event) override;

};


#endif //MARZIPAN_RASTERWIDGET_H
