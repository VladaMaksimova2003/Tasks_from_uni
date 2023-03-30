#pragma once
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