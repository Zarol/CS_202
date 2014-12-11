#ifndef QUEUE_H_
#define QUEUE_H_
#include <iostream>
#include "Node.h"

using namespace std;

template <typename T>
class Node;

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
#endif
