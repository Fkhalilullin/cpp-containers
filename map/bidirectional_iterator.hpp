#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include "tree.hpp"
#include <iterator>

namespace ft {
	template <typename T>
	struct Node;
}

namespace ft {
	
	template<typename T, typename Pointer, typename Reference>
	class bidirectional_iterator {
	public:

		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef Pointer							pointer;
		typedef Reference						reference;

	private:	
		Node<value_type> *_point;
	
	public:
	
		bidirectional_iterator() : _point (NULL) {}

		~bidirectional_iterator() {}

		explicit bidirectional_iterator(Node<value_type> *point) : _point(point) {}

		bidirectional_iterator(bidirectional_iterator<T, Pointer, Reference> const &c) : _point(c.base()) {}

		Node<value_type> *base() const { return _point; }

		bidirectional_iterator &operator=(bidirectional_iterator<T, Pointer, Reference> const &c) {
			_point = c.base();
			return *this;
		}

		reference operator*() const { return *_point->value; }

		pointer operator->() const { return _point->value; }

		bidirectional_iterator operator++() {
			Node<value_type> *p;

			if(_point->right)
			{
				_point = _point->right;
				while(_point->left)
					_point = _point->left;
			}
			else
			{
				p = _point->parent;
				while(p && _point == p->right)
				{
					_point = p;
					p = p->parent;
					
				}
				_point = _point->parent;		
			}
			return(*this);
		}

		const bidirectional_iterator operator++(int) {
			bidirectional_iterator it(*this);
			++(*this);
			return it;
		}

		bidirectional_iterator operator--() {
			Node<value_type> *p;

			if(_point->left)
			{
				_point = _point->left;
				while(_point->right)
					_point = _point->right;
			}
			else
			{
				p = _point->parent;
				while(p && _point == p->left)
				{
					_point = p;
					p = p->parent;
				}
				_point = _point->parent;		
			}
			return(*this);
		}

		const bidirectional_iterator operator--(int) {
			bidirectional_iterator it(*this);
			--(*this);
			return (it);
		}
	};

	template<typename T, typename FPointer, typename FReference, typename SPointer, typename SReference>
	bool operator==(bidirectional_iterator<T, FPointer, FReference> const &first, bidirectional_iterator<T, SPointer, SReference> const &second) {
		return(first.base() == second.base());
	}

	template<typename T, typename FPointer, typename FReference, typename SPointer, typename SReference>
	bool operator!=(bidirectional_iterator<T, FPointer, FReference> const &first, bidirectional_iterator<T, SPointer, SReference> const &second) {
		return(first.base() != second.base());
	}
}

#endif