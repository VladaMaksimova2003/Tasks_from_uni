#include <iostream>
using namespace std;
#define PI 3.1415
void main()
{
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    if (c * c == a * a + b * b && (c > 0 && a>0 && b>0)) {
        cout << "right triangle";
    }else  cout << " non right triangle";
    // тесты для проверки прямоугольного треугольника: (3,4,5), (6,8,10), (5,12,13);
    // если треугольник не прямоугольный: (2,5,10), (100,12,-300), (1,0,1), (0,0,0);
}