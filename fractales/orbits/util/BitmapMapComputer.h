
#ifndef MARZIPAN_BITMAPMAPCOMPUTER_H
#define MARZIPAN_BITMAPMAPCOMPUTER_H

#include <map>
#include "CImg.h"
#include <vector>


using namespace cimg_library;

class BitmapMapComputer {
public:
    void computeMap(CImg<unsigned char> *img, std::map<std::pair<int,int>, double> * distances);

    std::vector<std::pair<int, int>> getNeighbors(int x, int y);

    bool isValid(std::pair<int, int> pair);
};


#endif //MARZIPAN_BITMAPMAPCOMPUTER_H
