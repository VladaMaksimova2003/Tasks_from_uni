#include "pt4.h"
using namespace std;

void Solve()
{
    Task("TheTwo20");
    int N, min, number = 1, n = 1;
    pt >> N;
    min = N % 10;
    N /= 10;
    while (N != 0) {
        ++n;
        if (min > N % 10) {
            min = N % 10;
            number = n;
        }
        N /= 10;
    }
    pt << min << number;
}