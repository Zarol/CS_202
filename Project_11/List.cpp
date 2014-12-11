//List - Node-based implementation
#include "List.h"

template<typename T>
List<T>::List()
{
	head = NULL;
	cursor = NULL;
}

template<typename T>
List<T>::List(const List<T>& l)
{
	Node<T>* temp = head = l.head;
	while(temp != NULL)
	{
		insertAfter(temp->data);
		temp = temp->next;
	}
	if(temp == NULL)
		head = cursor = new Node<T>(NULL, NULL);	
}

template<typename T>
List<T>::~List()
{
	Node<T>* temp;
	cursor = NULL;

	while(head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

template<typename T>
bool List<T>::gotoBeginning()
{
	if(!empty())
		cursor = head;
	else
		return false;
	return true;
}

template<typename T>
bool List<T>::gotoEnd()
{
	if(!empty())
		while(cursor->next != NULL)
			cursor = cursor->next;
	else
		return false;
	return true;
}

template<typename T>
bool List<T>::gotoNext()
{
	if(!empty())
		if(cursor->next != NULL)
			cursor = cursor->next;
		else
			return false;
	else
		return false;
	return true;
}

template<typename T>
bool List<T>::gotoPrior()
{
	if(!empty())
		if(cursor != head)
		{
			Node<T>* temp = cursor;
			cursor = head;
			while(cursor->next != temp)
				cursor = cursor->next;
		}
		else
			return false;
	else
		return false;
	return true;
}

template<typename T>
bool List<T>::insertAfter(T c)
{
	if(!empty())
	{
		Node<T>* temp = new Node<T>(c, cursor->next);
		cursor->next = temp;
		cursor = temp;
	}
	else
	{
		head = new Node<T>(c, NULL);
		cursor = head;
	}
	return true;
}

template<typename T>
bool List<T>::insertBefore(T c)
{
	if(!empty())
	{
		Node<T>* temp = new Node<T>(cursor->data, cursor->next);
		cursor->next = temp;
		cursor->data = c;
	}
	else
	{
		head = new Node<T>(c, NULL);
		cursor = head;
	}
	return true;
}

template<typename T>
bool List<T>::remove(T& c)
{
	if(!empty())
	{
		c = cursor->data;
		Node<T>* temp = cursor->next;
		delete cursor;
		gotoPrior();
		cursor->next = temp;
	}
	else
		return false;
	return true;
}

template<typename T>
bool List<T>::replace(T c)
{
	if(!empty())
		cursor->data = c;
	else
		return false;
	return true;
}

template<typename T>
bool List<T>::getCursor(T& c) const
{
	if(!empty())
		c = cursor->data;
	else
		return false;
	return true;
}

template<typename T>
bool List<T>::empty() const
{
	return (head == NULL);
}

template<typename T>
bool List<T>::full() const
{
	return false;
}

template<typename T>
bool List<T>::clear()
{
	Node<T>* temp;
	cursor = NULL;

	while(head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	head = NULL;
	return true;
}

template<typename T>
List<T>& List<T>::operator=(const List<T>& l)
{
	Node<T>* temp = head = l.head;
	while(temp != NULL)
	{
		insertAfter(temp->data);
		temp = temp->next;
	}
	if(temp == NULL)
		head = cursor = new Node<T>(NULL, NULL);
	return *this;	
}

template<typename T>
void List<T>::print() const
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
ostream& operator<<(ostream& os, const List& l)
{
	int i = 0;
	Node* temp = l.head;
	while(temp != NULL)
	{
		os << "[" << i << "] " << temp->data << ", ";
		temp = temp->next;
	}
	os << endl;
	return os;
}
*/

template<typename T>
bool List<T>::operator==(const List<T>& l) const
{
	Node<T>* temp1 = head;
	Node<T>* temp2 = l.head;
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
