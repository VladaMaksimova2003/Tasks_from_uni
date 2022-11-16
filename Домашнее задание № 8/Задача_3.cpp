#include <iostream>
using namespace std;
//Написать программу для вычитания двух длинных целых чисел  
int main() {
    string temp, temp1, result = " ", temp2;
    int r = 0;
    char ch;
    cin >> temp >> temp1;
    if (temp.size() < temp1.size() || temp.size() == temp1.size() && temp[0] - '0' < temp1[0] - '0') {
        temp2 = temp;
        temp = temp1;
        temp1 = temp2;
        ch = '-';
    }
    while (temp.size() != temp1.size()) {
        if (temp.size() < temp1.size()) temp = "0" + temp;
        else temp1 = "0" + temp1;
    }
    for (int i = temp.size() - 1; i > -1; --i) {
        if (temp[i] < temp1[i] || temp[i] == temp1[i] && r == -1) {

            r = 10 + (temp[i] - '0') - (temp1[i] - '0') + r;
            result.insert(0, 1, r + '0');
            r = -1;
        }

        else {
            r = (temp[i] - '0') - (temp1[i] - '0') + r;
            result.insert(0, 1, r + '0');
            r = 0;
        }

    }
    if (result[0] == '0') {
        result.erase(0, 1);
    }
    if (ch == '-') {
        result.insert(0, 1, ch);
    }
    cout << result;
}