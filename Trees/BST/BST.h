#include <queue>

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

using namespace std;

// class Queue is publicly inherited from STL queue
template<class T>
class Queue : public queue<T> {
// Create a new function called dequeue()
public: 
	T dequeue() {
		T tmp = queue<T>::front();
		queue<T>::pop();
		return tmp;
	}
};

template <class T>
class BSTNode {
public:
	BSTNode() {
		left = right = 0;
	}

	BSTNode(const T& el, BSTNode *l = 0, BSTNode *r = 0) {
		key = el;
		left = l;
		right = r;
	}
	T key;
	BSTNode<T> *left, *right, *parent;
};

template <class T>
class BST {
public:
	BST() {
		root = 0;
	}

	~BST() { }

	/* Basic operations */
	bool isEmpty() {
		return (root == 0);
	}

	void insertNode(const T&);
	T* search(const T&);
	void visit(BSTNode<T>*);

	void findAndDeleteByMerging(const T& el);
	void deleteByMerging(BSTNode<T>*&);

	/* Traversals */
	void inorder() {
		inorder(root); // Need indirection because we want to pass a value during recursion.
	}
	void inorder(BSTNode<T>*);

	void preorder() {
                preorder(root); // Need indirection because we want to pass a value during recursion.
        }
	void preorder(BSTNode<T>*);

	void postorder() {
                postorder(root); // Need indirection because we want to pass a value during recursion.
        }
	void postorder(BSTNode<T>*);

	void breadthFirst();

	/* Tree problems */
	unsigned int getLeafCount();
	unsigned int getLeafCount(BSTNode<T>*);

	unsigned int findHeight();
	unsigned int findHeight(BSTNode<T>*);
	
	bool isBST();
	bool isBST(BSTNode<T>*, int , int);

private:
	BSTNode<T> *root;
};

#endif
