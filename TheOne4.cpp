#include "pt4.h"
#include "cmath"
using namespace std;
void Solve()
{
    Task("TheOne4");
    bool r;
    float x, y;
    pt >> x >> y;
    r = sqrt(x * x + y * y) < 2 && (x == 0 || (x < 0 && y / x <= -1) || (x > 0 && y / x >= 0.5));
    pt << r;
}
