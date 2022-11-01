#include "pt4.h"
using namespace std;
//TheMassiv4 В массиве из N элементов найти S1 – сумму положительных элементов массива, расположенных после максимального элемента,
//и S2 – сумму отрицательных элементов массива, расположенных до максимального элемента(элементы различны между собой)
void input(int* array, int N) {
    for (int i = 0; i < N; ++i) {
        pt >> array[i];
    }
}
int Max(int* array, int N) {
    int i = 0, j = 0;
    int max = array[i];
    for (i = 1; i < N; ++i) {
        if (max < array[i]) {
            max = array[i];
            j = i;
        }
    }
    return j;
}
int Sum_min(int* array, int max) {
    int sum_min = 0;
    for (int i = 0; i < max; ++i) {
        if (array[i] < 0) {
            sum_min += array[i];
        }
    }
    return sum_min;
}
int Sum_max(int* array, int max, int N) {
    int sum_max = 0;
    for (int i = max + 1; i < N; ++i) {
        if (array[i] > 0) {
            sum_max += array[i];
        }
    }
    return sum_max;
}
void Solve()
{
    Task("TheMassiv4");
    int N, max, sum_min, sum_max;
    pt >> N;
    int* array = new int[N];
    input(array, N);
    max = Max(array, N);
    sum_min = Sum_min(array, max);
    sum_max = Sum_max(array, max, N);
    pt << sum_max << sum_min;
    delete[] array;
}
