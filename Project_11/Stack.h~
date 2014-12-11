#ifndef STACK_H_
#define STACK_H_
#include <iostream>

using namespace std;

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
#endif
