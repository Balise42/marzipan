#include "gtest/gtest.h"
#include "../graphics/palette/gradient_palette.h"

TEST(gradient_palette, compute_value) {
    color black(0, 0, 0);
    color white(255, 255, 255);
    gradient_palette gp(0, 255, black, white);
    ASSERT_EQ(color(50,50,50), gp.compute_color(50));
    gradient_palette gp2(0, 255, white, black);
    ASSERT_EQ(color(205,205,205), gp2.compute_color(50));
    color test(10, 20, 30);
    gradient_palette gp3(0, 10, black, test);
    ASSERT_EQ(color(4,8,12), gp3.compute_color(4));
}