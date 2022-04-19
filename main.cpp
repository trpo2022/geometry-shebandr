#include <fstream>
#include <iostream>
#include <string>

using namespace std;
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
