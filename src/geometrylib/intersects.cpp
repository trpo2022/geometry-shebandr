#include <cmath>
#include <geometrylib/intersects.h>
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
    double distanceObs = sqrt((distanceX * distanceX) + (distanceY * distanceY));
    if (distanceObs > firstR + secondR || distanceObs < abs(firstR - secondR)) {
        return 0;
    } else if (distanceObs == firstR + secondR) {
        return 1;
    } else if (distanceObs < firstR + secondR) {
        return 2;
    }
    return 3;
}
