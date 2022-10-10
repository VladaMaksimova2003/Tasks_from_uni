#include <iostream>
#include <cmath>
float  Ln1(float x, float e) {
	float ln = x, x1 = x * x;
	for (int i = 1; abs(x1) / (i + 1) > e; ++i) {
		if (i % 2)
			ln -= x1 / (i + 1);
		else
			ln += x1 / (i + 1);
		x1 *= x;
	}
	return ln;
}
int main() {
	setlocale(LC_ALL, "Russian");
	float x, e;
	for (int i = 0; i < 6; ++i) {
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
		std::cout << "Значение стандартной функции:" << log1p(x) << std::endl;
		std::cout << "Полученное значение:" << Ln1(x, e) << std::endl;
	}
}