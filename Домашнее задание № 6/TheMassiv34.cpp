#include "pt4.h"
//TheMassiv34 Считать из текстового файла массив целых чисел, удалить из массива все числа кратные К, 
//размерность N на первом месте, К на втором. Вывести в новый текстовый файл исходный и результирующий массивы,
//1 - в первой строке, 2 - в третьей строке. После удаления в массиве есть хотя бы один элемент
using namespace std;
#include <fstream>
void Delete(int* array, int& N, int K) {
    int q = 0;
    for (int i = 0; i < N; ++i)
        if (array[i] % K != 0) {
            array[q] = array[i];
            ++q;
        }
    N = q;
}
void Solve()
{
    Task("TheMassiv34");
    string str, str1, number;
    int K, N, i = 0;
    int* array;
    pt >> str >> str1;
    ifstream fin(str);
    ofstream fout(str1);
    if (!fin.is_open() && !fout.is_open()) {
        pt << "do not open";
    }//запись в массив и запись исходного массива в другой файл
    else {
        fin >> number;
        N = stoi(number);
        fin >> number;
        K = stoi(number);
        array = new int[N];
        while (!fin.eof() && i < N) {
            fin >> number;
            fout << number << " ";
            array[i] = stoi(number);
            ++i;
        }
        fout << "\n" << "\n";
        Delete(array, N, K);
        for (int i = 0; i < N; ++i) {
            fout << array[i] << " ";
        }
    }
    fout.close();
    fin.close();

}