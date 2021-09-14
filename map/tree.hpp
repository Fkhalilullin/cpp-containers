#ifndef TREE_HPP
#define TREE_HPP


#include "../vector/swap.hpp"
#include <queue>
#include <iostream>

enum Color { BLACK, RED };

template < class U >
struct Node {
	U		_value;
	bool	color;
	Node*	left;
	Node*	right;
	Node*	parent;

	Node(const U value) {
		this->_value = value;
		left = right = parent = NULL;
		this->color = RED;
	}

	Node<U> *uncle() {
    	if (parent == NULL or parent->parent == NULL)
      		return NULL; 
    	if (parent->isOnLeft())
      		return parent->parent->right;
    	else
      		return parent->parent->left;
  	}

	bool isOnLeft() { return this == parent->left; }
 
  	Node<U> *sibling() {
		if (parent == NULL)
			return NULL; 
    	if (isOnLeft())
      		return parent->right;
    	return parent->left;
  	}

	void moveDown(Node<U> *nParent) {
		if (parent != NULL) {
			if (isOnLeft()) 
				parent->left = nParent;
			else 
				parent->right = nParent;
		}
		nParent->parent = parent;
		parent = nParent;
 	}
 
	bool hasRedChild() {
    	return (left != NULL && left->color == RED) ||
           	(right != NULL && right->color == RED);
	}
};

template < class T, class Alloc = std::allocator<Node<T> > >
class RBTree {
public:
	typedef T			value_type;
	typedef Alloc		nodeAllocator;
private:
  	Node<value_type>	*root;
	nodeAllocator		_nodeAllocator;

  	void leftRotate(Node<value_type> *x) {
		Node<value_type> *nParent = x->right;
	
		if (x == root)
			root = nParent;
		x->moveDown(nParent);
		x->right = nParent->left;
		if (nParent->left != NULL)
			nParent->left->parent = x;
		nParent->left = x;
  	}
 
	void rightRotate(Node<value_type> *x) {
		Node<value_type> *nParent = x->left;
	
		if (x == root)
			root = nParent;
	
		x->moveDown(nParent);
		x->left = nParent->right;
		if (nParent->right != NULL)
			nParent->right->parent = x;
		nParent->right = x;
	}
 
	void swapColors(Node<value_type> *x1, Node<value_type> *x2) {
		bool temp;
		temp = x1->color;
		x1->color = x2->color;
		x2->color = temp;
	}
 
	void swapValues(Node<value_type> *u, Node<value_type> *v) {
		value_type temp;
		temp = u->_value;
		u->_value = v->_value;
		v->_value = temp;
	}
 
	void fixRedRed(Node<value_type> *x) {
		if (x == root) {
			x->color = BLACK;
			return;
		}

		Node<value_type> *parent = x->parent;
		Node<value_type> *grandparent = parent->parent;
		Node<value_type> *uncle = x->uncle();
 
		if (parent->color != BLACK) {
			if (uncle != NULL && uncle->color == RED) {
				parent->color = BLACK;
				uncle->color = BLACK;
				grandparent->color = RED;
				fixRedRed(grandparent);
			} 
			else {
				if (parent->isOnLeft()) {
					if (x->isOnLeft())
						swapColors(parent, grandparent); 
					else {
						leftRotate(parent);
						swapColors(x, grandparent);
					}
					rightRotate(grandparent);
				} 
				else {
					if (x->isOnLeft()) {
						rightRotate(parent);
						swapColors(x, grandparent);
					} else
						swapColors(parent, grandparent);
					leftRotate(grandparent);
				}
			}
		}
	}
 
	Node<value_type> *successor(Node<value_type> *x) {
    	Node<value_type> *temp = x;
 		
		while (temp->left != NULL)
			temp = temp->left;
    	return temp;
  	}
 
	Node<value_type> *BSTreplace(Node<value_type> *x) {
		if (x->left != NULL and x->right != NULL)
			return successor(x->right);
		if (x->left == NULL and x->right == NULL)
			return NULL;
		if (x->left != NULL)
			return x->left;
		else
			return x->right;
	}
 
