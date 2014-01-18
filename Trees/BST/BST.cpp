#include "BST.h"
#include <iostream>
#include<limits.h>

using namespace std;

template<class T>
void BST<T>::insertNode(const T& el) {
	BSTNode<T> *newnode = new BSTNode<T>(el);
	BSTNode<T> *cur = root, *prev = 0;	
	if (cur == 0) {
		root = newnode;
	} else {
		while (cur != 0) {
			prev = cur;
			if (el < cur->key) { cur = cur->left; }
			else { cur = cur->right; }
		}
		if (el < prev->key) {
			prev->left = newnode;
		} else if (el > prev->key) {
			prev->right = newnode;
		}
	}
}

template<class T>
void BST<T>::visit(BSTNode<T> *p) {
        cout << p->key << " ";
}

template<class T>
T* BST<T>::search(const T& value) {
        BSTNode<T> *p = root;
        while(p) {
                if (p->key == value)
                  return &p->key;
                else
                  if (value < p->key) p = p->left;
                  else if (value > p->key) p = p->right;
        }
}

// Deletion
template<class T>
void BST<T>::findAndDeleteByMerging(const T& el) {
	BSTNode<T> *node = root, *prev = 0;

	if (!root) {
		cout << "Tree is empty;" << endl;
		return;
	}	
	while (node) {
		if (node->key == el) { 
		  break; 
		}
		prev = node; 
		if (el < node->key) { node = node->left; }
		else if (el > node->key) { node = node->right; }
	}

    if (node != 0 && node->key == el) {
	if (node == root) {
		deleteByMerging(root);
	} else if (node == prev->left) {
// Key here is that if the node to be deleted is not the root node, we are passing the appropriate 
// pointer if the node's parent to manipulate it directly in deleteByMerging().
		deleteByMerging(prev->left);
	} else {
		deleteByMerging(prev->right);
	}
    } else {
	cout << "The key you are searching for does not exist in the tree" << endl;
    } 
}

/* 
 * Here node == parent->left or parent->right.
 *
 * & out // reference to ...
   *(& out) // reference to pointer */
/* 
void myFunc(myStruct *&out)
It happens to be a reference to a pointer, which explains the semantics you're seeing; the called function can change the pointer in the calling context, since it has a reference to it.

So, to reiterate, the "operative symbol" here is not *&, that combination in itself doesn't mean a whole lot. The * is part of the type myStruct *, i.e. "pointer to myStruct", and the & makes it a reference, so you'd read it as "out is a reference to a pointer to myStruct".
*/
template<class T>
void BST<T>::deleteByMerging(BSTNode<T>*& node) {
	BSTNode<T> *tmp = node;
	
	// If no child nodes, make node NULL.
	// If only one node exists, the parent's pointer will point to node's lone child.
	
	if (node->right == 0) {
		node = node->left; // Assign the remaining child node to the parent
	} else if (node->left == 0) {
		node = node->right;
	} else { // node has both children
		// find rightmost element in node's left subtree
		tmp = tmp->left;
		while (tmp->right != 0) {
			tmp = tmp->right;
		}
		
		tmp->right = node->right; // rightmost el's right points to right subtree of node.
		tmp = node; // to be deleted
		node = node->left;
	}
	delete tmp;
}

// Traversals
template<class T>
void BST<T>::inorder(BSTNode<T> *p) {
	if (p) {
		inorder(p->left);
		visit(p);
		inorder(p->right);
	}
	cout << endl;
}

template<class T>
void BST<T>::preorder(BSTNode<T> *p) {
   if (p) {
	visit(p);
	preorder(p->left);
	preorder(p->right);
   }
}

template<class T>
void BST<T>::postorder(BSTNode<T> *p) {
   if (p) {
	postorder(p->left);
	postorder(p->right);
        visit(p);
   }
}

template<class T>
void BST<T>::breadthFirst() {
	BSTNode<T> *p = root, *tmp = 0;
	Queue<BSTNode<T>*> myq;
	if (p) { myq.push(p); }
	while (!myq.empty()) {
		tmp = myq.dequeue();
		visit(tmp);
		if (tmp->left) { myq.push(tmp->left); }
		if (tmp->right) { myq.push(tmp->right); }
	}
}

/* Tree problems */

template<class T>
unsigned int BST<T>::getLeafCount() {
	return getLeafCount(root);
}

template<class T>
unsigned int BST<T>::getLeafCount(BSTNode<T> *node) {
	if (node == 0) return 0;
	else if (node->left == 0 && node->right == 0) {
		return 1;
	} else {
		return (getLeafCount(node->left) + getLeafCount(node->right));
	}
}

template<class T>
unsigned int BST<T>::findHeight() {
        return findHeight(root);
}

template<class T>
unsigned int BST<T>::findHeight(BSTNode<T> *node) {
	if (node == 0) return 0;
	else {
		return(max(findHeight(node->left),findHeight(node->right)) + 1);
	}
}

/* Algorithm to find if the given tree is a BST */
/* 1. At node check if its left child is lesser than and right child is greater than 
 * current node. This method does not work because we are not comparing a node with
 * its grandparent.
 * 
 * 2. At each node: Check that the maxValue of its left subtree is less than the node's
 * value and the minValue of its right subtree is greater than the node's value.
 * This method is inefficient.
 *
 * 3. Correct and efficient: 
 * Use a recursive function and pass min and max. min is (node->data +1) and max is (node->data -1).
 * node->left must be less than or equal to max. 
 * node->right must be greater than or equal to min.
 */

template<class T>
bool BST<T>::isBST() {
	if (root == NULL) { 
		// Empty tree is a BST
		return true;
	} else {
     		return isBST(root, INT_MIN, INT_MAX);
	}
}

template<class T>
bool BST<T>::isBST(BSTNode<T> *node, int min, int max) {
	if (root == NULL) {
		return true;
	} else if (node->key < min || node->key > max) {
		return false;
	} else {
		return (isBST(node->left, min, (node->key - 1)) &&
		isBST(node->right, (node->key + 1), max));
	}
}

template<class T>
bool BST<T>::maxDepth(BSTNode<T> *node) {
	return 1 + max(maxDepth(node->left), maxDepth(node->right);
}

template<class T>
bool BST<T>::minDepth(BSTNode<T> *node) {
	return 1 + min(minDepth(node->left), minDepth(node->right));
}

template<class T>
bool BST<T>::isBanlanced() {
	return (maxDepth(root) - minDepth(root) <= 1) return true;
}

int main() {
	BST<int> tree;

	tree.insertNode(15); tree.insertNode(8); tree.insertNode(20);
	tree.insertNode(6); tree.insertNode(3); tree.insertNode(10);
	tree.insertNode(9); tree.insertNode(12); 
	tree.insertNode(17); tree.insertNode(23); tree.insertNode(16);
	tree.insertNode(18); tree.insertNode(21); tree.insertNode(25);

	//tree.inorder();
	//tree.preorder();
	tree.breadthFirst();
	cout << "Tree height:" << tree.findHeight() << endl;
	
	tree.findAndDeleteByMerging(8);
	cout << "After delete" << endl; 
	tree.breadthFirst();

	cout << "No of leaf nodes = " << tree.getLeafCount() << endl;
}
