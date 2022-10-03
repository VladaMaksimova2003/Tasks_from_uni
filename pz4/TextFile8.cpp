#include "pt4.h"
#include <fstream>
using namespace std;
void Solve()
{
    Task("TextFile8");
    string number = " ";
    int min = 0, max = 0, res;
    ifstream fin;
    fin.open("d.num");
    if (!fin.is_open()) {
        pt << "do not open";
    }
    else {
        fin >> number;
        res = stoi(number);
        min = max = res;
        if (res < min)   min = res;
        if (res > max)   max = res;

        while (!fin.eof()) {
            fin >> number;
            res = stoi(number);
            if (res < min)   min = res;
            if (res > max)   max = res;

        }

    }
    pt << max - min;

    fin.close();
}