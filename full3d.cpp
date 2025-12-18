#include "src/header.hpp"
#include "src/Xmath.hpp"

constexpr int constY = 31;
constexpr int constX = 2 * constY;

void drawLine(char table[constY][constX], int xa, int ya, int xb, int yb) {
    double dx = xb - xa;
    double dy = yb - ya;

    double steps = std::max(std::abs(dx), std::abs(dy));

    if (steps == 0) {
        if(xa >= 0 && xa < constX && ya >= 0 && ya < constY)
             table[ya][xa] = 'o';
        return;
    }

    double xInc = dx / steps;
    double yInc = dy / steps;

    double x = xa;
    double y = ya;

    for (int i = 0; i <= steps; i++) {
        int rX = Xmath::round(x);
        int rY = Xmath::round(y);
        table[rY + constY][rX + constX] = 'o';
        x += xInc;
        y += yInc;
    }
}
