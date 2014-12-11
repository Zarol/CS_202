#include "Project11Classes.h"

template<class T>
Node<T>::Node(T t, Node<T>* n)
{
	data = t;
	next = n;
}

template<class T>
Node<T>::Node(const Node<T>& n)
{
	data = n.data;
	n = n.next;
}

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
		i++;
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
		i++;
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

Card::Card()
{
	suit = "suit";
	rank = 0;
	location = "location";
}

Card::Card(string newSuit, int newRank, string newLocation)
{
	suit = newSuit;
	rank = newRank;
	location = newLocation;
}

Card::Card(const Card& newCard)
{
	suit = newCard.suit;
	rank = newCard.rank;
	location = newCard.location;
}

Card::~Card()
{
}

bool Card::setSuit(string newSuit)
{
	suit = newSuit;
	return true;
}

string Card::getSuit() const
{
	return suit;
}

bool Card::setRank(int newRank)
{
	if(newRank > 0 && newRank < 14)
	{
		rank = newRank;
		return true;
	}
	else
		return false;
}

int Card::getRank() const
{
	return rank;
}

bool Card::setLocation(string newLocation)
{
	location = newLocation;
	return true;
}

string Card::getLocation() const
{
	return location;
}

void Card::reset()
{
	suit = "suit";
	rank = 0;
	location = "location";
}

Card Card::operator=(const Card& sourceCard)
{
	suit = sourceCard.suit;
	rank = sourceCard.rank;
	location = sourceCard.location;
	return *this;
}

bool Card::operator>(const Card& sourceCard) const
{
	if(rank > sourceCard.rank)
		return true;
	else
		return false;
}

bool Card::operator<(const Card& sourceCard) const
{ 
	if(rank < sourceCard.rank)
		return true;
	else
		return false;
}


bool operator>=(const Card& sourceCard, const Card& compareCard)
{
	if(sourceCard.rank >= compareCard.rank)
		return true;
	else
		return false;
}

bool operator<=(const Card& sourceCard, const Card& compareCard)
{
	if(sourceCard.rank <= compareCard.rank)
		return true;
	else
		return false;
}

ifstream& operator>>(ifstream& ifs, Card& destCard)
{
	ifs >> destCard.suit;
	ifs >> destCard.rank;
	return ifs;
}

ostream& operator<<(ostream& os, Card& sourceCard)
{
	os << sourceCard.suit;
	os << " ";
	os << sourceCard.rank;
	os << " ";
	os << sourceCard.location;
	return os;
}

Player::Player()
{
	name = "name";
	id = new int[5];
	for(int i = 0; i < 5; i++)
		id[i] = 0;
	hand = Stack<Card>();
}

Player::~Player()
{
	if(id != NULL)
		//delete[] id;
	id = NULL;
}

bool Player::setName(string newName)
{
	name = newName;
	return true;
}

string Player::getName() const
{
	return name;
}

bool Player::setID(int *newID)
{
	for(int i = 0; i < 5; i++)
		id[i] = newID[i];
	return true;
}

int* Player::getID() const
{
	return id;
}

bool Player::giveCard(Card card)
{
	return hand.push(card);
}

bool Player::setHand(Stack<Card> newHand)
{
	hand = newHand;
	return true;
}

Stack<Card> Player::getHand() const
{
	return hand;
}

ifstream& operator>>(ifstream& ifs, Player& sourcePlayer)
{
	char temp;
	ifs >> sourcePlayer.name;
	for(int i = 0; i < 5; i++)
	{
		ifs >> temp;
		sourcePlayer.id[i] = temp - '0';
	}	
	return ifs;
}

ostream& operator<<(ostream& os, Player& sourcePlayer)
{
	os << sourcePlayer.name;
	os << " [";
	for(int i = 0; i < 5; i++)
		os << sourcePlayer.id[i];
	os << "]";
	return os;
}
