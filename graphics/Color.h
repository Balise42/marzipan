#ifndef MARZIPAN_COLOR_H
#define MARZIPAN_COLOR_H


class Color {
public:
    unsigned char R;
    unsigned char G;
    unsigned char B;

    Color(unsigned char R, unsigned char G, unsigned char B);
    Color();
};

bool operator==(Color lhs, Color rhs);

#endif //MARZIPAN_COLOR_H
