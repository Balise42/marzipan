#include "gtest/gtest.h"
#include "graphics/ImageCanvas.h"

TEST(CanvasTest, PaintPixel) {
    Color color(1, 2, 3);
    ImageCanvas c{};
    c.paint(8, 10, color);
    ASSERT_EQ(color, c.read_color(8, 10));
}