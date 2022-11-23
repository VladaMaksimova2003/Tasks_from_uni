#include "pt4.h"
using namespace std;
#include <fstream>
#include <iostream>
#include <algorithm>
#include <functional>
//Отсортировать данные по ключу, баллы по убыванию, фамилия по возрастанию. Использовать Шейкер-сортировку.
//Выровнить по столбацам. 15 позиций под фамилию, 3 под баллы. Фамилию по левому краю, баллы по правому 
void sort_shaker(vector <string>& name_vector, vector <string>& grade_vector, int n, int left, int right) {

    int j, i = 0, k = n - 1;
    string temp;
    do {
        for (j = left; j <= right; ++j)
            if (grade_vector[j - 1] < grade_vector[j]) {
                temp = name_vector[j - 1];
                name_vector[j - 1] = name_vector[j];
                name_vector[j] = temp;
                temp = grade_vector[j - 1];
                grade_vector[j - 1] = grade_vector[j];
                grade_vector[j] = temp;
                k = j;
            }
        right = k - 1;
        for (j = right; j >= left; --j)
            if (grade_vector[j - 1] < grade_vector[j]) {
                temp = name_vector[j - 1];
                name_vector[j - 1] = name_vector[j];
                name_vector[j] = temp;
                temp = grade_vector[j - 1];
                grade_vector[j - 1] = grade_vector[j];
                grade_vector[j] = temp;
                k = j;
            }
        left = k + 1;
    } while (left <= right);

}
void sort_shaker_string(vector <string>& name_vector, int left, int right) {

    int j, i = 0, k = right - 1;
    string temp;
    do {
        for (j = left; j <= right; ++j) {

            if (name_vector[j - 1][i] - '0' > name_vector[j][i] - '0') {
                temp = name_vector[j - 1];
                name_vector[j - 1] = name_vector[j];
                name_vector[j] = temp;
                k = j;

            }
            if (name_vector[j - 1][i] - '0' == name_vector[j][i] - '0')
                do {
                    ++i;
                    if (name_vector[j - 1][i] - '0' > name_vector[j][i] - '0') {
                        temp = name_vector[j - 1];
                        name_vector[j - 1] = name_vector[j];
                        name_vector[j] = temp;
                        k = j;
                        break;
                    }

                } while (name_vector[j - 1][i] - '0' == name_vector[j][i] - '0');
                i = 0;
        }

        right = k - 1;
        for (j = right; j >= left; --j) {

            if (name_vector[j - 1][i] - '0' > name_vector[j][i] - '0') {
                temp = name_vector[j - 1];
                name_vector[j - 1] = name_vector[j];
                name_vector[j] = temp;
                k = j;

            }
            if (name_vector[j - 1][i] - '0' == name_vector[j][i] - '0')
                do {
                    ++i;
                    if (name_vector[j - 1][i] - '0' > name_vector[j][i] - '0') {
                        temp = name_vector[j - 1];
                        name_vector[j - 1] = name_vector[j];
                        name_vector[j] = temp;
                        k = j;
                        break;
                    }

                } while (name_vector[j - 1][i] - '0' == name_vector[j][i] - '0');
                i = 0;
        }
        left = k + 1;
    } while (left <= right);

}
void Solve()
{
    Task("Five14");
    string str1, str2;
    int n = 0, count = 0;
    pt >> str1 >> str2;
    ifstream fin(str1);
    ofstream fout(str2);
    int array[10];
    int i = 0, j = 0;
    if (!fin.is_open() && !fout.is_open()) {
        pt << "do not open";
    }
    else {
        vector <string> name_vector;
        vector <string> grade_vector;
        fin >> str1;
        while (!fin.eof()) {
            name_vector.push_back(str1);
            fin >> str1;
            grade_vector.push_back(str1);
            fin >> str1;

        }
        int count = 0;
        n = name_vector.size();
        int left = 1;
        int right = n - 1;
        int min = 0;
        for (int i = 0; i < 10; ++i)
            array[i] = 0;
        sort_shaker(name_vector, grade_vector, n, left, right);
        for (int i = 0; i < grade_vector.size(); ++i) {
            if (grade_vector[i] == "9")++array[0];
            else if (grade_vector[i] == "9")++array[0];
            else if (grade_vector[i] == "8")++array[1];
            else if (grade_vector[i] == "7")++array[2];
            else if (grade_vector[i] == "6")++array[3];
            else if (grade_vector[i] == "5")++array[4];
            else if (grade_vector[i] == "4")++array[5];
            else if (grade_vector[i] == "3")++array[6];
            else if (grade_vector[i] == "2")++array[7];
            else if (grade_vector[i] == "1")++array[8];
            else ++array[9];
        }
        for (int i = 0; i < 10; ++i) {
            if (array[i] > 1) {
                /*sort(name_vector.begin() + count, name_vector.begin() + array[i] + count);*/
                sort_shaker_string(name_vector, count + 1, array[i] - 1 + count);
            }
            count += array[i];
        }


        do {
            count = name_vector[i].size();
            fout << name_vector[i];
            for (j = 0; j < 17 - count; ++j) fout << " ";
            fout << grade_vector[i] << "\n";
            --n;
            ++i;
        } while (n);
    }
    fout.close();
    fin.close();
}
