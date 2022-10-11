#include "pt4.h"
#include <fstream>
using namespace std;
int Length(int x, int x1, int y, int y1) {
    if (x1 > x) return sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
    return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
}
void Solve()
{
    Task("TheTri4");
    string number = " ";
    int x = 0, x1 = 0, y = 0, y1 = 0, res, length = INT_MAX, i = 1, n = 0;
    ifstream fin;
    fin.open("d.otr");
    if (!fin.is_open()) {
        pt << "do not open";
    }
    else {
        fin >> number;
        fin >> number;
        x = stoi(number);
        fin >> number;
        y = stoi(number);
        fin >> number;
        x1 = stoi(number);
        fin >> number;
        y1 = stoi(number);
        while (!fin.eof()) {
            res = Length(x, x1, y, y1);
            if (length > res) { length = res; n = i; }
            ++i;
            fin >> number;
            x = stoi(number);
            fin >> number;
            y = stoi(number);
            fin >> number;
            x1 = stoi(number);
            fin >> number;
            y1 = stoi(number);
        }

    }
    pt << n;

    fin.close();
}