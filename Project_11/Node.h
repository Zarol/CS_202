#ifndef NODE_H_
#define NODE_H_
#include "Queue.h"
#include "List.h"

using namespace std;

template <typename T>
class Stack;

template <typename T>
class Queue;

template <typename T>
class List;

template <typename T>
class Node{
	public:
		Node(T,Node<T>*);
		T data;
		Node* next;
		friend class Queue<T>;
		friend class List<T>;
};
#endif
