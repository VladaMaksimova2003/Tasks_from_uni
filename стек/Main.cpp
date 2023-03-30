// 4. ���� ������������ �������
// ����������� ������ ������ ���� ������������ ������� � �������� ���
// ������������� �� ������� ������ ���� short � �������� ������ ��������, �
// ����� ���������, �������������� ����������� ������ �������.
// 
// ���� � ��� �������� ������������������ ���������, ������� � ������� ��
// ������� �� ����� ������������� ������� � ����� ���������, � ��������� �������
// ������� �����, ��������� �����.���� ����� ����������� ��� ������ ���� �� �����,
// ��� ���������� ��� ������ ����� ����� �������� ������ ������.
// �������� ����� ��������� � ���� � ��������� �� �����.��� ����������
// ��������, ������ ����� ������������� �������������.����������� ������ ���������
// ����������� �������, ��� ���� ������ ����� ������������� �����������.������
// ����� - ������� ����� �� ���������.
// 
// ������ ������ - ������� ������ �������� �������� �� ������������, ��� ����
// ���������� ������������ �������������� ��������.
// ����� - ������ ������ �������� ������ ����������� :
// ��������� �������� � ����;
// ��������� ��������� ������� �� �����;
// ���������� � ���������� �������� �����;
// ��������� ���� �� �������;
// ������ ���������� ��������� � �����;
// ���������� ���� ���� � ������(�������������� �������� = ).
// � ��������� ���������� ������� �� ������ ������� ������� �� ��� ������������ ������(�������� ��� ������� ����) � �������� �� �����������.
#include <iostream>
#include "Aquarium.h"
#include "Stack.h"
#include <iomanip>
using namespace std;

template <typename T>
void my_print(const T& t) {
	cout << t;
}
template <typename T>
void stack_test(Stack<T> stack1, Stack<T> stack2, T value1, T value2) {
	char key;
	char choice;
	size_t lenght;
	do {
		try {
			cout << "�������� ��������, ������� ������ ������� " << endl;
			cout << "1) �������� �������� � ����" << endl;
			cout << "2) ������� ��������� ������� �� �����" << endl;
			cout << "3) ���������� � ���������� �������� �����" << endl;
			cout << "4) ��������� ���� �� �������" << endl;
			cout << "5) �������� ���������� ��������� � �����" << endl;
			cout << "6) ����������� ���� ���� � ������" << endl;
			cout << "7) �����" << endl;
			cin >> key;

			switch (key) {
			case '1':
				cout << "��������, � ����� ���� � ������ �������� ";
				cin >> choice;
				if (choice == '1') {
					cout << "������� ���������� ��������� ��� ������� ����� " << endl;
					cin >> lenght;
					for (size_t i = 0; i < lenght; ++i) {
						cout << i + 1 << "������� " << endl;
						cin >> value1;
						stack1.Push(value1);
					}
				}
				if (choice == '2') {
					cout << "������� ���������� ��������� ��� ������� ����� " << endl;
					cin >> lenght;
					for (size_t i = 0; i < lenght; ++i) {
						cout << i + 1 << "������� " << endl;
						cin >> value2;
						stack2.Push(value2);
					}
				}


				break;
			case '2':
				cout << "�������� ���� ";
				cin >> choice;
				if (choice == '1') {
					cout << "��������� ������� � ����� ";
					my_print(stack1.Pop());
				}
				else {
					cout << "��������� ������� � ����� ";
					my_print(stack2.Pop());
				}
				break;
			case '3':
				cout << "�������� ���� ";
				cin >> choice;
				if (choice == '1') {
					cout << "��������� ������� � ����� ";
					my_print(stack1.Check());
				}
				else {
					cout << "��������� ������� � ����� ";
					my_print(stack2.Check());
				}
				break;
			case '4':
				cout << "����� ���� �� ������ ���������? ";
				cin >> choice;
				if (choice == '1') {
					if (stack1.IsEmpty()) {
						cout << "���� ���� " << endl;
					}
					else cout << "���� �� ���� " << endl;
				}
				else {
					if (stack1.IsEmpty()) {
						cout << "���� ���� " << endl;
					}
					else cout << "���� �� ���� " << endl;
				}
				break;
			case '5':
				cout << "�������� ���� ";
				cin >> choice;
				if (choice == '1') {
					cout << "���������� ��������� � ����� " << stack1.GetLength() << endl;
				}
				else cout << "���������� ��������� � ����� " << stack2.GetLength() << endl;

				break;
			case '6':
				stack2 = stack1;
				cout << "���� 2 ���������� " << endl;
				break;
			case '7':
				break;
			default:
				break;
			}

		}
		catch (const exception& value)
		{
			cout << value.what() << endl;
		}
	} while (key >= '1' && key <= '6');
}
int main() {
	setlocale(LC_ALL, "ru");
	char key;
	Stack<short> short1;
	Stack<short> short2;
	short value1 = 0;
	short value2 = 0;

	Stack<Aquarium> Aquarium1;
	Stack<Aquarium> Aquarium2;
	Aquarium valueA1;
	Aquarium valueA2;

	do {
		cout << "�������� � ������ ������� ������ �������� 1-short, 2-Aquarium" << endl;
		cout << "����� - 0" << endl;
		cin >> key;
		if (key == '1')
			stack_test(short1, short2, value1, value2);
		else if (key == '2')
			stack_test(Aquarium1, Aquarium2, valueA1, valueA2);
		else if (key != '0') cout << "����������� ������ ����� " << endl;
	} while (key != '0');

}