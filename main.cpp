#include <iostream>
#include "CImg.h"

using namespace cimg_library;

int main() {

    CImg<unsigned char> canvas(500, 400, 1, 3, 0);
    canvas.save_bmp("plop.bmp");
    return 0;
}