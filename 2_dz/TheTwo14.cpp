#include "pt4.h"
using namespace std;

void Solve()
{
    Task("TheTwo14");
    float result = 0;
    int N;
    pt >> N;
    for (int i = 5; i <= N; ++i) {
        result += pow(float(i), -N);
    }
    pt << result;
}
