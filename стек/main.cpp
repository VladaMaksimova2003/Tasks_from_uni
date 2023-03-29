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
#include <iomanip>
using namespace std;

template <class T>
class Stack
{
private:
	size_t Length;
	T* S;
public:
	Stack();
	~Stack();
	void Push(T elem);
	T Pop();
	T Check();
	bool IsEmpty();
	unsigned long GetLength();

	Stack& operator = (const Stack<T>&);

};
template <class T>
Stack<T>& Stack<T>::operator= (const Stack<T>& stack)
{
	if (S) delete[] S;
	Length = stack.Length;


	S = new T[stack.Length];

	for (int i = 0; i < stack.Length; ++i)
		S[i] = stack.S[i];

	return *this;
}
template <class T>
Stack<T>::Stack()
{
	S = 0;
	Length = 0;
}

template <class T>
Stack<T>::~Stack()
{
	if (S)
		delete[] S;
}

template <class T>
void Stack<T>::Push(T elem)
{
	T* temp = new T[Length + 1];
	for (int i = 0; i < Length; i++)
	{
		temp[i] = S[i];
	}
	temp[Length] = elem;
	Length++;
	delete[] S;
	S = new T[Length];
	S = temp;
}

template <class T>
T Stack<T>::Pop()
{
	if (IsEmpty())
		throw exception("���� ����");
	Length--;
	T value = S[Length];

	T* temp = new T[Length];
	for (int i = 0; i < Length; i++)
	{
		temp[i] = S[i];
	}
	delete[] S;
	S = new T[Length];
	S = temp;

	return value;
}

template <class T>
T Stack<T>::Check()
{
	return S[Length - 1];
}

template <class T>
bool Stack<T>::IsEmpty()
{
	return true ? Length == 0 : false;
}

template <class T>
unsigned long Stack<T>::GetLength()
{
	return Length;
}

void stack_test(Stack<Aquarium> stack1, Stack<Aquarium> stack2, Aquarium value1, Aquarium value2) {
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
					cout << "��������� ������� � ����� " << stack1.Pop() << endl;
				}
				else cout << "��������� ������� � ����� " << stack2.Pop() << endl;
				break;
			case '3':
				cout << "�������� ���� ";
				cin >> choice;
				if (choice == '1') {
					cout << "��������� ������� � ����� " << stack1.Check() << endl;
				}
				else cout << "��������� ������� � ����� " << stack2.Check() << endl;
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
void stack_test(Stack<short> stack1, Stack<short> stack2, short value1, short value2) {
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
					cout << "��������� ������� � ����� " << stack1.Pop() << endl;
				}
				else cout << "��������� ������� � ����� " << stack2.Pop() << endl;
				break;
			case '3':
				cout << "�������� ���� ";
				cin >> choice;
				if (choice == '1') {
					cout << "��������� ������� � ����� " << stack1.Check() << endl;
				}
				else cout << "��������� ������� � ����� " << stack2.Check() << endl;
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

	cout << "�������� � ������ ������� ������ �������� 1-short, 2-Aquarium";
	cin >> key;
	if (key == '1')
		stack_test(short1, short2, value1, value2);
	else if (key == '2')
		stack_test(Aquarium1, Aquarium2, valueA1, valueA2);
	else cout << "����������� ������ ����� " << endl;

}