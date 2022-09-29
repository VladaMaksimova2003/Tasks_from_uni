#include <iostream>
#include <cmath>
using namespace std;
void main()
{
	setlocale(LC_ALL, "Russian");
	int N;
	float x, sum, result, a;
	cout << "Введите целое число n \n";
	cin >> N;
	do {
		cout << "Введите вещественное число не больше 1 и не меньше -1\n";
		cin >> x;
	} while (abs(x) > 1);
	sum = x;
	for (int i = 2; i <= N; ++i) {
		a = pow(x, i);
		if (i % 2 == 0) {
			sum += (a / -i);
		}
		else
			sum += (a / i);
	}
	result = log1p(x);
	cout << "Сумма " << N << " первых членов ряда:" << sum << endl;
	cout << "Значение  функции в точке x:" << result;
}