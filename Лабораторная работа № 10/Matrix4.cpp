#include <iostream>
using namespace std;
//Matrix4.Даны целые положительные числа M, N и набор из N чисел.Сформировать матрицу размера M × N, 
//у которой в каждой строке содержатся все числа из исходного набора(в том же порядке).
int main()
{
	setlocale(LC_ALL, "ru");
	int m, n;

	do {
		cout << "Введите положительные значения для m, n" << endl;
		cin >> m >> n;
	} while (m < 0 || n < 0);
	cout << "Введите набор чисел из N чисел" << endl;
	int* s = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	int** array = new int* [m];
	for (int i = 0; i < m; i++)
		array[i] = new int[n];


	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			array[i][j] = s[j];

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			cout << array[i][j] << " ";
		cout << endl;
	}
	for (int i = 0; i < m; i++) {
		delete[] array[i];
	}
	delete[] array;
}