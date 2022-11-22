#include "pt4.h"
using namespace std;
#include <fstream>
//Дано целое число X и текстовый файл c именем FileName. 
//В файле записан набор целых чисел, расположенных в невозрастающем порядке. 
// С помощью метода бинарного поиска определить количество вхождений числа X в исходном наборе.
//Чисел в исходном наборе не более 200.
int lower_bound(int* arr, int low,
    int high, int X)
{
    if (low > high) {
        return low;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] <= X) {
        return lower_bound(arr, low,
            mid - 1, X);
    }

    return lower_bound(arr, mid + 1,
        high, X);
}

int upper_bound(int* arr, int low,
    int high, int X)
{

    if (low > high)
        return low;

    int mid = low + (high - low) / 2;

    if (arr[mid] >= X) {
        return upper_bound(arr, mid + 1,
            high, X);
    }

    return upper_bound(arr, low,
        mid - 1, X);
}
void Solve()
{
    Task("Sort16");
    string str;
    int i = 0, x, n = 0;
    int* array = new int[200];
    pt >> str;
    pt >> x;
    ifstream fin(str);
    if (!fin.is_open()) {
        pt << "do not open";
    }
    else {
        do {
            fin >> array[i];
            ++i;
            ++n;
        } while (!fin.eof());

    }
    int lower = lower_bound(array, 0, n, x);
    int upper = upper_bound(array, 0, n, x);
    pt << upper - lower;
}
