#include <iostream>
using namespace std;
#define PI 3.1415
void main()
{
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    if (c * c == a * a + b * b || a * a == c * c + b * b || b * b == a * a + c * c && (c > 0 && a > 0 && b > 0)) {
        cout << "right triangle";
    }
    else  cout << " non right triangle";
    // тесты для проверки прямоугольного треугольника: (3,4,5), (6,8,10), (12,5,13),(5,12,13), (13,12,5);
    // если треугольник не прямоугольный: (2,5,10), (100,12,-300), (1,0,1), (0,0,0);
}