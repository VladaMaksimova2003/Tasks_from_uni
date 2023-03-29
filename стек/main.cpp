// 4. Стек бесконечного размера
// Разработать шаблон класса Стек бесконечного размера и показать его
// использование на примере данных типа short и объектов класса Аквариум, а
// также программу, иллюстрирующую возможности данных классов.
// 
// Стек – это конечная последовательность элементов, которая в отличие от
// массива не имеет произвольного доступа к своим элементам, а реализует принцип
// “первый вошел, последний вышел”.Стек можно представить как стопку книг на столе,
// где добавление или взятие новой книги возможно только сверху.
// Элементы можно добавлять в стек и извлекать из стека.При добавлении
// элемента, размер стека автоматически увеличивается.Извлекается всегда последний
// добавленный элемент, при этом размер стека автоматически уменьшается.Размер
// стека - шаблона ничем не ограничен.
// 
// Методы класса - шаблона должны включать проверку на корректность, при этом
// необходимо использовать исключительные ситуации.
// Класс - шаблон должен включать методы позволяющие :
// добавлять элементы в стек;
// извлекать последний элемент из стека;
// обращаться к последнему элементу стека;
// проверять стек на пустоту;
// читать количество элементов в стеке;
// копировать один стек в другой(переопределить оператор = ).
// В программе необходимо создать на основе данного шаблона по два объектастека данных(отдельно для каждого типа) и показать их возможности.
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
		throw exception("Стек пуст");
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
			cout << "выберите действие, которые хотите сделать " << endl;
			cout << "1) добавить элементы в стек" << endl;
			cout << "2) извлечь последний элемент из стека" << endl;
			cout << "3) обратиться к последнему элементу стека" << endl;
			cout << "4) проверить стек на пустоту" << endl;
			cout << "5) прочесть количество элементов в стеке" << endl;
			cout << "6) скопировать один стек в другой" << endl;
			cin >> key;

			switch (key) {
			case '1':
				cout << "Выберите, в какой стек в хотите добавить ";
				cin >> choice;
				if (choice == '1') {
					cout << "Задайте количество элементов для первого стека " << endl;
					cin >> lenght;
					for (size_t i = 0; i < lenght; ++i) {
						cout << i + 1 << "элемент " << endl;
						cin >> value1;
						stack1.Push(value1);
					}
				}
				if (choice == '2') {
					cout << "Задайте количество элементов для второго стека " << endl;
					cin >> lenght;
					for (size_t i = 0; i < lenght; ++i) {
						cout << i + 1 << "элемент " << endl;
						cin >> value2;
						stack2.Push(value2);
					}
				}


				break;
			case '2':
				cout << "Выберите стек ";
				cin >> choice;
				if (choice == '1') {
					cout << "Последний элемент в стеке " << stack1.Pop() << endl;
				}
				else cout << "Последний элемент в стеке " << stack2.Pop() << endl;
				break;
			case '3':
				cout << "Выберите стек ";
				cin >> choice;
				if (choice == '1') {
					cout << "Последний элемент в стеке " << stack1.Check() << endl;
				}
				else cout << "Последний элемент в стеке " << stack2.Check() << endl;
				break;
			case '4':
				cout << "Какой стек вы хотите проверить? ";
				cin >> choice;
				if (choice == '1') {
					if (stack1.IsEmpty()) {
						cout << "Стек пуст " << endl;
					}
					else cout << "Стек не пуст " << endl;
				}
				else {
					if (stack1.IsEmpty()) {
						cout << "Стек пуст " << endl;
					}
					else cout << "Стек не пуст " << endl;
				}
				break;
			case '5':
				cout << "Выберите стек ";
				cin >> choice;
				if (choice == '1') {
					cout << "Количество элементов в стеке " << stack1.GetLength() << endl;
				}
				else cout << "Количество элементов в стеке " << stack2.GetLength() << endl;

				break;
			case '6':
				stack2 = stack1;
				cout << "Стек 2 скопирован " << endl;
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
			cout << "выберите действие, которые хотите сделать " << endl;
			cout << "1) добавить элементы в стек" << endl;
			cout << "2) извлечь последний элемент из стека" << endl;
			cout << "3) обратиться к последнему элементу стека" << endl;
			cout << "4) проверить стек на пустоту" << endl;
			cout << "5) прочесть количество элементов в стеке" << endl;
			cout << "6) скопировать один стек в другой" << endl;
			cin >> key;

			switch (key) {
			case '1':
				cout << "Выберите, в какой стек в хотите добавить ";
				cin >> choice;
				if (choice == '1') {
					cout << "Задайте количество элементов для первого стека " << endl;
					cin >> lenght;
					for (size_t i = 0; i < lenght; ++i) {
						cout << i + 1 << "элемент " << endl;
						cin >> value1;
						stack1.Push(value1);
					}
				}
				if (choice == '2') {
					cout << "Задайте количество элементов для второго стека " << endl;
					cin >> lenght;
					for (size_t i = 0; i < lenght; ++i) {
						cout << i + 1 << "элемент " << endl;
						cin >> value2;
						stack2.Push(value2);
					}
				}


				break;
			case '2':
				cout << "Выберите стек ";
				cin >> choice;
				if (choice == '1') {
					cout << "Последний элемент в стеке " << stack1.Pop() << endl;
				}
				else cout << "Последний элемент в стеке " << stack2.Pop() << endl;
				break;
			case '3':
				cout << "Выберите стек ";
				cin >> choice;
				if (choice == '1') {
					cout << "Последний элемент в стеке " << stack1.Check() << endl;
				}
				else cout << "Последний элемент в стеке " << stack2.Check() << endl;
				break;
			case '4':
				cout << "Какой стек вы хотите проверить? ";
				cin >> choice;
				if (choice == '1') {
					if (stack1.IsEmpty()) {
						cout << "Стек пуст " << endl;
					}
					else cout << "Стек не пуст " << endl;
				}
				else {
					if (stack1.IsEmpty()) {
						cout << "Стек пуст " << endl;
					}
					else cout << "Стек не пуст " << endl;
				}
				break;
			case '5':
				cout << "Выберите стек ";
				cin >> choice;
				if (choice == '1') {
					cout << "Количество элементов в стеке " << stack1.GetLength() << endl;
				}
				else cout << "Количество элементов в стеке " << stack2.GetLength() << endl;

				break;
			case '6':
				stack2 = stack1;
				cout << "Стек 2 скопирован " << endl;
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

	cout << "Выберите с какими стекаим будете работать 1-short, 2-Aquarium";
	cin >> key;
	if (key == '1')
		stack_test(short1, short2, value1, value2);
	else if (key == '2')
		stack_test(Aquarium1, Aquarium2, valueA1, valueA2);
	else cout << "Неправильно набран номер " << endl;

}