
#include <queue>
#include <iostream>
#include "BitmapMapComputer.h"

void BitmapMapComputer::computeMap(CImg<unsigned char> *img, std::map<std::pair<int,int>, double> * distances) {
    std::map<std::pair<int,int>, bool> visited;

    std::priority_queue<std::pair<int, std::pair<int,int>>> queue;

    for (int x = 0; x<img->width(); x++) {
        for (int y = 0; y<img->height(); y++) {
            if(*(img->data(x, y, 0, 0)) == 0) {
                visited[std::make_pair(x, y)] = true;
                (*distances)[std::make_pair(x, y)] = 0;
                for (auto neigh : getNeighbors(x, y)) {
                    if (!visited[neigh]) {
                        (*distances)[neigh] = 10;
                        queue.push(std::make_pair(-10, neigh));
                    }
                }
            }
        }
    }

    while (!queue.empty()) {
        auto v = queue.top();
        queue.pop();
        for (auto neigh : getNeighbors(v.second.first, v.second.second)) {
            int alt = -v.first + 1;
            if (!visited[neigh] || alt < (*distances)[neigh]) {
                (*distances)[neigh] = alt;
                if (isValid(neigh)) {
                    queue.push(std::make_pair(-alt, neigh));
                }
                visited[neigh] = true;
            }
        }
    }
}


std::vector<std::pair<int, int>> BitmapMapComputer::getNeighbors(int x, int y) {
    std::vector<std::pair<int,int>> v = {
            std::make_pair(x-1, y-1),
            std::make_pair(x-1, y),
            std::make_pair(x-1, y+1),
            std::make_pair(x, y-1),
            std::make_pair(x, y+1),
            std::make_pair(x+1, y-1),
            std::make_pair(x+1, y),
            std::make_pair(x+1, y+1)
    };
    return v;
}

bool BitmapMapComputer::isValid(std::pair<int, int> pair) {
    return pair.first >= -100 && pair.second >= -100 && pair.first <= 1000 && pair.second <= 700;
}
