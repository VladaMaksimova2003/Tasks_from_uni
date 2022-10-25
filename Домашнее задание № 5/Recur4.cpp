#include "pt4.h"
#include <locale.h>
using namespace std;
//Recur4°.Описать рекурсивную функцию Fib1(N) целого типа, вычисляющую 
//N - й элемент последовательности чисел Фибоначчи(N — целое число) :
//F1 = F2 = 1, FK = FK−2 + FK−1, K = 3, 4, … .
//С помощью этой функции найти пять чисел Фибоначчи с данными номерами, и 
//вывести эти числа вместе с количеством рекурсивных вызовов функции Fib1, потребовавшихся для их нахождения.
int fib(int n, int& count)
{
    count++;
    if (n <= 2) {
        return 1;
    }
    return fib(n - 1, count) + fib(n - 2, count);
}

void Solve()
{
    int N[5];
    int count = 0, result;
    setlocale(LC_ALL, "Rus");
    Task("Recur4");
    for (int i = 0; i < 5; ++i) {
        pt >> N[i];
    }
    for (int i = 0; i < 5; ++i) {
        result = fib(N[i], count);
        pt << result << count;
        count = 0;
    }

}