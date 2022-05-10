#include <cmath>
#include <iostream>
#include <string>
using namespace std;
int intersects(
        float firstX,
        float firstY,
        float firstR,
        float secondX,
        float secondY,
        float secondR)
{
    float distanceX = abs(firstX - secondX);
    float distanceY = abs(firstY - secondY);
    float distanceObs = sqrt((distanceX * distanceX) + (distanceY * distanceY));
    if (distanceObs > firstR + secondR || distanceObs < abs(firstR - secondR)) {
        return 0;
    } else if (distanceObs == firstR + secondR) {
        return 1;
    } else if (distanceObs < firstR + secondR) {
        return 2;
    }
}