class IntSLLNode {
public:
	int info;
	IntSLLNode *next;
	IntSLLNode (int data, IntSLLNode *ptr = 0) {
		info = data;
		next = ptr;
	}
};

class IntSLList {
public:
	IntSLList() {
		head = tail = 0;
	}
	~IntSLList();

	bool isEmpty() {
		if (!head) {
			// Can add an assert to check that tail == 0.
			return true;
		}
		return false;
	}

	void addToHead(int);
	void addToTail(int);
	int deleteFromHead(); //delete head and return its info
	int deleteFromTail();
	void deleteNode(int);
	bool isInList(int) const;
	void printList();
	void mergeOrdered(IntSLList *list1, IntSLList *list2);
	bool deleteIth(int i);

private:
	IntSLLNode *head, *tail;

};
