#include "Canvas.h"


int main() {

    auto canvas = new Canvas();
    Color col(255, 120, 40);

    for (unsigned int i = 100; i<200; i++) {
        for (unsigned int j = 100; j<200; j++) {
            canvas->paint(i, j, col);
        }
    }

    canvas->write("plop.bmp");

    delete canvas;

    return 0;
}