template <class T>
class DLLNode {
public:
	DLLNode() {
		next = prev = 0;
	}

	DLLNode(const T& val, DLLNode *n = 0, DLLNode *p = 0) {
		info = val; next = n; prev = p;
	}
	T info;
	DLLNode *next, *prev;
};

template <class T>
class DLList {
public:
	DLList() {
		head = tail = 0;
	}
	void addToTail(const T&);
	T deleteFromTail();
	void printList();
private:
	DLLNode<T> *head, *tail;
};