	void deleteNode(Node<value_type> *v) {
    	Node<value_type> *u = BSTreplace(v);
		Node<value_type> *parent = v->parent;

    	bool uvBlack = ((u == NULL || u->color == BLACK) && (v->color == BLACK));

		if (u == NULL) {
			if (v == root)
				root = NULL; 
			else {
				if (uvBlack) 
					fixDoubleBlack(v);
				else {
					if (v->sibling() != NULL)
						v->sibling()->color = RED;
				}
				if (v->isOnLeft()) 
					parent->left = NULL;
				else 
					parent->right = NULL;
			}
			_nodeAllocator.destroy(v);
			return ;
		}
		if (v->left == NULL or v->right == NULL) {
			if (v == root) {
				v->_value = u->_value;
				v->left = v->right = NULL;
				_nodeAllocator.destroy(u);
			} 
			else {
				if (v->isOnLeft()) 
					parent->left = u;
				else 
					parent->right = u;
				_nodeAllocator.destroy(v);
				u->parent = parent;
				if (uvBlack) {
					fixDoubleBlack(u);
				} else 
					u->color = BLACK;
				
			}
			return;
		}
    	swapValues(u, v);
    	deleteNode(u);
	}
 
	void fixDoubleBlack(Node<value_type> *x) {
		if (x == root)
			return;
	
		Node<value_type> *sibling = x->sibling();
		Node<value_type> *parent = x->parent;
		if (sibling == NULL)
			fixDoubleBlack(parent); 
		else {
			if (sibling->color == RED) {
				parent->color = RED;
				sibling->color = BLACK;
				if (sibling->isOnLeft())
					rightRotate(parent);
				else
					leftRotate(parent);
				fixDoubleBlack(x);
			} 
			else {
				if (sibling->hasRedChild()) {
					if (sibling->left != NULL and sibling->left->color == RED) {
						if (sibling->isOnLeft()) {
							sibling->left->color = sibling->color;
							sibling->color = parent->color;
							rightRotate(parent);
						} 
						else {
							sibling->left->color = parent->color;
							rightRotate(sibling);
							leftRotate(parent);
						}
					} 
					else {
						if (sibling->isOnLeft()) {
							sibling->right->color = parent->color;
							leftRotate(sibling);
							rightRotate(parent);
						} 
						else {
							sibling->right->color = sibling->color;
							sibling->color = parent->color;
							leftRotate(parent);
						}
					}
					parent->color = BLACK;
				} 
				else {
					sibling->color = RED;
					if (parent->color == BLACK)
						fixDoubleBlack(parent);
					else
						parent->color = BLACK;
				}
			}
		}
	}
 
	void levelOrder(Node<value_type> *x) {
		if (x == NULL)
			return;
	
		std::queue<Node<value_type> *> q;
		Node<value_type> *curr;
	
		q.push(x);
	
		while (!q.empty()) {
		curr = q.front();
		q.pop();
	
		std::cout << curr->_value << " ";
	
		if (curr->left != NULL)
			q.push(curr->left);
		if (curr->right != NULL)
			q.push(curr->right);
		}
	}
 
	void inorder(Node<value_type> *x) {
		if (x == NULL)
		return;
		inorder(x->left);
		std::cout << x->_value << " ";
		inorder(x->right);
	}
 
public:

	RBTree() { root = NULL; }
 
	Node<value_type> *getRoot() { return root; }
  
	Node<value_type> *search(int n) {
		Node<value_type> *temp = root;

		while (temp != NULL) {
			if (n < temp->_value) {
				if (temp->left == NULL)
					break;
				else
					temp = temp->left;
			} 
			else if (n == temp->_value)
				break;
			else {
				if (temp->right == NULL)
					break;
				else
					temp = temp->right;
			}
		}
		return temp;
	}
 
	void insert(value_type n) {
		// Node<value_type> *newNode = new Node<value_type>(n);
		Node<value_type> *newNode = _nodeAllocator.allocate(1);
		_nodeAllocator.construct(newNode, n);
		if (root == NULL) {
			newNode->color = BLACK;
			root = newNode;
		} 
		else {
			Node<value_type> *temp = search(n);
		
			if (temp->_value == n)
				return;
			newNode->parent = temp;
			if (n < temp->_value)
				temp->left = newNode;
			else
				temp->right = newNode;
			fixRedRed(newNode);
		}
	}
 
	void deleteByVal(value_type n) {
		if (root == NULL)
			return;
	
		Node<value_type> *v = search(n);
	
		if (v->_value != n) {
			std::cout << "No node found to delete with value:" << n << std::endl;
			return;
		}
		deleteNode(v);
	}
 
	void printInOrder() {
		std::cout << "Inorder: " << std::endl;
		if (root == NULL)
			std::cout << "Tree is empty" << std::endl;
		else
			inorder(root);
		std::cout << std::endl;
	}
	
	void printLevelOrder() {
		std::cout << "Level order: " << std::endl;
		if (root == NULL)
			std::cout << "Tree is empty" << std::endl;
		else
			levelOrder(root);
		std::cout << std::endl;
	}
};

#endif