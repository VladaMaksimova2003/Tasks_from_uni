//Recur8.Описать рекурсивную функцию RootK(X, K, N) вещественного типа, 
//находящую приближенное значение корня K - й степени из числа X по формуле :
//Y0 = 1, YN + 1 = YN −(YN − X / (YN)K−1) / K,
//где YN обозначает RootK(X, K, N) при фиксированных X и K.Параметры функции : 
//X(> 0) — вещественное число, K(> 1) и N(> 0) — целые.С помощью функции RootK найти для данного числа X приближенные значения его корня K - й 
//степени при шести данных значениях N.
#include <iostream>
#include <cmath>
using namespace std;
float RootK(float X, int K, int N) {
	if (!N) return 1;
	return RootK(X, K, N - 1) - (RootK(X, K, N - 1) - X / pow(RootK(X, K, N - 1), K - 1)) / K;
}
int main() {
	setlocale(LC_ALL, "ru");
	int N, K;
	float X;
	do {
		cout << "Введите X(> 0): ";
		cin >> X;
		cout << "Введите степень K(> 1): ";
		cin >> K;
	} while (X <= 0 || K <= 1);
	for (int i = 0; i < 6; ++i) {
		do {
			cout << "Введите 6 значений N(> 0): " << endl;
			cin >> N;
		} while (N < 0);
		cout << "Приближенное значение " << RootK(X, K, N) << endl;
	}
}