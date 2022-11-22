#include "pt4.h"
using namespace std;
#include <fstream>
//В текстовом файле c именем FN1 дана домашняя работа третьеклассника в формате : <операнд><знак> < операнд >= <ответ> 
//В качестве операндов используются не более, чем трехзначные натуральные числа, в качестве знаков операций используются умножить('*') и разделить(':').
//Проверьте работу третьеклассника, записав эти же примеры в выходной файл с именем FN2, указывая после неверно решенных примеров знак '!'
void Solve()
{
    Task("Five4");
    string str, str1, str2, number, sign;
    int K, N, Sum, res, i = 0;
    pt >> str2 >> str1;
    ifstream fin(str2);
    ofstream fout(str1);
    if (!fin.is_open() && !fout.is_open()) {
        pt << "do not open";
    }
    else {
        fin >> number;
        do {
            str = "";
            for (i = 0; number[i] != '*' && number[i] != ':'; ++i) {
                str += number[i];
            }
            //первое число

            sign = number[i];
            N = stoi(str);
            //знак
            str = "";
            for (++i; number[i] != '='; ++i) {
                str += number[i];
            }
            K = stoi(str);
            //второе число
            str = "";
            for (++i; i < number.size(); ++i) {
                str += number[i];
            }

            Sum = stoi(str);
            //результат
            if (sign == "*")res = N * K;
            else res = N / K;
            if (res == Sum) {
                fout << number << "\n";
            }
            else {
                number.push_back('!');
                fout << number << "\n";
            }
            fin >> number;
        } while (!fin.eof());

    }
    fout.close();
    fin.close();
}
