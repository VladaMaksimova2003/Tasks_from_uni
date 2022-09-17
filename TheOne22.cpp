#include "pt4.h"
using namespace std;

void Solve()
{
    Task("TheOne22");
    int X, Y, a;
    pt >> a >> X >> Y;
    switch (a) {
    case 1:
        pt << X + Y;
        break;
    case 2:
        pt << X - Y;
        break;
    case 3:
        pt << X * Y;
        break;
    case 4:
        pt << X / Y;
        break;
    case 5:
        pt << X % Y;
        break;
    }
}
