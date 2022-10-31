//Array21.Дан массив размера N и целые числа K и L(1 ≤ K ≤ L ≤ N).
//Найти среднее арифметическое элементов массива с номерами от K до L включительно.
#include <iostream>
#include <string>
using namespace std;
void input(int* array, int N) {
	for (int i = 0; i < N; ++i) {
		cin >> array[i];
	}
}
void Sum(int L, int K, int* array, int& sum) {
	for (int i = K; i <= L; ++i) {
		sum += array[i];
	}
}
int main() {
	setlocale(LC_ALL, "ru");
	int L, K, N, sum = 0;
	do {
		cout << "Введите размер массива, значение K и значение L (1 <= K <= L <= N)соответственно" << endl;
		cin >> N >> K >> L;
	} while (K < 1 || L < 1 || N < 1 || K > L || K > N || L > N);
	int* array = new int[N];
	cout << "Введите значения в массив" << endl;
	input(array, N);
	Sum(L - 1, K - 1, array, sum);
	cout << "Среднее арифметическое элементов массива с номерами от K до L включительно " << sum / (L - K + 1);
	delete[] array;
}