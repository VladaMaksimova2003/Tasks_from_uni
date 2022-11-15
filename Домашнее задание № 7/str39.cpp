#include "pt4.h"
using namespace std;
//вывести символы, которые встречаются только раз в том порядке, в котором они были, знаки препинания не считать 
void Solve()
{
    Task("str39");
    string s = " ";
    string result = "";
    map<char, int>myMap;
    pt >> s;
    for (char element : s) {
        ++myMap[element];
    }
    for (char element : s) {
        if (myMap.find(element)->second == 1 && element != ' ' && element != '.' && element != '!' && element != ',' && element != '?' && element != '-')
            result += element;
    }
    pt << result;
}