#include <qt5/QtGui/QGuiApplication>
#include "RasterWindow.h"
#include <fractales/mandelbrot.h>
#include <graphics/palette/random_palette.h>


int main(int argc, char ** argv) {
    QGuiApplication app(argc, argv);
    RasterWindow window;
    window.show();
    return app.exec();
}