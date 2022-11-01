#include "pt4.h"
using namespace std;
// TheMassiv24 Дан массив, считая, что  нумерация начинается с 0, 
//найти максимальный элемент из элементов с нечетными номерами.
//Использвать указатели для доступа к элементу
void input(int* array, int N) {
    for (int i = 0; i < N; ++i) {
        pt >> *(array + i);
    }
}
void Max(int* array, int N, int& max) {
    for (int i = 3; i < N; i += 2)
        if (max < *(array + i)) {
            max = *(array + i);
        }
}
void Solve()
{
    Task("TheMassiv24");
    int N, max;
    pt >> N;
    int* array = new int[N];
    input(array, N);
    max = *(array + 1);
    Max(array, N, max);
    pt << max;
    delete[] array;
}
