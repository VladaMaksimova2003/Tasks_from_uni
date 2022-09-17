#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.1415

void main()
{
	setlocale(LC_ALL, "Russian");
	float number = 0, result = 0;
	cout << "Вычисление площади круга по длине окружности: " << endl << endl;
	cout << "Введите длину окружности (см) -> ";
	cin >> number;
	result = number * number / 4 / PI;
	cout << "Площадь круга " << result << " кв.см.";
}