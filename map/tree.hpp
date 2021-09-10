#ifndef TREE_HPP
#define TREE_HPP


#include "../vector/swap.hpp"
#include <queue>
enum Color { BLACK, RED };

template <class Key>
struct Node {
	Key		_key;
	bool	color;
	Node*	left;
	Node*	right;
	Node*	parent;

	Node(const Key key) {
		this->_key = key;
		left = right = parent = NULL;
		this->color = RED;
	}
};

template <class T> 
class RBtree {
public:
	RBtree() { root = NULL; }

	void insert(const T &n) { 
		Node<T> *pt = new Node<T>(n);
	
		root = BSTInsert(root, pt);
		fixViolation(root, pt);
	}

	void inorder() {  inorderHelper(root); }
	void levelOrder() { levelOrderHelper(root); }

	void rotateLeft(Node<T> *&root, Node<T> *&pt) {
		Node<T> *pt_right = pt->right;

    	pt->right = pt_right->left;
    	if (pt->right != NULL)
        	pt->right->parent = pt;
    	pt_right->parent = pt->parent;
    	if (pt->parent == NULL)
        	root = pt_right;
    	else if (pt == pt->parent->left)
        	pt->parent->left = pt_right;
    	else
			pt->parent->right = pt_right;
  		pt_right->left = pt;
		pt->parent = pt_right;
	}

    void rotateRight(Node<T> *&root, Node<T> *&pt) {
		Node<T> *pt_left = pt->left;
	
		pt->left = pt_left->right;
		if (pt->left != NULL)
			pt->left->parent = pt;
		pt_left->parent = pt->parent;
		if (pt->parent == NULL)
			root = pt_left;
		else if (pt == pt->parent->left)
			pt->parent->left = pt_left;
		else
			pt->parent->right = pt_left;
		pt_left->right = pt;
		pt->parent = pt_left;
	}

    void fixViolation(Node<T> *&root, Node<T> *&pt) { 
		Node<T> *parent_pt = NULL;
		Node<T> *grand_parent_pt = NULL;
	
		while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED)) {
			parent_pt = pt->parent;
			grand_parent_pt = pt->parent->parent;
	
			if (parent_pt == grand_parent_pt->left)
			{
				Node<T> *uncle_pt = grand_parent_pt->right;
	
				if (uncle_pt != NULL && uncle_pt->color == RED)
				{
					grand_parent_pt->color = RED;
					parent_pt->color = BLACK;
					uncle_pt->color = BLACK;
					pt = grand_parent_pt;
				}
				else
				{
					if (pt == parent_pt->right)
					{
						rotateLeft(root, parent_pt);
						pt = parent_pt;
						parent_pt = pt->parent;
					}
					rotateRight(root, grand_parent_pt);
					ft::swap(parent_pt->color, 
							grand_parent_pt->color);
					pt = parent_pt;
				}
			}
			else
			{
				Node<T> *uncle_pt = grand_parent_pt->left;
				if ((uncle_pt != NULL) && (uncle_pt->color == RED))
				{
					grand_parent_pt->color = RED;
					parent_pt->color = BLACK;
					uncle_pt->color = BLACK;
					pt = grand_parent_pt;
				}
				else
				{
					if (pt == parent_pt->left)
					{
						rotateRight(root, parent_pt);
						pt = parent_pt;
						parent_pt = pt->parent;
					}
					rotateLeft(root, grand_parent_pt);
					ft::swap(parent_pt->color, 
							grand_parent_pt->color);
					pt = parent_pt;
				}
			}
    	}
    	root->color = BLACK;
	}
private:
	Node<T>*	root;	
};

template <typename T>
void inorderHelper(Node<T> *root)
{
    if (root == NULL)
        return;
  
    inorderHelper(root->left);
    std::cout << root->_key << "  ";
    inorderHelper(root->right);
}

template <typename T>
void levelOrderHelper(Node<T> *root)
{
    if (root == NULL)
        return;
  
    std::queue<Node<T> *> q;
    q.push(root);
  
    while (!q.empty())
    {
        Node<T> *temp = q.front();
        std::cout << temp->_key << "  ";
        q.pop();
  
        if (temp->left != NULL)
            q.push(temp->left);
  
        if (temp->right != NULL)
            q.push(temp->right);
    }
}

template <typename T>
Node<T>* BSTInsert(Node<T>* root, Node<T> *pt)
{
    /* If the tree is empty, return a new node */
    if (root == NULL)
       return pt;
  
    /* Otherwise, recur down the tree */
    if (pt->_key < root->_key)
    {
        root->left  = BSTInsert(root->left, pt);
        root->left->parent = root;
    }
    else if (pt->_key > root->_key)
    {
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }
  
    /* return the (unchanged) node pointer */
    return root;
}







#endif