//13.Описать рекурсивную функцию Palindrome(S) логического типа, 
//возвращающую True, если строка S является палиндромом
//(т.е.читается одинаково слева направо и справа налево), и False в противном случае.
//Оператор цикла в теле функции не использовать.
//Вывести значения функции Palindrome для пяти данных строк.
#include <iostream>
#include <string>
using namespace std;
bool Palindrome(string str, int size, string s, int& flag) {
	if (size > 0) {
		char c = str[size - 1];
		s += c;
		--size;
		Palindrome(str, size, s, flag);
	}
	if (str == s) {
		flag = 1; return flag;
	}
	return flag;
}
int main() {
	string str, s = "";
	int size, flag = 0;;
	setlocale(LC_ALL, "ru");
	for (int i = 0; i < 5; ++i) {
		cout << "Введите строку ";
		cin >> str;
		size = str.size();
		cout << Palindrome(str, size, s, flag) << endl;
		flag = 0;
	}
}