#include "gtest/gtest.h"
#include "Canvas.h"

TEST(CanvasTest, PaintPixel) {
    Color color(1, 2, 3);
    Canvas * canvas = new Canvas();
    canvas->paint(8, 10, color);
    ASSERT_EQ(color, canvas->readColor(8, 10));
    delete canvas;
}