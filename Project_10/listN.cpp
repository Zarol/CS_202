//List - Node-based implementation
#include"listN.h"

Node::Node(char c, Node* n)
{
	data = c;
	next = n;
}

List::List(int IGNORE)
{
	head = NULL;
	cursor = NULL;
}

List::List(const List& l)
{
	Node* temp = head = l.head;
	while(temp != NULL)
	{
		insertAfter(temp->data);
		temp = temp->next;
	}
	if(temp == NULL)
		head = cursor = new Node(NULL, NULL);	
}

List::~List()
{
	Node* temp;
	cursor = NULL;

	while(head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

bool List::gotoBeginning()
{
	if(!empty())
		cursor = head;
	else
		return false;
	return true;
}

bool List::gotoEnd()
{
	if(!empty())
		while(cursor->next != NULL)
			cursor = cursor->next;
	else
		return false;
	return true;
}

bool List::gotoNext()
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

bool List::gotoPrior()
{
	if(!empty())
		if(cursor != head)
		{
			Node* temp = cursor;
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

bool List::insertAfter(char c)
{
	if(!empty())
	{
		Node* temp = new Node(c, cursor->next);
		cursor->next = temp;
		cursor = temp;
	}
	else
	{
		head = new Node(c, NULL);
		cursor = head;
	}
	return true;
}

bool List::insertBefore(char c)
{
	if(!empty())
	{
		Node* temp = new Node(cursor->data, cursor->next);
		cursor->next = temp;
		cursor->data = c;
	}
	else
	{
		head = new Node(c, NULL);
		cursor = head;
	}
	return true;
}

bool List::remove(char& c)
{
	if(!empty())
	{
		c = cursor->data;
		Node* temp = cursor->next;
		delete cursor;
		gotoPrior();
		cursor->next = temp;
	}
	else
		return false;
	return true;
}

bool List::replace(char c)
{
	if(!empty())
		cursor->data = c;
	else
		return false;
	return true;
}

bool List::getCursor(char& c) const
{
	if(!empty())
		c = cursor->data;
	else
		return false;
	return true;
}

bool List::empty() const
{
	return (head == NULL);
}

bool List::full() const
{
	return false;
}

bool List::clear()
{
	Node* temp;
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

List& List::operator=(const List& l)
{
	Node* temp = head = l.head;
	while(temp != NULL)
	{
		insertAfter(temp->data);
		temp = temp->next;
	}
	if(temp == NULL)
		head = cursor = new Node(NULL, NULL);	
}

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

bool List::operator==(const List& l) const
{
	Node* temp1 = head;
	Node* temp2 = l.head;
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
