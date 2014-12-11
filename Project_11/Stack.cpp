//Stack (Move)
#include "Stack.h"

template<class T>
Stack<T>::Stack(int size)
{
	max = size;
	top = -1;
	data = new T[size];
}

template<class T>
Stack<T>::Stack(const Stack& source)
{
	max = source.max;
	top = source.top;
	data = new T[source.max];
	for(int i = 0; i <= source.top; i++)
		data[i] = source.data[i];
}

template<class T>
Stack<T>::~Stack()
{
	delete[] data;
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack& source)
{
	for(int i = 0; i <= source.top; i++)
		data[i] = source.data[i];
	top = source.top;
	return *this;
}

template<class T>
bool Stack<T>::operator==(const Stack& source) const
{
	for(int i = 0; i < source.top; i++)
		if(data[i] != source.data[i])
			return false;
	if(data[top + 1] != source.data[top + 1])
		return false;
	return true;
}

template<class T>
void Stack<T>::print() const
{
	for(int i = 0; i <= top; i++)
		cout << "[" << i << "] " << data[i] << endl;
}

/*
template<class T>
ostream& operator<<(ostream& os, const Stack<T>& source)
{
	for(int i = 0; i <= source.top; i++)
		os << "[" << i << "] " << source.data[i] << ", ";
	os << endl;
	return os;
}
*/

template<class T>
bool Stack<T>::push(T value)
{
	if (!full())
	{
		top++;
		data[top] = value;
		return true;
	}
	else
		return false;
}

template<class T>
bool Stack<T>::pop(T& value)
{
	if (!empty())
	{
		value = data[top];
		top--;
		return true;
	}	
	else
		return false;
}

template<class T>
bool Stack<T>::empty() const
{
	return (top == -1);
}

template<class T>
bool Stack<T>::full() const
{
	return (top == max - 1);
}

template<class T>
bool Stack<T>::clear()
{
	top = -1;
	return true;
}
