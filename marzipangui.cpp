#include <qt5/QtGui/QGuiApplication>
#include "RasterWindow.h"
#include <fractales/Mandelbrot.h>
#include <graphics/palette/RandomPalette.h>


int main(int argc, char ** argv) {
    QGuiApplication app(argc, argv);
    RasterWindow window;
    window.show();
    return app.exec();
}