//Queue (Wrap)
#include "Queue.h"

Queue::Queue(int size)
{
	max = size;
	front = 0;
	rear = -1;
	data = new int[max];
}

Queue::Queue(const Queue& source)
{
	max = source.max;
	front = source.front;
	rear = source.rear;
	data = new int[source.max];
	for(int i = 0; i <= source.rear; i++)
		data[i] = source.data[i];
}

Queue::~Queue()
{
	delete[] data;
}

Queue& Queue::operator=(const Queue& source)
{
	for(int i = 0; i <= source.rear; i++)
		data[i] = source.data[i];
	rear = source.rear;
	return *this;
}

bool Queue::enqueue(int value)
{
	if(!full())
	{
		rear++;
		rear %= max;
		data[rear] = value;
		return true;
	}
	else
		return false;
}

bool Queue::dequeue(int& value)
{
	if(!empty())
	{
		value = data[front];
		front++;
		front %= max;
		return true;
	}
	else
		return false;
}

bool Queue::empty() const
{
	return (rear == -1);
}

bool Queue::full() const
{
	return (rear == max - 1);
}

bool Queue::clear()
{
	rear = -1;
	return true;
}

bool Queue::operator==(const Queue& source) const
{
	if(max != source.max)
		return false;
	else
		for(int i = 0; i < max; i++)
			if(data[i] != source.data[i])
				return false;
	return true;
}

ostream& operator<<(ostream& os, const Queue& source)
{
	if(source.rear > source.front)
	{
		for(int i = source.front; i <= source.rear; i++)
			os << "[" << i << "] " << source.data[i] << ", ";
		os << endl;
		return os;
	}
	else
	{
		for(int i = source.rear; i < source.max; i++)
			os << "[" << i << "] " << source.data[i] << ", ";
		for(int i = 0; i <= source.front; i++)
			os << "[" << i << "] " << source.data[i] << ", ";
		os << endl;
		return os;
	}
	return os;
}
