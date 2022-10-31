//Array90.Дан массив размера N и целое число K(1 ≤ K ≤ N).Удалить из массива элемент с порядковым номером K.
#include <iostream>
#include <string>
using namespace std;
void input(int* array, int N) {
	for (int i = 0; i < N; ++i) {
		cin >> array[i];
	}
}
void output(int* array, int N) {
	for (int i = 0; i < N - 1; ++i) {
		cout << array[i];
	}
}
void Delete(int* array, int N, int K) {
	for (int i = K; i < N - 1; ++i)
		array[i] = array[i + 1];
}
int main() {
	setlocale(LC_ALL, "ru");
	int K, N;
	do {
		cout << "Введите размер массива, значение K (1 <= K <= N)" << endl;
		cin >> N >> K;
	} while (K < 1 || N < 1 || K > N);
	int* array = new int[N];
	cout << "Введите значения в массив" << endl;
	input(array, N);
	Delete(array, N, K - 1);
	cout << "Массив после удаления" << endl;
	output(array, N);
	delete[] array;
}