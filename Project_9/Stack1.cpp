//Stack (Stay)
#include "Stack.h"

template<class T>
Stack<T>::Stack(int size)
{
	max = size;
	top = 0;
	actual = -1;
	data = new T[size];
}

template<class T>
Stack<T>::Stack(const Stack& source)
{
	max = source.max;
	top = 0;
	actual = source.actual;
	data = new T[source.max];
	for(int i = 0; i <= source.actual; i++)
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
	for(int i = 0; i <= source.actual; i++)
		data[i] = source.data[i];
	actual = source.actual;
	return *this;
}

template<class T>
bool Stack<T>::push(T value)
{
	if(!full())
	{
		actual++;
		for(int i = actual; i > -1; i--)
			data[i+1] = data[i];
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
		for(int i = 0; i < actual; i++)
			data[i] = data[i+1];
		actual--;
	}
	else
		return false;	
}

template<class T>
bool Stack<T>::empty() const
{
	return (actual == -1);
}

template<class T>
bool Stack<T>::full() const
{
	return (actual == max - 1);
}

template<class T>
bool Stack<T>::clear()
{
	actual = -1;
	return true;
}

template<class T>
void Stack<T>::print() const
{
	for(int i = 0; i <= actual; i++)
		cout << "[" << i << "] " << data[i] << ", ";
	cout << endl;
}
