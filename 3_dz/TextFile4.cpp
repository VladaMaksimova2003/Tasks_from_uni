#include "pt4.h"
#include <fstream>
using namespace std;

void Solve()
{
    Task("TextFile4");
    int n;
    pt >> n;
    int a = 0;
    int b = 1;
    ofstream fout;
    fout.open("d.tst");
    if (!fout.is_open()) {
        pt << "do not open";
    }
    else {
        for (int i = 0; i < n; i++)
        {
            a = a + b;
            b = a - b;
            fout << a << "\n";
        }
    }
    fout.close();
}