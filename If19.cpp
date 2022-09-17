#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;
	if (a == b && a == c) {
		cout << 4;
	}
	else if (a == b && a == d) {
		cout << 3;
	}
	else if (a == d && a == c) {
		cout << 2;
	}
	else if (b == d && b == c) {
		cout << 1;
	}
	else cout << "Неправильный ввод";

}