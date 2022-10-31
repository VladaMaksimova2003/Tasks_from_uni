#include "pt4.h"
using namespace std;
//Array54°.Дан целочисленный массив A размера N.Переписать в новый целочисленный массив B все четные числа из 
//исходного массива(в том же порядке) и вывести размер полученного массива B и его содержимое.
void Solve()
{
    Task("Array54");
    int N, i = 0, j = 0;
    pt >> N;
    int* A = new int[N];
    int* B = new int[N];
    for (; j < N; ++j) {
        pt >> A[j];
        if (A[j] % 2 == 0) {
            B[i] = A[j];
            ++i;
        }
    }
    pt << i;
    for (int k = 0; k < i; ++k) {
        pt << B[k];
    }
}

//or


void Solve()
{
    Task("Array54");
    int N, i = 0, j = 0, k = 0;
    pt >> N;
    int* A = new int[N];
    for (; j < N; ++j) {
        pt >> A[j];
        if (A[j] % 2 == 0) {
            ++i;
        }
    }
    int* B = new int[i];
    pt << i;
    for (j = 0; j < N; ++j) {
        if (A[j] % 2 == 0) {
            B[k] = A[j];
            pt << B[k];
            ++k;
        }
    }
}
