#include <iostream>
#include "fraction_division.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	int a, b, c, d, k, m;
	do {
		cout << "�������, ����������, ��������� ��������" << endl;
		cout << "������� �������� ����������: a, c, k" << endl;
		cin >> a >> c >> k;
		cout << "������� �������� ������������: b, d, m" << endl;
		cin >> b >> d >> m;
	} while (a == 0 || c == 0 || k == 0 || b == 0 || d == 0 || k == 0);
	Sokr(a, b);
	Sokr(c, d);
	Sokr(k, m);
	cout << "���������� �������� " << Div(a, b, c, d, k, m);
}
