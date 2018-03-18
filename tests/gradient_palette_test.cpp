#include "gtest/gtest.h"
#include "graphics/palette/GradientPalette.h"

TEST(gradient_palette, compute_value) {
    Color black(0, 0, 0);
    Color white(255, 255, 255);
    GradientPalette gp(0, 255, black, white);
    ASSERT_EQ(Color(50,50,50), gp.compute_color(50));
    GradientPalette gp2(0, 255, white, black);
    ASSERT_EQ(Color(205,205,205), gp2.compute_color(50));
    Color test(10, 20, 30);
    GradientPalette gp3(0, 10, black, test);
    ASSERT_EQ(Color(4,8,12), gp3.compute_color(4));
}