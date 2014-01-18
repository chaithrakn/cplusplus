#include <iostream>
#include "genDLL.h"

using namespace std;

template <class T>
void DLList<T>::addToTail(const T& val)
{
	if (tail != 0) {
		tail->next = new DLLNode<T>(val, 0, tail);
		tail = tail->next;
	} else {
		head = tail = new DLLNode<T>(val);
	}
}

template <class T>
void DLList<T>::printList()
{
	for (DLLNode<T> *ptr = head; ptr != 0; ptr=ptr->next) {
		cout << ptr->info << " ";
	}
	cout << endl;
}

template <class T>
T DLList<T>::deleteFromTail()
{
	int ret;
	if (head == tail) {
		ret = head->info;
		delete head;
		head = tail = 0;
	} else {
		DLLNode<T> *delnode = tail;
		ret = tail->info;
		tail = tail->prev;
		tail->next = 0;
		delete delnode;
	}
	return ret;
}

int main() {
	DLList<int> list1;
	
	list1.addToTail(3);
	list1.addToTail(5);
	list1.addToTail(2);
	list1.addToTail(12);

	list1.printList();

	list1.deleteFromTail();
	list1.deleteFromTail();
	list1.deleteFromTail();
	list1.deleteFromTail();

	list1.printList();

}
