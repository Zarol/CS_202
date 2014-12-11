#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

template <typename T>
class Node;
template <typename T>
class Queue;
template <typename T>
class List;
template <typename T>
class Stack;

template <typename T>
class Node{
	public:
		Node(T,Node<T>*);
		Node(const Node<T>&);
		T data;
		Node* next;
		friend class Queue<T>;
		friend class List<T>;
};

template <typename T>
class Queue{
        public:
                Queue();
                Queue(const Queue<T>&);
                ~Queue();
                Queue<T>& operator=(const Queue<T>&);
                bool enqueue(T);
                bool dequeue(T&);
                bool empty() const;
                bool full() const;
                bool clear();
                bool operator==(const Queue<T>&) const;
		void print() const;
                //friend ostream& operator<<(ostream&, const Queue<T>&);
        private:
                Node<T>* head;
		Node<T>* tail;
};

template <typename T>
class List{
        public:
                List();
                List(const List<T>&);
                ~List();
		bool gotoBeginning();
		bool gotoEnd();
		bool gotoNext();
                bool gotoPrior();
		bool insertAfter(T);
		bool insertBefore(T);
                bool remove(T&);
		bool replace(T);
		bool getCursor(T&) const;
                bool empty() const;
                bool full() const;
                bool clear();
		List<T>& operator=(const List<T>&);
		void print() const;
                //friend ostream& operator<<(ostream&, const List&);
                bool operator==(const List<T>&) const;
        private:
		Node<T>* head;
		Node<T>* cursor;
};

template <typename T>
class Stack {
        public:
                Stack(int = 10);
                Stack(const Stack<T>&);
                ~Stack();
                Stack<T>& operator=(const Stack<T>&);
		bool operator==(const Stack<T>&) const;
		void print() const;
		//friend ostream& operator<<(ostream&, const Stack<T>&);
                bool push(T);
                bool pop(T&);
                bool empty() const;
                bool full() const;
                bool clear();
        private:
                int max;
                int top;
                T* data;
};

class Card
{
	public: 
		Card();
		Card(string, int, string);
		Card(const Card&);
		~Card();
		bool setSuit(string);
		string getSuit() const;
		bool setRank(int);
		int getRank() const;
		bool setLocation(string);
		string getLocation() const;
		void reset();
		
		Card operator=(const Card&);
		bool operator>(const Card&) const;
		bool operator<(const Card&) const;
		friend bool operator>=(const Card&, const Card&);
		friend bool operator<=(const Card&, const Card&);
		friend ifstream& operator>>(ifstream&, Card&);
		friend ostream& operator<<(ostream&, Card&);

	private:
		string suit;
		int rank;
		string location;
};

class Player
{
	public:
		Player();
		~Player();
		bool setName(string);
		string getName() const;
		bool setID(int*);
		int* getID() const;
		bool giveCard(Card);
		bool setHand(Stack<Card>);
		Stack<Card> getHand() const;

		friend ifstream& operator>>(ifstream&, Player&);
		friend ostream& operator<<(ostream&, Player&);
	private:
		string name;
		int *id;
		Stack<Card> hand;
};
