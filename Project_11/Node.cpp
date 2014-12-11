#include "Node.h"

template<class T>
Node<T>::Node(T t, Node<T>* n)
{
	data = t;
	next = n;
}
