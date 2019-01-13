
#ifndef MARZIPAN_CONTINUOUSFIXEDPALETTE_H
#define MARZIPAN_CONTINUOUSFIXEDPALETTE_H


#include "ContinuousPalette.h"

class ContinuousFixedPalette : public ContinuousPalette {

public:
    ContinuousFixedPalette(int min, int max, const std::vector<Color *> &colors, const Color &inner_color);

private:


    bool is_iteration_dependent() override ;
};


#endif //MARZIPAN_CONTINUOUSFIXEDPALETTE_H
