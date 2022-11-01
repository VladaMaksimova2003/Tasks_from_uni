#include "pt4.h"
using namespace std;
// TheMassiv18 В массиве найти значения двух наибольших элементов и выевсти их в порядке возрастания. 
//Гарантируется что в массиве есть хотя бы два различных элемента. 
//Запрещается проходить по массиву более одного раза.
void input(int* array, int N) {
    for (int i = 0; i < N; ++i) {
        pt >> array[i];
    }
}
void Max(int* array, int& max1, int N, int& max2) {
    for (int i = 1; i < N; ++i) {
        if (array[i] > max1) {
            max2 = max1;
            max1 = array[i];
        }
        if (array[i] < max1 && max2 < array[i]) {
            max2 = array[i];
        }
    }
}
void Solve()
{
    Task("TheMassiv18");
    int N, i = 0;
    pt >> N;
    int* array = new int[N];
    input(array, N);
    int max1 = array[i];
    int max2 = 0;
    Max(array, max1, N, max2);
    pt << max2 << max1;
    delete[] array;
}
