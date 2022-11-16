#include "pt4.h"
using namespace std;
//в думерном массиве размерностью n*m, среди элементов могут быть совпадающе,
//определить наименьшее и наибольшее значение, индексы первого и последнего 
// минимального и индексы первого и последнего максимального элементов
void Solve()
{
    Task("DArray14");
    int n, m, temp;
    int a[10];//для вывода данных
    a[0] = INT_MIN, a[5] = INT_MAX;
    pt >> n >> m;
    int** array = new int* [n];
    for (int i = 0; i < n; i++)
        array[i] = new int[m];//создание

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            pt >> array[i][j];//заполнение
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (array[i][j] > a[0]) {
                a[0] = array[i][j];
                a[1] = i + 1;
                a[2] = j + 1;
            }
            if ((array[i][j] == a[0])) {
                a[3] = i + 1;
                a[4] = j + 1;
            }
            if (array[i][j] < a[5]) {
                a[5] = array[i][j];
                a[6] = i + 1;
                a[7] = j + 1;
            }
            if ((array[i][j] == a[5])) {
                a[8] = i + 1;
                a[9] = j + 1;
            }
        }

    }
    for (int i = 0; i < 10; ++i)
        pt << a[i];

    for (int i = 0; i < n; i++) {
        delete[] array[i];
    }
    delete[] array;//удаление
}
