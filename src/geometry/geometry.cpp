#include <cstdlib>
#include <fstream>
#include <geometrylib/intersects.h>
#include <geometrylib/perimeter.h>
#include <geometrylib/square.h>
#include <geometrylib/stringCollapse.h>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main()
{
    string line;
    string Slices[50];
    ifstream input("input.txt");

    if (input.is_open()) {
        int k = 0;
        while (getline(input, line)) {
            k = stringCollapse(line, Slices, k);
            if(k==-1){
                return 0;
            }
        }
        for (int w = 0; w < k; w += 4) {
            cout << "it's circle" << endl;
            cout << "on coordinates: " << Slices[w + 1] << " " << Slices[w + 2]
                 << endl;
            cout << "with radius: " << Slices[w + 3] << endl;
            cout << "perimeter: " << calculate_perimeter(stof(Slices[w + 3]))
                 << endl;
            cout << "ploshad: " << calculate_square(stof(Slices[w + 3]))
                 << endl;
            for (int z = w; z < k - 4; z += 4) {
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
    input.close();
    cout << "End of program" << endl;
    return 0;
}
