#include <iostream>
using namespace std;
void time(int& m, int& n, int& k) {
	do {
		cout << "Введите часы: ";
		cin >> m;
		cout << "Введите минуты: ";
		cin >> n;
		cout << "Введите секунды: ";
		cin >> k;
		if (m > 23 || m < 0 && n < 0 || n>59 && k < 0 || k > 59) cout << "Неправильный ввод\n";
	} while (m > 23 || m < 0 && n < 0 || n>59 && k < 0 || k > 59);
}
int Sec(int m, int n, int k) {
	return m * 3600 + n * 60 + k;
}
void Counting_time(int sec) {
	int h, m, s;
	h = sec / 3600;
	m = (sec - h * 3600) / 60;
	s = sec - h * 3600 - m * 60;
	if (h > 23) h -= 24;
	cout << "Полученнное время:" << h << ":" << m << ":" << s;

}
int main()
{
	int m = 0, n = 0, k = 0, p = 0, q = 0, r = 0;
	int sec_1, sec_2;
	setlocale(LC_ALL, "Russian");
	cout << "Введите текущее время " << endl;
	time(m, n, k);
	cout << "Текущее время - " << m << ":" << n << ":" << k << endl;
	sec_1 = Sec(m, n, k);
	cout << "Введите время для нахождения" << endl;
	time(p, q, r);
	cout << "Время - " << p << ":" << q << ":" << r << endl;
	sec_2 = Sec(p, q, r);
	sec_2 += sec_1;
	Counting_time(sec_2);
	system("pause");
}

