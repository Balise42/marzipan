#include "gtest/gtest.h"
#include "graphics/image_canvas.h"

TEST(CanvasTest, PaintPixel) {
    color color(1, 2, 3);
    image_canvas c{};
    c.paint(8, 10, color);
    ASSERT_EQ(color, c.read_color(8, 10));
}