#include <fstream>
#include <iostream>
#include <string>
#define _USE_MATH_DEFINES 
#include <cmath>
using namespace std;

float calculate_plosh(float rad){
    return pow(rad, 2)*M_PI;
}

float calculate_perimetr(float rad){
    return 2*M_PI*rad;
}

int main()
{
    string line;
    string Slices[500];
    ifstream input("input.txt"); // окрываем файл для чтения
    if (input.is_open()) {
        int w = 0;
        int k = 0;
        while (getline(input, line)) {
            for (int i = 0; i < line.length() - 1; i++) {
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
            if (Slices[w] == "circle") {
                cout << "it's circle" << endl;
                cout << "perimetr: " << calculate_perimetr(stof(Slices[w+3])) << endl;
                cout << "ploshad: " << calculate_plosh(stof(Slices[w+3])) << endl;
            } else {
                cout << "error, it's not a circle" << endl;
                return 1;
            }

            w += 4;
        }
    }
    input.close(); // закрываем файл

    cout << "End of program" << endl;
    return 0;
}
