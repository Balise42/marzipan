#include <qt5/QtGui/QGuiApplication>
#include "RasterWindow.h"
#include <fractales/mandelbrot.h>
#include <graphics/palette/random_palette.h>


int main(int argc, char ** argv) {
    QGuiApplication app(argc, argv);
    RasterWindow window;
    mandelbrot m(900, 600);
    m.set_maxiter(10);
    random_palette * palette = new random_palette(0, 10);
    canvas c = m.renderToCanvas(palette);
    c.write();
    delete palette;
    window.show();
    return app.exec();
}