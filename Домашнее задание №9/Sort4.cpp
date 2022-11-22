#include "pt4.h"
using namespace std;
#include <fstream>
//отсортировать массив по убыванию методом простых обменов. Отсортированную часть накаливать в конце массива.
//Отсортированную часть отделить от несортированной |.
void Bubble_sort(int* array, int N, string str) {
    ofstream fout(str);
    if (!fout.is_open()) {
        pt << "do not open";
    }
    else {
        int temp;
        int temp_size = N - 2;
        for (int step = 0; step < N - 1; ++step) {
            int swap = 0;
            for (int i = 0; i < N - 1 - step; ++i) {
                if (array[i] < array[i + 1]) {
                    temp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = temp;
                    swap = 1;
                }
            }
            if (swap == 0) break;
            for (int i = 0; i < N; ++i) {
                fout << array[i] << " ";
                if (i == temp_size) {
                    fout << "|" << " "; --temp_size;
                }

            }
            fout << "\n";
        }
        while (temp_size > -1) {
            for (int i = 0; i < N; ++i) {
                fout << array[i] << " ";
                if (i == temp_size) {
                    fout << "|" << " "; --temp_size;
                }
            }
            fout << "\n";
        }

    }
    fout.close();
}
void Solve()
{
    Task("Sort4");
    int N;
    string str;
    pt >> N;
    int* array = new int[N + 1];
    for (int i = 0; i < N; ++i) {
        pt >> array[i];
    }
    pt >> str;
    Bubble_sort(array, N, str);

}
