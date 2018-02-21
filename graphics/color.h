#ifndef MARZIPAN_COLOR_H
#define MARZIPAN_COLOR_H


class color {
public:
    unsigned char R;
    unsigned char G;
    unsigned char B;

    color(unsigned char R, unsigned char G, unsigned char B);
    color();
};

bool operator==(color lhs, color rhs);

#endif //MARZIPAN_COLOR_H
