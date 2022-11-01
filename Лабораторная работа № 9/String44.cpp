#include "pt4.h"
using namespace std;
//String44°.Дана строка, состоящая из русских слов, набранных заглавными буквами и разделенных пробелами
//(одним или несколькими).Найти количество слов, которые содержат ровно три буквы «А».
void Solve()
{
    Task("String44");
    string str;
    int count = 0;
    int _count = 0;
    pt >> str;
    for (int i = 0; i < str.size(); ++i) {
        while (str[i] != ' ' && i < str.size()) {
            if (str[i] == 'А') {
                ++count;
            }
            ++i;
        }
        if (count == 3) {
            ++_count;
        }
        count = 0;
    }
    pt << _count;
}