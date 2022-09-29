#include "pt4.h"
#include <fstream>
using namespace std;

void Solve()
{
    Task("TextFile19");
    string a = "";
    bool r = true;
    ifstream fin;
    fin.open("d.txt");
    if (!fin.is_open()) {
        pt << "do not open";
    }
    else {
        string str1 = "";
        string str = "";
        fin >> a;
        fin >> str1;
        while (!fin.eof()) {
            fin >> str;
            if (str1.size() != str.size()) {
                r = false;
                break;
            }

        }
    }
    pt << r;
    fin.close();
}