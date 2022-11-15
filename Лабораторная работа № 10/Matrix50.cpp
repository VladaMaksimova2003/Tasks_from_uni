#include <iostream>
using namespace std;
//Matrix50. Дана матрица размера M × N. Преобразовать матрицу, поменяв местами минимальный и максимальный элемент в каждом столбце.
int main()
{
	setlocale(LC_ALL, "ru");
	int m, n, k, l;
	int min = INT_MAX, max = INT_MIN;
	do {
		cout << "Введите положительные значения для m, n" << endl;
		cin >> m >> n;
	} while (m < 0 || n < 0);

	int** array = new int* [m];
	for (int i = 0; i < m; i++)
		array[i] = new int[n];//создание

	cout << "Введите значения в массив array" << endl;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> array[i][j];//заполнение
	cout << "Вывод массива " << endl;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			cout << array[i][j] << " ";
		cout << endl;
	}//вывод

	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < m; ++i) {
			if (array[i][j] > max) {
				max = array[i][j]; k = i;
			}
			if (array[i][j] < min) {
				min = array[i][j];
				l = i;
			}
		}
		array[k][j] = min;
		array[l][j] = max;
		min = INT_MAX; max = INT_MIN;

	}//счет
	cout << "Вывод преобразованного массива " << endl;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			cout << array[i][j] << " ";
		cout << endl;
	}//вывод

	for (int i = 0; i < m; i++) {
		delete[] array[i];
	}
	delete[] array;//удаление
}