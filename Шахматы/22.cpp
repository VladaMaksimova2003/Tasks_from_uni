#include <iostream>
using namespace std;
#include "Array.h"

int main() {
	char key;
	UINT temp;
	cout << "1) Задать размер " << endl;
	cout << "2) Показать список " << endl;
	cout << "3) Изменить тип фигуры " << endl;
	cout << "4) Переместить фигуру " << endl;
	cout << "5) Прочитать координаты возможного перемещения " << endl;
	cout << "6) Нарисовать фигуры по выбору " << endl;
	cin >> key;

	while (true) {
		switch (key)
		{
		case 1:
			cout << "Задайте размер массива ";
			cin 
			SetSize()
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		default:
			break;
		}
	}
}