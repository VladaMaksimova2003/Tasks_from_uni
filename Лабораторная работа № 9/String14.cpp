//String14.Дана строка.Подсчитать количество содержащихся в ней прописных латинских букв.
#include <iostream>
#include <string>
using namespace std;

void main() {
	setlocale(LC_ALL, "ru");
	string str;
	int size = 0;
	cout << "Введите строку ";
	cin >> str;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z') ++size;
	}
	cout << "Количество строчных букв " << size;
}