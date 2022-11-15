#include <iostream>
#include <string>
#include <random>
using namespace std;
//Напишите генератор паролей.Составьте три уровня сложности генерации паролей(вместе с их длиной) и спрашивайте у пользователя, 
//какой уровень сложности ему нужен.Проявите свою изобретательность : надёжные пароли должны состоять из сочетания строчных букв, 
//прописных букв, цифр и символов.Пароли должны генерироваться случайным образом каждый раз, когда пользователь запрашивает новый пароль.
const char lowercase[] = "абвгдеёжзийклмнопрстуфхцчшщэюя";
const char Uppercase[] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЭЮЯ";
const char digits[] = "0123456789";
const char special[] = "!@#$%^&*()?_=+.,|`~^№";
string generate(int length, bool flag_lowercase, bool flag_uppercase, bool flag_digits, bool flag_special) {
	mt19937 mt{ random_device{}() };
	string result, password;
	if (!flag_lowercase && !flag_uppercase && !flag_digits && !flag_special) return "";
	if (flag_lowercase) result += lowercase;
	if (flag_uppercase) result += Uppercase;
	if (flag_digits) result += digits;
	if (flag_special) result += special;
	uniform_int_distribution<int> num(0, result.length() - 1);
	for (int i = 0; i < length; ++i) {
		password += result[num(mt)];
	}
	return password;
}
int main() {
	setlocale(LC_ALL, "ru");
	bool f1, f2, f3, f4;
	char key;
	int length;
	cout << "Какой уровень сложности пароль вам нужен?" << endl;
	cout << "1 - Слабый" << endl;
	cout << "2 - Средний" << endl;
	cout << "3 - Сложный" << endl;
	cin >> key;
	cout << "Применить строчные буквы? 1 - да, 0 - нет" << endl;
	cin >> f1;
	cout << "Применить прописные буквы? 1 - да, 0 - нет" << endl;
	cin >> f2;
	cout << "Применить цифры? 1 - да, 0 - нет" << endl;
	cin >> f3;
	cout << "Применить символы? 1 - да, 0 - нет" << endl;
	cin >> f4;
	if (key == '1') length = 8;
	else if (key == '2') length = 12;
	else if (key == '3') length = 20;
	else length = 20;
	if (f1 == 0 && f2 == 0 && f3 == 0 && f4 == 0) {
		f1 = 1; f2 = 1; f3 = 1; f4 = 1;
	}
	cout << generate(length, f1, f2, f3, f4);
}