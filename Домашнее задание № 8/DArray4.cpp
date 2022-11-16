#include "pt4.h"
using namespace std;
//DArray4.Задана квадратичная матрица, найти транспонированную матрицу и проверить симметричность относительно главной диагонали
void Solve()
{
    Task("DArray4");
    int num, temp;
    int j = 1, l = 0, k = 0, i = 1;
    bool temp1 = true;
    pt >> num;
    int** array = new int* [num];
    for (int i = 0; i < num; i++)
        array[i] = new int[num];//создание

    for (int i = 0; i < num; ++i)
        for (int j = 0; j < num; ++j)
            pt >> array[i][j];//заполнение

    for (; i < num; ++i) {
        for (; j < num && i < num; ++j) {
            temp = array[k][j];
            array[k][j] = array[i][l];
            array[i][l] = temp;
            ++i;
        }
        ++k;
        ++l;
        i = k;
        j = l + 1;
    }//Транспонирование матрицы

    for (i = 1, k = 0, l = 0; i < num; ++i) {
        for (j = 1; j < num && i < num; ++j) {
            if (array[k][j] != array[i][l]) {
                temp1 = false;
                break;
            }
        }
        if (array[k][j] != array[i][l]) {
            break;
        }
        ++k;
        ++l;
        i = k;
        j = l + 1;
    }
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j)
            pt << array[i][j];
    }//вывод
    pt << temp1;

}
