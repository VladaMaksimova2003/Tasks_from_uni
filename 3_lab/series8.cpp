#include <iostream>
using namespace std;
void main()
{
    int N, a, size = 0;
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    cout << "Введите число: \n";
    cin >> N;
    do {
        cout << "Введите число из набора: \n";
        cin >> a;
        if (a % 2 == 0 && a != 0) { cout << "Число " << a << " четное" << endl; ++size; }
        --N;

    } while (N);
    cout << "Всего четных чисел - " << size << endl;
    system("pause");
    //тесты: 10(0, 11, 2, 3, 4, 15, 16, 7, 18, 9), 5(11, 333, 6666, 7, 909), 5(10, 2, 12, 444, 804);

}