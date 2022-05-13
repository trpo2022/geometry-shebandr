#include <cstdlib>
#include <ctest.h>
#include <fstream>
#include <geometrylib/intersects.hpp>
#include <geometrylib/perimeter.hpp>
#include <geometrylib/square.hpp>
#include <geometrylib/stringCollapse.hpp>
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

CTEST(intersects, touch)
{
    double a = 1, b = 1, c = 2, d = 1, e = 5, f = 2;
    const int exp = 1;
    double real = intersects(a, b, c, d, e, f);
    ASSERT_EQUAL(exp, real);
}

CTEST(intersects, intersect)
{
    double a = 1, b = 1, c = 2, d = 1, e = 5, f = 3;
    const int exp = 2;
    double real = intersects(a, b, c, d, e, f);
    ASSERT_EQUAL(exp, real);
}

CTEST(intersects, freeExternal)
{
    double a = 1, b = 1, c = 2, d = 1, e = 5, f = 1;
    const int exp = 0;
    double real = intersects(a, b, c, d, e, f);
    ASSERT_EQUAL(exp, real);
}

CTEST(intersects, freeInterior)
{
    double a = 1, b = 1, c = 20, d = 1, e = 5, f = 1;
    const int exp = 0;
    double real = intersects(a, b, c, d, e, f);
    ASSERT_EQUAL(exp, real);
}

CTEST(stringCollapse, testK)
{
    string line = "circle(3 2.9,5)";
    string Slices[50];
    int exp = 4;
    const int k = 0;
    int real = stringCollapse(line, Slices, k);
    ASSERT_EQUAL(exp, real);
}

CTEST(stringCollapse, testCircle)
{
    string line = "circle(3 2.9,5)";
    string Slices[50];
    int k = 0;
    stringCollapse(line, Slices, k);
    ASSERT_STR("circle", Slices[0].c_str());
}
CTEST(stringCollapse, testX)
{
    string line = "circle(3 2.9,5)";
    string Slices[50];
    int k = 0;
    stringCollapse(line, Slices, k);
    ASSERT_STR("3", Slices[1].c_str());
}
CTEST(stringCollapse, testY)
{
    string line = "circle(3 2.9,5)";
    string Slices[50];
    int k = 0;
    stringCollapse(line, Slices, k);
    ASSERT_STR("2.9", Slices[2].c_str());
}

CTEST(stringCollapse, testRad)
{
    string line = "circle(3 2.9,5)";
    string Slices[50];
    int k = 0;
    stringCollapse(line, Slices, k);
    ASSERT_STR("5", Slices[3].c_str());
}