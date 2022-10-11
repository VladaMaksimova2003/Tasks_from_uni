#include "pt4.h"
using namespace std;

void Solve()
{
    Task("Minmax19");
    int N, k = 0;
    int min = INT_MAX;
    pt >> N;
    int* array = new int[N];
    for (int i = 0; i < N; ++i) {
        pt >> array[i];
        if (array[i] < min) {
            min = array[i]; k = 0;
        }
        if (array[i] == min) ++k;
    }
    pt << k;
}