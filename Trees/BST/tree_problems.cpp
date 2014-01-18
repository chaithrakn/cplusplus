/* Tree problems - untested */

/* When to use recursion? 
 * When moving through multiple branches of the tree or examining 
 * some special pattern of nodes.
 */

#include "BST.h"

/* To find lowest common ancestor:
 * Find a node whose value is between  value1 and value2.
 * If value1 < value and value2 < value move left
 * If value1 > value and value2 > value move right 
 */

T* BST<T>::lowestCommonAncestor(const T& value1, T& value2) {
	BSTNode<T> *p = root;u
	if (!p) { cout << "Error";
	          return NULL;  }	

	while (p != 0) {
		if (value1 < p->key && value2 < p->key) {
			p = p->left;
		} else if (value1 > p->key && value2 > p->key) {
			p = p->right;
		} else {
			return p->key;
		}
	}

	// No common ancestor except root
	return root->key;
}

/* Tree size  - number of nodes in the tree*/

int BST<T>::tree_size(BSTNode<T> *node) {
	if (node == 0) return 0;
	else return (tree_size(node->left) + 1 + tree_size(node->right);
}

/* Find if right subtree or left subtree is bigger */
void BST<T>::bigger_subtree() {
	int left, right;
	if (root == 0) {
		cout << "tree is empty";
	} else {
		left = tree_size(root->left);
		right = tree_size(root->right);
		{
			left > right ...
		}
	}
}

/* Count number of leaves */

