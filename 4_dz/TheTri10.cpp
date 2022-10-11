#include "pt4.h"
using namespace std;
int Palindrom(int n) {
    int num = 0, s;
    s = n;
    while (n) {
        num = num * 10 + n % 10;
        n /= 10;
    }
    if (s == num) return num;
    return 0;
}
void Solve()
{
    Task("TheTri10");
    vector <int> vec;
    int a, b, five, four, three;
    pt >> a >> b;
    for (int i = a; i < b; ++i) {
        five = pow(i, 5);
        five = Palindrom(five);
        four = pow(i, 4);
        four = Palindrom(four);
        three = pow(i, 3);
        three = Palindrom(three);
        if (three != 0 || four != 0 || five != 0) vec.push_back(i);
    }
    if (vec.empty()) {
        pt << "No solution";
    }
    else
        for (int i = 0; i < vec.size(); i++) {
            pt << vec[i];
        }
}

