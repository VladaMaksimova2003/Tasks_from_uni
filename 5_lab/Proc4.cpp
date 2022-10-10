#include "pt4.h"
using namespace std;
void trianglePS(float a, float& P, float& S) {
    P = 3 * a;
    S = a * a * sqrt(3) / 4;
}
void Solve()
{
    float a, P = 0, S = 0;
    Task("Proc4");
    for (int i = 0; i < 3; ++i) {
        pt >> a;
        trianglePS(a, P, S);
        pt << P << S;
    }

}
