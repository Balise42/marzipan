#include <QApplication>
#include "RasterWindow.h"
#include <fractales/Mandelbrot.h>
#include <graphics/palette/RandomPalette.h>


int main(int argc, char **argv) {
    QApplication app(argc, argv);
    RasterWindow window;
    window.show();
    return app.exec();
}