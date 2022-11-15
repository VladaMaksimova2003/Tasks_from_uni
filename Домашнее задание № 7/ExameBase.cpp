#include <iostream>
#include <fstream>
#include <iomanip>
#include "pt4exam.h"
using namespace std;
//Дана строка, содержащая пробелы. Найдите в ней самое длинное слово, выведите это слово. Если таких слов несколько, выведите первое из них.
// Для ввода используйте поток cin
// Для вывода используйте поток cout
void Solve()
{
    Task("ExamBase97");
    int k = 0;
    string s, result;
    getline(cin, s);
    s.insert(0, 1, ' ');
    s += " ";
    int p = s.find(" "), p1;
    while (p + 1) {
        p1 = s.find(" ", p + 1);
        if (p1 - p > k) {
            k = p1 - p;
            result = s.substr(p + 1, p1 - p - 1);
        }
        p = p1;
    }
    cout << result;
}