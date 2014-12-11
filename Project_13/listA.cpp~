//List - Array-based implementation
#include"listA.h"

List::List(int size)
{
	this->size = size;
	actual = 0;
	cursor = -1;
	data = new char[size];
}

List::List(const List& l)
{
	size = l.size;
	actual = l.actual;
	cursor = l.cursor;
	data = new char[size];
	for(int i = 0; i < l.actual; i++)
		data[i] = l.data[i];
}

List::~List()
{
	delete[] data;
}

bool List::gotoBeginning()
{
	if(!empty())
		cursor = 0;
	else
		return false;
	return true;
}

bool List::gotoEnd()
{
	if(!empty())
		cursor = actual - 1;
	else
		return false;
	return true;
}

bool List::gotoNext()
{
	if((cursor + 1) < actual)
		cursor += 1;
	else
		return false;
	return true;
}

bool List::gotoPrior()
{
	if(!empty() && actual != 1)
		cursor -= 1;
	else
		return false;
	return true;
}

bool List::insertAfter(char c)
{
	if(!full())
	{
		for(int i = actual; i > cursor + 1; i--)
			data[i] = data[i-1];
		cursor++;
		data[cursor] = c;
		actual++;
	}
	else
		return false;
	return true;
}

bool List::insertBefore(char c)
{
	if(!full())
	{
		for(int i = actual; i > cursor; i--)
			data[i] = data[i-1];
		data[cursor] = c;
		actual++;
	}
	else
		return false;
	return true;
}

bool List::remove(char& c)
{
	if(!empty())
	{
		c = data[cursor];
		for(int i = cursor; i < actual; i++)
			data[i] = data[i+1];
		actual--;
		if(actual < cursor)
		{
			actual = 0;
			cursor = -1;
		}	
	}
	else
		return false;
	return true;
}

bool List::replace(char c)
{
	if(!empty())
		data[cursor] = c;
	else
		return false;
	return true;
}

bool List::getCursor(char& c) const
{
	if(!empty())
		c = data[cursor];
	else
		return false;
	return true;
}

bool List::empty() const
{
	return (actual == 0);
}

bool List::full() const
{
	return (actual == size);
}

bool List::clear()
{
	actual = 0;
	cursor = -1;
	return true;
}

List& List::operator=(const List& l)
{
	actual = l.actual;
	cursor = l.cursor;
	for(int i = 0; i < l.actual; i++)
		data[i] = l.data[i];
	return *this;
}

ostream& operator<<(ostream& os, const List& l)
{
	for(int i = 0; i < l.actual; i++)
		os << "[" << i << "] " << l.data[i] << ", ";
	os << endl;
	return os;
}

bool List::operator==(const List& l) const
{
	if(actual != l.actual)
		return false;
	for(int i = 0; i < actual; i++)
		if(data[i] != l.data[i])
			return false;
	return true;
		
}
