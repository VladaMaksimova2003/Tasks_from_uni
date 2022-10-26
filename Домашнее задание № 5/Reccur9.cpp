#include "pt4.h"
using namespace std;
void rec(int N, int a, float& S) {
    if (N > 0) {
        rec(--N, a * 2, S += a);
    }
}
void Solve()
{
    Task("Reccur9");
    int a = 1, N;
    float S = 0;
    pt >> N;
    rec(N, a, S);
    pt << S;
}
//Написать рекурсивную функцию для вычисления суммы:
//S = 1 + 2 + 4 + 8 + 16 + ..., содержащей N первых членов
//(N - натуральное число, N < 20, S - вещественное).
