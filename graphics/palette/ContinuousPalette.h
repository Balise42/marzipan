
#ifndef MARZIPAN_CONTINUOUSPALETTE_H
#define MARZIPAN_CONTINUOUSPALETTE_H


#include <vector>
#include "Palette.h"

class ContinuousPalette : public Palette {
public:

    ContinuousPalette(int min, int max, std::vector<Color *> colors, Color inner_color);

    Color compute_color(double value) override;

private:
    int min;
    int max;
    std::vector<unsigned char> R;
    std::vector<unsigned char> G;
    std::vector<unsigned char> B;

    unsigned char compute_component(double value, std::vector<unsigned char> v);

    bool is_iteration_dependent() override;

    void recompute(Fractal *fractal) override;

};


#endif //MARZIPAN_CONTINUOUSPALETTE_H
