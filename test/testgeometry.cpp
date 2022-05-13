#include <cstdlib>
#include <ctest.h>
#include <fstream>
#include <geometrylib/intersects.h>
#include <geometrylib/perimeter.h>
#include <geometrylib/square.h>
#include <geometrylib/stringCollapse.h>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

CTEST(calculate_perimeter, test_true)
{
    double a = 2.5;
    const double exp = 2 * a * M_PI;
    double real = calculate_perimeter(a);
    ASSERT_DBL_NEAR(exp, real);
}

CTEST(calculate_square, test_true)
{
    double a = 2.5;
    const double exp = a * a * M_PI;
    double real = calculate_square(a);
    ASSERT_DBL_NEAR(exp, real);
}
