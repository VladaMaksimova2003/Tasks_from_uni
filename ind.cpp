#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h> 
#include <string>
using namespace std;
void Creat(char mas[12][13], int y, int x) {//прорисовка 
	int i, j;
	strcpy(mas[0], "############");
	for (i = 10; i >= 1; --i) {
		strcpy(mas[i], "#          #");
	}
	strcpy(mas[11], "############");
	mas[y][x] = '@';
	system("cls");
	for (i = 11; i >= 0; --i) {
		for (j = 0; j < 12; ++j)
			std::cout << " " << mas[i][j];
		std::cout << std::endl;
	}
}
void Input_str(string& key) {//ввод команд
	do {
		cout << "Введите команду (ВВЕРХ/ВНИЗ/ВЛЕВО/ВПРАВО)" << endl;
		getline(cin, key);
		if (key == "ВВЕРХ" || key == "ВНИЗ" || key == "ВЛЕВО" || key == "ВПРАВО") break;
		if (key != " ") cout << "Повторите ввод" << endl;
	} while (key != " ");
}
void Input(string key, int& y, int& x) {//нахождение координат исполнителя
	if (key == "ВВЕРХ") ++y;
	if (key == "ВНИЗ") --y;
	if (key == "ВЛЕВО") --x;
	if (key == "ВПРАВО") ++x;
}
//int Repeat(char mas[12][13], string key, int count, int &y, int &x) {//повторение команд
//	string comand = " ";
//	do {
//		cout << "Для повторения строки " << count << " введите команду ПОВТОРИТЬ N(1 <= N <= 9)" << endl;
//		getline(cin, comand);
//		if (comand.find("ПОВТОРИТЬ") != string::npos) {//N-ое количество ходов команды
//				for (int i = 0; i < comand[10] - '0'; ++i)
//					Input(key, y, x);
//				if (mas[y][x] == '#') {
//					return 1;
//				}
//				Creat(mas, y, x);
//		}
//
//	} while (comand != " ");
//}
int Repeat(char mas[12][13], string key, int count, int& y, int& x) {//повторение команд
	string comand = " ";
	do {
		cout << "Для повторения строки введите команду ПОВТОРИТЬ N(1 <= N <= 9)" << endl;
		getline(cin, comand);
		if (comand.find("ПОВТОРИТЬ") != string::npos) {//перезапись предыдущей команды
			++count;
			Input_str(key);
			Input(key, y, x);
			if (mas[y][x] == '#') {
				return 1;
			}
			Creat(mas, y, x);
		}

	} while (comand != " ");
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int x = 1, y = 1;//начальное положение исполнителя
	int count = 0;//счетчик команд
	string key = "";//строка для команд
	char mas[12][13];//массив для координат 
	int flag = 0;//результат выхода из функции повтора 
	Creat(mas, y, x);
	Input_str(key);
	Input(key, y, x);
	//предварительный ввод
	do {
		++count;
		if (mas[y][x] == '#') { break; }
		Creat(mas, y, x);
		flag = Repeat(mas, key, count, y, x);
		if (flag == 1) { break; }
		Input_str(key);
		Input(key, y, x);

	} while (key != " ");
	if (x > 0 && y > 0 && x < 11 && y < 11)//результаты выхода 
		cout << "Координаты исполнителя : (" << x << "," << y << ")";
	else if (x == 0)
		cout << "Команда " << count << ": X < 1";
	else if (y == 0)
		cout << "Команда " << count << ": Y < 1";
	else if (x > 10)
		cout << "Команда " << count << ": X > 10";
	else
		cout << "Команда " << count << ": Y > 10";
	return 0;
}