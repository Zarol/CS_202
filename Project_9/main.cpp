#include "Queue.h"

int main()
{
	int temp;

	Queue q(4);
	q.enqueue(1);
	cout << q << endl;
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	cout << q << endl;
	
	q.dequeue(temp);
	cout << temp << endl;
	cout << q << endl;

	Queue q2(q);
	cout << q2 << endl;

	cout << (q2 == q) << endl;
	
	Queue q3(4);
	q3 = q2;
	cout << q3 << endl;
	cout << (q3 == q2) << endl;
	return 0;
}
