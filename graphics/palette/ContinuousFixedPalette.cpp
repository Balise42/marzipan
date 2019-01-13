
#include "ContinuousFixedPalette.h"

bool ContinuousFixedPalette::is_iteration_dependent() {
    return false;
}

ContinuousFixedPalette::ContinuousFixedPalette(int min, int max, const std::vector<Color *> &colors,
                                               const Color &inner_color) : ContinuousPalette(min, max,
                                                                                             colors,
                                                                                             inner_color) {}
