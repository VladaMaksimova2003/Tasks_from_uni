#include <iostream>
#include <cmath>
float binpow(float& x) {
	x = x * x;
	return x;
}
int factorial(int& i) {
	if (i == 1) return i *= 2;
	i = i * (i + 1) * (i + 2);
	return i;
}
float Result(float x, float e) {
	float sum = 1;
	int i = 1;
	float a = 0, k = 1;
	do {
		k = factorial(i);
		a = binpow(x);
		k = a / k;
		if (abs(k) < e) { break; }
		sum += k;
	} while (k);
	return sum;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	float x, e, sum;
	do {
		std::cout << "Введите x\n";
		std::cin >> x;
		if (abs(x) >= 1) std::cout << "Неправильный ввод данных\n";
	} while (abs(x) >= 1);
	do {
		std::cout << "Введите e\n";
		std::cin >> e;
		if (e <= 0) std::cout << "Неправильный ввод данных\n";
	} while (e <= 0);
	std::cout << "Значение стандартной функции:" << cosh(x) << std::endl;
	sum = Result(x, e);
	std::cout << "Полученное значение:" << sum << std::endl;

}