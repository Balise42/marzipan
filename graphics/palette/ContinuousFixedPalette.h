
#ifndef MARZIPAN_CONTINUOUSFIXEDPALETTE_H
#define MARZIPAN_CONTINUOUSFIXEDPALETTE_H


#include "ContinuousPalette.h"

class ContinuousFixedPalette : public ContinuousPalette {

public:
    ContinuousFixedPalette(int min, int max, const Color &cmin, const Color &cmax, const Color &inner_color,
                           int num_cols);

private:
    bool is_iteration_dependent() override ;
};


#endif //MARZIPAN_CONTINUOUSFIXEDPALETTE_H
