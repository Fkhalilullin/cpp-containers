#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include <iterator>
#include "tree.hpp"

namespace ft {
    template <class T, class Node>
    class bidirectional_iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
    public:
        typedef T															value_type;
		typedef T*															pointer;
		typedef T&															reference;
		typedef bidirectional_iterator<T, Node>								It;
		typedef std::ptrdiff_t												difference_type;
		typedef typename std::bidirectional_iterator_tag					iterator_category;

		bidirectional_iterator() : _node(0) {}

		bidirectional_iterator(Node *node) : _node(node) {}

		bidirectional_iterator(bidirectional_iterator<T, Node> const &rhs) : _node ( rhs.getNode() ) {}

		virtual ~bidirectional_iterator() {}

		It	&operator=(const It &rhs) {
			if (this == &rhs)
				return *this;
			_node = rhs._node;
			return *this;
		}

		reference				operator*() { return _node->_value; }
		pointer					operator->() { return &_node->_value; }

		It				operator++() {
			Node *p;
			if(_node->right)
			{
				_node = _node->right;
				while(_node->left)
					_node = _node->left;
			}
			else
			{
				p = _node->parent;
				while(p && _node == p->right)
				{
					_node = p;
					p = p->parent;
					
				}
				_node = _node->parent;		
			}
			return(*this);
		} 

		It				operator--() {
			Node *p;

			if(_node->left)
			{
				_node = _node->left;
				while(_node->right)
					_node = _node->right;
			}
			else
			{
				p = _node->parent;
				while(p && _node == p->left)
				{
					_node = p;
					p = p->parent;
				}
				_node = _node->parent;		
			}
			return(*this);
	}
		It				operator++(int) { It it(*this); ++(*this); return it; }
		It				operator--(int) { It it(*this); --(*this); return it; }

		Node* getNode() const { return this->_node; }
	private:
		// Tree	_ptr;
		Node	*_node;
    };

    // template <class T, class Tree>
	// bool	operator!=(const bidirectional_iterator<T, Tree> &lhs, const bidirectional_iterator<T, Tree> &rhs) {
	// 	return (!(lhs == rhs));
	// }

    // template <class T, class Tree>
	// bool	operator==(const bidirectional_iterator<T, Tree> &lhs, const bidirectional_iterator<T, Tree> &rhs) {
	// 	return (lhs.getPointer() == rhs.getPointer());
	// }
}

#endif