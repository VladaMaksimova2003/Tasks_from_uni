#include "pt4.h"
#include <iostream>
#include <algorithm>
using namespace std;
//заменить все пробелы символом #, а в конце вставить !
void Solve()
{
    Task("str16");
    string s;
    pt >> s;
    char ch = '!';
    s.insert(s.length(), 1, ch);
    replace(s.begin(), s.end(), ' ', '#');
    pt << s;

}