//String31. Даны строки S и S0. Проверить, содержится ли строка S0 в строке S. 
//Если содержится, то вывести True, если не содержится, то вывести False.
#include <iostream>
#include <string>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	string str, s;
	int size = 0;
	cout << "Введите строку ";
	cin >> s;
	cout << "Введите строку, которую нужно найти ";
	cin >> str;
	int index = s.find(str);
	if (index != string::npos) {
		return 1;
	}
	return 0;
}