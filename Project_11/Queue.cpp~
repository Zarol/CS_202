//Queue (Stay)
#include "Queue.h"

template<class T>
Queue<T>::Queue()
{
	head = NULL;
	tail = NULL;
}

template<class T>
Queue<T>::Queue(const Queue<T>& q)
{
	Node<T>* temp = head = q.head;
	while(temp != NULL)
	{
		enqueue(temp->data);
		temp = temp->next;
	}
	tail = temp;
	if(temp == NULL)
		head = tail = new Node<T>(NULL, NULL);
}

template<class T>
Queue<T>::~Queue()
{
	Node<T>* temp;
	tail = NULL;

	while(head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& q)
{
	Node<T>* temp = head = q.head;
	while(temp != NULL)
	{
		enqueue(temp->data);
		temp = temp->next;
	}
	if(temp == NULL)
		head = tail = new Node<T>(NULL, NULL);
	return *this;
}

template<class T>
bool Queue<T>::enqueue(T value)
{
	if(!empty())
	{
		Node<T>* temp = new Node<T>(value, NULL);
		tail->next = temp;
		tail = temp;
	}
	else
		head = tail = new Node<T>(value, NULL);
	return true;
}

template<class T>
bool Queue<T>::dequeue(T& value)
{
	if(!empty())
	{
		value = head->data;
		if(head != tail)
		{
			Node<T>* temp = head;
			head = head->next;
			delete temp;
		}
		else
		{
			delete head;
			head = tail = NULL;
		}
	}
	else
		return false;
	return true;
}

template<class T>
bool Queue<T>::empty() const
{
	return (head == NULL);
}

template<class T>
bool Queue<T>::full() const
{
	return false;
}

template<class T>
bool Queue<T>::clear()
{
	Node<T>* temp;
	tail = NULL;

	while(head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	return true;
}

template<class T>
bool Queue<T>::operator==(const Queue<T>& q) const
{
	Node<T>* temp1 = head;
	Node<T>* temp2 = q.head;
	while(temp2 != NULL)
	{
		if(temp1->data != temp2->data)
			return false;
		temp2 = temp2->next;
		temp1 = temp1->next;
	}
	if(temp1->next != NULL)
		return false;
	return true;
}

template<typename T>
void Queue<T>::print() const
{
	int i = 0;
	Node<T>* temp = head;
	while(temp != NULL)
	{
		cout << "[" << i << "] " << temp->data << endl;
		temp = temp->next;
	}
}


/*
template<class T>
ostream& operator<<(ostream& os, const Queue<T>& q)
{
	int i = 0;
	Node* temp = q.head;
	while(temp != NULL)
	{
		os << "[" << i << "] " << temp->data << ", ";
		temp = temp->next;
	}
	os << endl;
	return os;
}
*/
