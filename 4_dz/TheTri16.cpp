#include "pt4.h"
#include <string> 
using namespace std;
int trans10(int x, int p) {
    int z10 = 0, i = 0;
    while (x) {
        z10 += (x % 10) * pow(p, i);
        ++i;
        x /= 10;
    }
    return z10;
}
int transp(int x, int p) {
    int z10 = 0, j = 0;
    while (x)
    {
        z10 += (x % p) * pow(10.0, j);
        ++j;
        x /= p;

    }
    return z10;
}
int sub(int x, int y, int p) {
    int z = trans10(x, p) - trans10(y, p);

    return transp(z, p);
}
void Solve()
{
    int x, y, p;
    Task("TheTri16");
    pt >> x >> y >> p;
    pt << sub(x, y, p);
}