#include <fstream>
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
    ifstream input(

            "input.txt"); // окрываем файл
                          // для чтения
    if (input.is_open()) {
        int w = 0;
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
                    std::cout << slice << std::endl;
                }
            }
            if (Slices[w] == "circle") {
                std::cout << "it's circle" << std::endl;
                std::cout << "perimetr: "
                          << calculate_perimeter(stof(Slices[w + 3]))
                          << std::endl;
                std::cout << "ploshad: "
                          << calculate_square(stof(Slices[w + 3])) << std::endl;
            } else {
                std::cout << "error, it's not a circle" << std::endl;
                return 1;
            }

            w += 4;
        }
    } else {

    }
    input.close(); // закрываем файл
    std::cout << "End of program" << std::endl;
    return 0;
}
