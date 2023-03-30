#include "Stack.h"


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