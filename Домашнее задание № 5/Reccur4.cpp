#include "pt4.h"
using namespace std;
void max(int k, int& m) {
    int digit;
    if (k > 0) {
        digit = k % 10;
        if (digit > m) m = digit;
        max(k / 10, m);
    }
}
void Solve()
{
    Task("Reccur4");
    int n, m = 0;
    pt >> n;
    m = n % 10;
    max(n, m);
    pt << m;
}
//написать рекурсивынй алгоритм опредления максимальной цифры целого числа N
