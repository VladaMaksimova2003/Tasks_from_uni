#include "pt4.h"
using namespace std;

void Solve()
{
    Task("TheTwo9");
    int X, N, all = 0, N_day = 0;
    pt >> N >> X;
    all = X;
    N_day = X;
    for (int i = 2; i <= N; ++i) {
        N_day += i;
        all += N_day;
    }
    pt << N_day << all;
}