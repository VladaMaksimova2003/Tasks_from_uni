#include <iostream>
using namespace std;
//Matrix20.Дана матрица размера M × N.Для каждого столбца матрицы найти произведение его элементов.
int main()
{
	setlocale(LC_ALL, "ru");
	int m, n;
	long int res = 1;

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

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			cout << array[i][j] << " ";
		cout << endl;
	}//вывод

	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < m; ++i)
			res *= array[i][j];
		cout << "Полученные значения столбца " << j + 1 << ": " << res << endl;
		res = 1;
	}//счет


	for (int i = 0; i < m; i++) {
		delete[] array[i];
	}
	delete[] array;//удаление
}