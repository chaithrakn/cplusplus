#include <iostream>
#include "intSLL.h"

using namespace std;

// TODO: Use try-catch for isEmpty() everywhere.

void IntSLList::addToHead(int data)
{
	head = new IntSLLNode(data, head);
	if (tail == 0) {
		tail = head; // Inserting the first node. head and tail point to
			     // same node.
	}
}

void IntSLList::addToTail(int data)
{
	if (tail != 0) {
		tail->next = new IntSLLNode(data);
		tail = tail->next;
	} else {
		head = tail = new IntSLLNode(data); // First node.
	}
}

void IntSLList::printList()
{
	//cout << head->info << " " << tail->info << endl;
	if (isEmpty() == true) {
		cout << "printList:List is empty." << endl;
		return;
	} else {
		for (IntSLLNode *ptr = head; ptr != 0; ptr = ptr->next) {
			cout << ptr->info << " " ;
		}
		cout << endl;
	}
}

int IntSLList::deleteFromHead() {
	if (!isEmpty()) {
		int data = head->info;
		IntSLLNode *delnode = head;
		
		if (head == tail) { // Deleting the last node.
			head = tail = 0;
		} else {
			head = head->next;
		}

		delete delnode;
		return data;
	} else {
		cout << "deleteFromHead:List is empty." << endl; 
	}
}

int IntSLList::deleteFromTail() {
	if (!isEmpty()) {
		int data = tail->info;
		if (head == tail) {
			head = tail = 0;
			delete tail;
			return data;
		} else {
			IntSLLNode *ptr = head;
			while (ptr->next != tail) {
        	                ptr = ptr->next;
	                }
			ptr->next = 0;
			delete tail;
			tail = ptr;
			return data;
		}	
	} else {
		cout << "deleteFromTail:List is empty." << endl;
	}
}

// TODO: this version does not work if there are consecutive occurences of value.
void IntSLList::deleteNode(int value) {
	if (!isEmpty()) {
		// Only one node in list
		cout << head->info << " " << tail->info << endl;
		if ((head == tail) && head->info == value) {
			delete head;
			head = tail = 0;
		} else if (head->info == value) {
			IntSLLNode *delnode = head;
			head = head->next;
			delete delnode;
		}
		IntSLLNode *prev, *ptr;
		for (prev = head, ptr = head->next; ptr != 0; ptr=ptr->next, prev=prev->next) {
			if ((ptr->info == value) && (ptr == tail)) {	
				tail = prev;
				tail->next = 0;
				delete ptr;
			} else if (ptr->info == value) {
				prev->next = ptr->next;
				delete ptr;
				ptr = prev->next;
			}
		}
		
	} else {
		cout << "deleteNode:List is empty." << endl;
	}
}

bool IntSLList::isInList(int value) const
{
	for (IntSLLNode *ptr = head; ptr != 0; ptr = ptr->next) {
		if (ptr->info == value) {
			return true;
		} 
	}
	return false;
}

// merge ordered list1 and list2 into list3
void IntSLList::mergeOrdered(IntSLList *l1, IntSLList *l2)
{
	IntSLLNode *list1 = l1->head, *list2 = l2->head;
	
	// When list3 was created, head and tail were made 0. Initialize them first.
	if (list1->info == list2->info) {
		head = new IntSLLNode(list1->info);
                list1 = list1->next;
		list2 = list2->next;
	} else if (list1->info < list2->info) {
		head = new IntSLLNode(list1->info);
		list1 = list1->next;
	} else {
		head = new IntSLLNode(list2->info);
		list2 = list2->next;
	}
	tail = head;
	IntSLLNode *ptr = head;

	while (list1 && list2) {
		if (list1->info == list2->info) {
			ptr->next = new IntSLLNode(list1->info);
                        list1 = list1->next;
			list2 = list2->next;
                        tail = ptr->next;
		} else if (list1->info < list2->info) {
			ptr->next = new IntSLLNode(list1->info);
			list1 = list1->next;
			tail = ptr->next;
		} else {
			ptr->next = new IntSLLNode(list2->info);
                        list2 = list2->next;
                        tail = ptr->next;
		}
		ptr = ptr->next;
	}

	// if one of the lists was longer than the other
	while (list1 != 0) {
		ptr->next = new IntSLLNode(list1->info);
                list1 = list1->next;
                tail = ptr = ptr->next;
	}

	while (list2 != 0) {
		ptr->next = new IntSLLNode(list2->info);
                list2 = list2->next;
                tail = ptr = ptr->next;
	}
}

int main() {
	IntSLList *list1 = new IntSLList();
	list1->addToTail(3);
	list1->addToTail(7);
	list1->addToTail(12);

	list1->printList();

	IntSLList *list2 = new IntSLList();
        list2->addToTail(1);
        list2->addToTail(2);
        list2->addToTail(3);
	list2->addToTail(9);
	list2->addToTail(11);
	list2->addToTail(14);

	list2->printList();

	IntSLList *list3 = new IntSLList();
	list3->mergeOrdered(list1, list2);

	list3->printList();

	/* list1->deleteFromHead();
	list1->deleteFromHead();
	list1->deleteFromHead();
	list1->deleteFromHead(); */

	/* list1->deleteFromTail();
	list1->deleteFromTail();
	list1->deleteFromTail();
	list1->deleteFromTail();
	list1->deleteFromTail(); */

	//list1->deleteNode(13);
	if (list1->isInList(9)) {
		cout << "10 is in list" << endl;
	}
	
	list1->printList();
}
