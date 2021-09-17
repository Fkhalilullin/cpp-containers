#ifndef TREE_HPP
#define TREE_HPP

#include "bidirectional_iterator.hpp"
#include "../vector/reverse_iterator.hpp"
#include "../vector/swap.hpp"

namespace ft
{
	template <typename T>
	struct Node;

	template <typename T, typename Compare, typename Alloc, typename NAlloc>
	class RBTree;
}

namespace ft {

	template <typename T>
	struct Node {
		T		*value;
		bool	color;
		Node	*left;
		Node	*right;
		Node	*parent;

		Node(const T *value) {
			this->value = value;
			left = right = parent = NULL;
			this->color = true;
		}
	};

	template <typename T, typename Compare = std::less<T>, typename Alloc = std::allocator<T>, typename NAlloc = std::allocator<Node<T> > >
	class RBTree {
	public:
		typedef T															value_type;
		typedef Alloc														allocator_type;
		typedef NAlloc														nalloc_type;
		typedef const T														&const_reference;
		typedef T															*pointer;
		typedef const T														*const_pointer;
		typedef Compare														compare_type;
		typedef typename ft::bidirectional_iterator<T, T*, T&>				iterator;
		typedef typename ft::bidirectional_iterator<T, const T*, const T&>	const_iterator;
		typedef typename ft::reverse_iterator<iterator>						reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		typedef	ptrdiff_t													difference_type;
		typedef size_t														size_type;

	public:
		explicit RBTree(const compare_type comp = Compare(), const allocator_type &alloc = Alloc(), const nalloc_type &nalloc = NAlloc()) :
		_compare(comp), _allocator(alloc), _nodeAllocator(nalloc), _root(NULL), _size(0) {
			_end = _nodeAllocator.allocate(1);
			_nodeAllocator.construct(_end, Node<value_type>(NULL));
		}	

		~RBTree() {
			clear();
			_nodeAllocator.destroy(_end);
			_nodeAllocator.deallocate(_end, 1);
		}

		RBTree(const RBTree &c) : _compare(c._compare), _allocator(c._allocator), _nodeAllocator(c._nodeAllocator), _root(NULL),  _size(0) {
			_end = _nodeAllocator.allocate(1);
			_nodeAllocator.construct(_end, Node<value_type>(NULL));
			insert(c.begin(), c.end());
		}

		RBTree &operator=(const RBTree &c) {
			if(this == &c)
				return (*this);
			_compare = c._compare;
			_allocator = c._allocator;
			_nodeAllocator = c._nodeAllocator;
			insert(c.begin(), c.end());
			return(*this);
		}

		template <class InputIterator>
  		RBTree(InputIterator first, InputIterator last, const compare_type comp = Compare(), 
	  			const allocator_type &alloc = Alloc(), const nalloc_type &nalloc = NAlloc()) :
		_compare(comp), _allocator(alloc), _nodeAllocator(nalloc), _root(NULL), _size(0) {
			_end = _nodeAllocator.allocate(1);
			_nodeAllocator.construct(_end, Node<value_type>(NULL));
			insert(first, last);
		}

		// Iterators:
		iterator		begin() {
			if(!_root || !_size)
				return (end());
			Node<value_type> *tmp = _root;
			while(tmp->left)
				tmp = tmp->left;
			return(iterator(tmp));
		}

		const_iterator	begin() const {
			if(!_root || !_size)
				return (end());
			Node<value_type> *tmp = _root;
			while(tmp->left)
				tmp = tmp->left;
			return(iterator(tmp));
		}

		iterator		end() { return iterator(_end); }
		const_iterator	end() const { return const_iterator(_end); }

		reverse_iterator		rbegin() { return(reverse_iterator(end())); }
		const_reverse_iterator	rbegin() const {	return(const_reverse_iterator(end())); }

		reverse_iterator		rend() { return(reverse_iterator(begin())); }
		const_reverse_iterator	rend() const { return(const_reverse_iterator(begin())); }

		// Capacity:
		bool empty () const {
			if (_size == 0)
				return true;
			return false;
		}

		size_type size() const { return _size; }

		size_type max_size() const {
			size_type first = _allocator.max_size();
			size_type second = _nodeAllocator.max_size();
			return first < second ? first : second;
		}

		//Modifiers:
		pair<iterator, bool> insert(const_reference val) {
			if(_root)
				_root->parent = NULL;

			pointer p = _allocator.allocate(1);
			_allocator.construct(p, val);

			node<value_type> *no = _nodeAllocator.allocate(1);
			_nodeAllocator.construct(no, Node<value_type>(p));

			if(!_root) {
				_size++;
				_root = no;
				_root->color = false;
				return (ft::make_pair(iterator(_root), true));
			}

			node<value_type> *res = _move(val);

			// if(*res->value == val)
			if(!_compare(*res->value, val) && !_compare(val, *res->value)) {
				_clear(no);
				_root->parent = _end;
				_end->left = _root;
				return (ft::make_pair(iterator(res), false));
			}
			_size++;
			if(_compare(*res->value, val))
				res->right = no;
			else
				res->left = no;
			no->parent = res;

			_balance(no);

			_root->parent = _end;
			_end->left = _root;
			
			return (ft::make_pair(iterator(no), true));
		}
		// iterator insert(iterator position, const value_type &val);
		// template <typename InputIterator>
		// void insert(InputIterator first, InputIterator last, 
		// typename ft::enable_if<ft::is_input_iterator_tag<typename InputIterator::iterator_category>::value>::type* = NULL);
		// void erase(iterator it);
		// size_type erase(const value_type &value);
		// void erase (iterator first, iterator last);

