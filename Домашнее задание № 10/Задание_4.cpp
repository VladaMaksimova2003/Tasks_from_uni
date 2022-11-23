#include <iostream>
using namespace std;
//Дан массив целых чисел из N элементов.Отсортировать элементы со значением больше 10 в порядке возрастания, 
//а остальные - в порядке убывания.Использовать сортировку простыми обменами.
void bubbleSort(int array[], int size) {
    for (int step = 0; step < (size - 1); ++step) {

        int swap = 0;
        for (int i = 0; i < (size - step - 1); ++i) {
            if (array[i] > array[i + 1] && array[i + 1] > 9 || array[i] < array[i + 1] && array[i] < 10) {

                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swap = 1;
            }
        }
        if (swap == 0)
            break;
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "  " << array[i];
    }
    cout << "\n";
}

int main() {
    setlocale(LC_ALL, "ru");
    int size;
    cout << "Введите размер массива ";
    cin >> size;
    int* array = new int[size];
    cout << "Введите значения массива ";
    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }

    bubbleSort(array, size);

    cout << "Отсортированный массив:\n";
    printArray(array, size);
}