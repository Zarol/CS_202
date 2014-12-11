#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include "Node.h"

using namespace std;

template <typename T>
class Node;

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
#endif
