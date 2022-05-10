#include <cstdlib>
#include <fstream>
#include <geometrylib/intersects.h>
#include <geometrylib/perimeter.h>
#include <geometrylib/square.h>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main()
{
    string line;
    string Slices[500];
    ifstream input("input.txt");

    if (input.is_open()) {
        int q = 0;
        int k = 0;
        while (getline(input, line)) {
            for (size_t i = 0; i < line.length() - 1; i++) {
                if (line[i] == ' ' || line[i] == ')' || line[i] == '('
                    || line[i] == ',') {
                    i++;
                } else {
                    int q = 0;
                    string slice = "";

                    while (line[i + q] != ' ' && line[i + q] != '('
                           && line[i + q] != ')' && line[i + q] != ',') {
                        slice += line[i + q];

                        q++;
                    }
                    Slices[k] = slice;
                    k++;
                    i += q;
                    cout << slice << endl;
                }
            }
            q += 4;
        }
        for (int w = 0; w < q; w += 4) {
            cout << "it's circle" << endl;
            cout << "perimeter: " << calculate_perimeter(stof(Slices[w + 3]))
                 << endl;
            cout << "ploshad: " << calculate_square(stof(Slices[w + 3]))
                 << endl;
            for (int z = w; z < q-4; z += 4) {
                if (Slices[w] == "circle") {
                    if ((intersects(
                                 strtof(Slices[w + 1].c_str(), nullptr),
                                 strtof(Slices[w + 2].c_str(), nullptr),
                                 strtof(Slices[w + 3].c_str(), nullptr),
                                 strtof(Slices[z + 1].c_str(), nullptr),
                                 strtof(Slices[z + 2].c_str(), nullptr),
                                 strtof(Slices[z + 3].c_str(), nullptr))
                         == 0)
                        && (Slices[w + 4] == "circle")) {
                        cout << w / 4 << " and " << (z / 4) + 1
                             << " not intersect" << endl;
                    } else if (
                            (intersects(
                                     strtof(Slices[w + 1].c_str(), nullptr),
                                     strtof(Slices[w + 2].c_str(), nullptr),
                                     strtof(Slices[w + 3].c_str(), nullptr),
                                     strtof(Slices[z + 1].c_str(), nullptr),
                                     strtof(Slices[z + 2].c_str(), nullptr),
                                     strtof(Slices[z + 3].c_str(), nullptr))
                             == 1)
                            && (Slices[w + 4] == "circle")) {
                        cout << w / 4 << " and " << (z / 4) + 1 << " touches "
                             << endl;
                    } else if (
                            (intersects(
                                     strtof(Slices[w + 1].c_str(), nullptr),
                                     strtof(Slices[w + 2].c_str(), nullptr),
                                     strtof(Slices[w + 3].c_str(), nullptr),
                                     strtof(Slices[z + 1].c_str(), nullptr),
                                     strtof(Slices[z + 2].c_str(), nullptr),
                                     strtof(Slices[z + 3].c_str(), nullptr))
                             == 2)
                            && (Slices[w + 4] == "circle")) {
                        cout << w / 4 << " and " << (z / 4) + 1 << " intersect"
                             << endl;
                    }
                } else {
                    cout << "error, it's not a circle" << endl;
                    return 1;
                }
            }
        }
    }
    input.close(); // закрываем файл
    cout << "End of program" << endl;
    return 0;
}
