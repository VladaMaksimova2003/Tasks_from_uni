#include <iostream>
using namespace std;
void main()
{
    int a = 0, N;
    bool r = true;
    cin >> N;
    a = N % 10;

    do {
        N /= 10;
        if (a % 2 == 1) {
            cout << r;
            exit(0);
        }
        a = N % 10;

    } while (N);
    r = false;
    cout << r;
    // тесты для проверки: 100, 222, 234, 122, 333, 223;

}