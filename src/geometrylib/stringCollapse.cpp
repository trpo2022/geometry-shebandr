#include <geometrylib/stringCollapse.h>
#include <iostream>
#include <string>
using namespace std;
int stringCollapse(string line, string* Slices, int k)
{
    int q = 0;
    string slice;
    for (size_t i = 0; i < line.length() - 1; i++) {
        if (line[i] == ' ' || line[i] == ')' || line[i] == '('
            || line[i] == ',') {
            i++;
        } else {
            q = 0;
            slice = "";

            while (line[i + q] != ' ' && line[i + q] != '('
                   && line[i + q] != ')' && line[i + q] != ',') {
                slice += line[i + q];

                q++;
            }
            Slices[k] = slice;
            k++;
            i += q;
        }
    }
    cout << strtof(Slices[k-1].c_str(), nullptr)  << endl;
    if (strtof(Slices[k-1].c_str(), nullptr) < 0) {
        cout << "radius can't be negative" << endl;
        return -1;
    }
    q += 4;
    return k;
}
