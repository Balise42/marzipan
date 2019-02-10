
#include <iostream>
#include "BitmapOrbit.h"

double BitmapOrbit::getOrbitFastValue(std::complex<double> z) {
    double x = z.real();
    double y = z.imag();

    int xImg = (( int) ((x + 2) / 3 * 899));

    int offsetX = 0;
    int offsetY = 0;

    if (xImg < 0) {
        offsetX = -xImg;
        xImg = 0;
    }
    if (xImg > 899) {
        offsetX = xImg - 899;
        xImg = 899;
    }

    int yImg = ( int) ((y + 1) / 2 * 599);

    if (yImg < 0) {
        offsetY = -yImg;
        yImg = 0;
    }
    if (yImg > 599) {
        offsetY = yImg - 599;
        yImg = 599;
    }

    return distances[xImg][yImg] + offsetX + offsetY;
}

double BitmapOrbit::getOrbitValue(double v) {
    double res =  (v - this->translation) * this->factor;
    return res;
}

BitmapOrbit::BitmapOrbit(CImg<unsigned char> *img, double max_value) {
    this->bitmap = img;

    CImg<unsigned char> * map = new CImg<unsigned char>(900, 600, 1, 3, 0);

    for (unsigned int i = 0; i < 900; i++) {
        distances[i] = new double[600];
        for (unsigned int j = 0; j < 600; j++) {
            distances[i][j] = precompute_distance(i, j);
            (*map)(i, j, 0) = distances[i][j];
            (*map)(i, j, 1) = distances[i][j];
            (*map)(i, j, 2) = distances[i][j];
        }
    }

    map->save_bmp("map.bmp");

    double minDist = 0.0;
    double maxDist = getOrbitFastValue(std::complex<double>(-2.0, -1.0));

    maxDist = std::max(maxDist, getOrbitFastValue(std::complex<double>(-2.0, 1.0)));
    maxDist = std::max(maxDist, getOrbitFastValue(std::complex<double>(1.0, 1.0)));
    maxDist = std::max(maxDist, getOrbitFastValue(std::complex<double>(1.0, -1.0)));

    minDist = std::min(minDist, getOrbitFastValue(std::complex<double>(-2.0, 1.0)));
    minDist = std::min(minDist, getOrbitFastValue(std::complex<double>(1.0, 1.0)));
    minDist = std::min(minDist, getOrbitFastValue(std::complex<double>(1.0, -1.0)));

    this->factor = (max_value - minDist) / (maxDist - minDist);
    this->translation = minDist;
}

double BitmapOrbit::precompute_distance(const int x, const int y) {
    if (*(bitmap->data(x, y, 0, 0)) == 0) {
        return 0;
    }

    int neighdist = 1;
    if (x > 0) {
        neighdist = (int) (distances[x - 1][y] - 5);
    } else if (y > 0) {
        neighdist = (int) (distances[x][y - 1] - 5);
    }

    for (int k = neighdist; k < 100; k++) {
        if (y - k > 0) {
            int i = 0;
            while (x - i > 0 && i < k) {
                if (*(bitmap->data(x - i, y - k, 0, 0)) == 0) {
                    return k;
                }
                i++;
            }

            i = 0;
            while (x + i < 900 && i < k) {
                if (*(bitmap->data(x + i, y - k, 0, 0)) == 0) {
                    return k;
                }
                i++;
            }
        }

        if (y + k < 600) {
            int i = 0;
            while (x - i > 0 && i < k) {
                if (*(bitmap->data(x - i, y + k, 0, 0)) == 0) {
                    return k;
                }
                i++;
            }

            i = 0;
            while (x + i < 900 && i < k) {
                if (*(bitmap->data(x + i, y + k, 0, 0)) == 0) {
                    return k;
                }
                i++;
            }
        }

        if (x - k > 0) {
            int i = 0;
            while (y - i > 0 && i < k) {
                if (*(bitmap->data(x - k, y - i, 0, 0)) == 0) {
                    return k;
                }
                i++;
            }

            i = 0;
            while (y + i < 600 && i < k) {
                if (*(bitmap->data(x - k, y + i, 0, 0)) == 0) {
                    return k;
                }
                i++;
            }
        }

        if (x + k < 900) {
            int i = 0;
            while (y - i > 0 && i < k) {
                if (*(bitmap->data(x + k, y + i, 0, 0)) == 0) {
                    return k;
                }
                i++;
            }

            i = 0;
            while (y + i < 600 && i < k) {
                if (*(bitmap->data(x + k, y + i, 0, 0)) == 0) {
                    return k;
                }
                i++;
            }
        }

    }

    return 100;
}
