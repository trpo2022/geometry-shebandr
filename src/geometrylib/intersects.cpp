#include <cmath>
#include <geometrylib/intersects.hpp>
#include <iostream>
#include <string>
using namespace std;
int intersects(
        double firstX,
        double firstY,
        double firstR,
        double secondX,
        double secondY,
        double secondR)
{
    double distanceX = abs(firstX - secondX);
    double distanceY = abs(firstY - secondY);
    double distanceAbs
            = sqrt((distanceX * distanceX) + (distanceY * distanceY));
    if (distanceAbs > firstR + secondR || distanceAbs < abs(firstR - secondR)) {
        return 0;
    } else if (distanceAbs == firstR + secondR) {
        return 1;
    } else if (distanceAbs < firstR + secondR) {
        return 2;
    }
    return 3;
}