		void swap(RBTree &c) {
			ft::swap(_compare, c._compare);
			ft::swap(_allocator, c._allocator);
			ft::swap(_nodeAllocator, c._nodeAllocator);
			ft::swap(_end, c._end);
			ft::swap(_root, c._root);
			ft::swap(_size, c._size);
		}

		void clear() {
			if(!_size)
				return ;
			_size = 0;
			_clear(_root);
			_root = NULL;
		}

		// Observers:
		compare_type	value_comp() const { return _compare; }

		// Operations:
		iterator		find(const value_type &value) {
			Node<value_type> *tmp = _move(value);

			if(!_compare(*tmp->value, value) && !_compare(value, *tmp->value))
				return(iterator(tmp));
			return(end());
		}

		const_iterator	find(const value_type &value) const {
			Node<value_type> *tmp = _move(value);

			if(!_comp(*tmp->value, value) && !_comp(value, *tmp->value))
				return(const_iterator(tmp));
			return(end());
		}

		size_type 		count(const value_type &value) const {
			iterator it = find(value);
			if(it == end())
				return (0);
			return (1);
		}

		iterator		lower_bound(const value_type &value) { return iterator(_lower_bound(value, _root)); }
		const_iterator	lower_bound(const value_type &value) const { return const_iterator(_lower_bound(value, _root)); }

		iterator		upper_bound(const value_type &value) { return iterator(_upper_bound(value, _root)); }
		const_iterator	upper_bound(const value_type &value) const { return const_iterator(_upper_bound(value, _root)); }

		pair<const_iterator,const_iterator> equal_range(const value_type &value) const {
			const_iterator it = const_iterator(lower_bound(value));
			const_iterator it2 = const_iterator(upper_bound(value));

			return (ft::make_pair<const_iterator, const_iterator>(it, it2));
		}

		pair<iterator,iterator>             equal_range(const value_type &value) {
			const_iterator it = iterator(lower_bound(value));
			const_iterator it2 = iterator(upper_bound(value));

			return (ft::make_pair<iterator, iterator>(it, it2));
		}

		// Allocator:
		allocator_type get_allocator() const { return _allocator; }

	private:	
		void _clear(Node<value_type> *node) {
			if (!node)
				return;
			_clear(node->right);
			_clear(node->left);
			_allocator.destroy(node->value);
			_allocator.deallocate(node->value, 1);
			_nodeAllocator.destroy(node);
			_nodeAllocator.deallocate(node, 1);
		}

		Node<value_type> *_move(const_reference val) const {
			Node<value_type> *x = _root;
			Node<value_type> *y = NULL;
			while(x)
			{
				y = x;
				if(_compare(*x->value, val))
					x = y->right;
				else if (_compare(val, *x->value))
					x = y->left;
				else
					return (y);
			}
			return (y);
		}

		Node<value_type> *_lower_bound(value_type const &value, Node<value_type> *the_node) const {
			if (!the_node)
				return(_end);
		
			if(_compare(*the_node->value, value))
				return(_lower_bound(value, the_node->right));
			else
			{
				Node<value_type> *left = _lower_bound(value, the_node->left);
				return(left != _end ? left : the_node);
			}
		}

		Node<value_type> *_upper_bound(value_type const &value, Node<value_type> *the_node) const {
			if (!the_node)
				return(_end);
			
			if(!_compare(value, *the_node->value))
				return(_upper_bound(value, the_node->right));
			else
			{
				Node<value_type> *left = _upper_bound(value, the_node->left);
				return(left != _end ? left : the_node);
			}
		}

		void _balance(node<value_type> *the_node) {
			if(!the_node)
				return;
			node<value_type> *parent = NULL;
			node<value_type> *grandpa = NULL;
			node<value_type> *uncle = NULL;

			while ((the_node != _root) && (the_node->color != false) &&
				(the_node->parent->color == true)) {
				parent = the_node->parent;
				grandpa = the_node->parent->parent;

				if (parent == grandpa->left) {
					uncle = grandpa->right;

					if (uncle && uncle->color == true) {
						grandpa->color = true;
						parent->color = false;
						uncle->color = false;
						the_node = grandpa;
					}
					else {
						if (the_node == parent->right) {
							_rotate_left(parent);
							the_node = parent;
							parent = the_node->parent;
						}
						_rotate_right(grandpa);
						ft::swap(parent->color, grandpa->color);
						the_node = parent;
					}
				}
				else {
					uncle = grandpa->left;
		
					if (uncle && uncle->color == true) {
						grandpa->color = true;
						parent->color = false;
						uncle->color = false;
						the_node = grandpa;
					}
					else {
						if (the_node == parent->left) {
							_rotate_right(parent);
							the_node = parent;
							parent = the_node->parent;
						}
						_rotate_left(grandpa);
						ft::swap(parent->color, grandpa->color);
						the_node = parent;
					}
				}
			}
			_root->color = false;
		}

	private:
		compare_type				_compare;
		allocator_type 				_allocator;
		nalloc_type					_nodeAllocator;
		Node<value_type>			*_end;
		Node<value_type>			*_root;
		size_type					_size;
	};

}


#endif