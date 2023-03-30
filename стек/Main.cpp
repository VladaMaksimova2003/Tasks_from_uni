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
			cout << "выберите действие, которые хотите сделать " << endl;
			cout << "1) добавить элементы в стек" << endl;
			cout << "2) извлечь последний элемент из стека" << endl;
			cout << "3) обратиться к последнему элементу стека" << endl;
			cout << "4) проверить стек на пустоту" << endl;
			cout << "5) прочесть количество элементов в стеке" << endl;
			cout << "6) скопировать один стек в другой" << endl;
			cout << "7) выход" << endl;
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
					cout << "Последний элемент в стеке ";
					my_print(stack1.Pop());
				}
				else {
					cout << "Последний элемент в стеке ";
					my_print(stack2.Pop());
				}
				break;
			case '3':
				cout << "Выберите стек ";
				cin >> choice;
				if (choice == '1') {
					cout << "Последний элемент в стеке ";
					my_print(stack1.Check());
				}
				else {
					cout << "Последний элемент в стеке ";
					my_print(stack2.Check());
				}
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
		cout << "Выберите с какими стекаим будете работать 1-short, 2-Aquarium" << endl;
		cout << "Выход - 0" << endl;
		cin >> key;
		if (key == '1')
			stack_test(short1, short2, value1, value2);
		else if (key == '2')
			stack_test(Aquarium1, Aquarium2, valueA1, valueA2);
		else if (key != '0') cout << "Неправильно набран номер " << endl;
	} while (key != '0');

}