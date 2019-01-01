
#include "ContinuousFixedPalette.h"

bool ContinuousFixedPalette::is_iteration_dependent() {
    return false;
}

ContinuousFixedPalette::ContinuousFixedPalette(int min, int max, const Color &cmin, const Color &cmax,
                                               const Color &inner_color, int num_cols) : ContinuousPalette(min, max,
                                                                                                           cmin, cmax,
                                                                                                           inner_color,
                                                                                                           num_cols) {}
