#ifndef TREE_HPP
#define TREE_HPP

#include "../iterator/bidirectional_iterator.hpp"
#include "../iterator/reverse_iterator.hpp"
#include "../iterator/is_input_iterator_tag.hpp"
#include "../utility/swap.hpp"
#include "../utility/enable_if.hpp"
#include "../map/map.hpp"

namespace ft
{
	template <typename T>
	struct Node;

	template <typename T, typename Compare, typename Alloc, typename NAlloc>
	class RBTree;

	template <class Arg1, class Arg2, class Result>
  	struct binary_function;

	template <class T> 
	struct less;
}

namespace ft {

	template <typename T>
	struct Node {
		T		*value;
		bool	color;
		Node	*left;
		Node	*right;
		Node	*parent;

		Node(T *value) {
			this->value = value;
			left = right = parent = NULL;
			this->color = true;
		}
	};

	template <typename T, typename Compare = ft::less<T>, typename Alloc = std::allocator<T>, typename NAlloc = std::allocator<Node<T> > >
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

		~RBTree() 
		{
			clear();
			_nodeAllocator.destroy(_end);
			_nodeAllocator.deallocate(_end, 1);
		}

		RBTree(const RBTree &c) : _compare(c._compare), _allocator(c._allocator), _nodeAllocator(c._nodeAllocator), _root(NULL),  _size(0) 
		{
			_end = _nodeAllocator.allocate(1);
			_nodeAllocator.construct(_end, Node<value_type>(NULL));
			insert(c.begin(), c.end());
		}

		RBTree &operator=(const RBTree &c) 
		{
			if(this == &c)
				return (*this);
			_compare = c._compare;
			_allocator = c._allocator;
			_nodeAllocator = c._nodeAllocator;
			insert(c.begin(), c.end());
			return(*this);
		}

		template <class InputIterator>
  		RBTree(InputIterator first, InputIterator last, const compare_type comp = Compare(), const allocator_type &alloc = Alloc(), const nalloc_type &nalloc = NAlloc()) :
		_compare(comp), _allocator(alloc), _nodeAllocator(nalloc), _root(NULL), _size(0) 
		{
			_end = _nodeAllocator.allocate(1);
			_nodeAllocator.construct(_end, Node<value_type>(NULL));
			insert(first, last);
		}

		iterator		begin() 
		{
			if(!_root || !_size)
				return (end());
			Node<value_type> *tmp = _root;
			while(tmp->left)
				tmp = tmp->left;
			return(iterator(tmp));
		}

		const_iterator	begin() const 
		{
			if(!_root || !_size)
				return (end());
			Node<value_type> *tmp = _root;
			while(tmp->left)
				tmp = tmp->left;
			return(const_iterator(tmp));
		}

		iterator		end() { return iterator(_end); }
		const_iterator	end() const { return const_iterator(_end); }

		reverse_iterator		rbegin() { return(reverse_iterator(end())); }
		const_reverse_iterator	rbegin() const {	return(const_reverse_iterator(end())); }

		reverse_iterator		rend() { return(reverse_iterator(begin())); }
		const_reverse_iterator	rend() const { return(const_reverse_iterator(begin())); }

		bool empty () const 
		{
			if (_size == 0)
				return true;
			return false;
		}

		size_type size() const { return _size; }

		size_type max_size() const 
		{
			size_type first = _allocator.max_size();
			size_type second = _nodeAllocator.max_size();
			return first < second ? first : second;
		}

		pair<iterator, bool> insert(const_reference val) 
		{
			if(_root)
				_root->parent = NULL;

			pointer p = _allocator.allocate(1);
			_allocator.construct(p, val);

			Node<value_type> *no = _nodeAllocator.allocate(1);
			_nodeAllocator.construct(no, Node<value_type>(p));

			if(!_root) {
				_size++;
				_root = no;
				_root->color = false;
				return (ft::make_pair(iterator(_root), true));
			}

			Node<value_type> *res = _move(val);

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

		iterator insert(iterator position, const value_type &val) 
		{
			(void)position;
			return insert(val).first;
		}

		template <typename InputIterator>
		void insert(InputIterator first, InputIterator last,
		typename ft::enable_if<ft::is_input_iterator_tag<typename InputIterator::iterator_category>::value>::type* = NULL) 
		{
			for(; first != last; ++first)
				insert(*first);
		}

		void erase(iterator it) 
		{
			_size--;
			_root->parent = NULL;
			Node<value_type> *no = _erase(it.base());
			_balance(no);
			if(_root)
			{
				_root->parent = _end;
				_end->left = _root;
			}
		}

		size_type erase(const value_type &value) 
		{
			if(!_root)
				return(0);
			iterator it = find(value);
			if (it == end())
				return (0);
			if(*it == value)
			{
				erase(it);
				return(1);
			}
			return (0);
		}

		void erase (iterator first, iterator last) 
		{
			iterator tmp;

			while(first != last)
			{
				tmp = first;
				first++;
				erase(tmp);
			}
		}

		void swap(RBTree &c) 
		{
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

		compare_type	value_comp() const { return _compare; }

		iterator		find(const value_type &value) 
		{
			Node<value_type> *tmp = _move(value);

			if(!_compare(*tmp->value, value) && !_compare(value, *tmp->value))
				return(iterator(tmp));
			return(end());
		}

		const_iterator	find(const value_type &value) const 
		{
			Node<value_type> *tmp = _move(value);

			if(!_compare(*tmp->value, value) && !_compare(value, *tmp->value))
				return(const_iterator(tmp));
			return(end());
		}

		size_type 		count(const value_type &value) const 
		{
			if (this->find(value) == this->end())
				return (0);
			return (1);
		}

		iterator		lower_bound(const value_type &value) { return iterator(_lower_bound(value, _root)); }
		const_iterator	lower_bound(const value_type &value) const { return const_iterator(_lower_bound(value, _root)); }

		iterator		upper_bound(const value_type &value) { return iterator(_upper_bound(value, _root)); }
		const_iterator	upper_bound(const value_type &value) const { return const_iterator(_upper_bound(value, _root)); }

		pair<const_iterator,const_iterator> equal_range(const value_type &value) const 
		{
			if (this->lower_bound(value) == this->end() && this->upper_bound(value) == this->end())
				return (ft::make_pair<const_iterator, const_iterator>(this->begin(), this->begin()));
			return (ft::make_pair<const_iterator, const_iterator>(this->lower_bound(value), this->upper_bound(value)));
		}

		pair<iterator,iterator>             equal_range(const value_type &value) 
		{
			if (this->lower_bound(value) == this->end() && this->upper_bound(value) == this->end())
				return (ft::make_pair<iterator, iterator>(this->begin(), this->begin()));
			return (ft::make_pair<iterator, iterator>(this->lower_bound(value), this->upper_bound(value)));
		}

		allocator_type get_allocator() const { return _allocator; }

	private:

		void _clear(Node<value_type> *node) 
		{
			if (!node)
				return;
			_clear(node->right);
			_clear(node->left);
			_allocator.destroy(node->value);
			_allocator.deallocate(node->value, 1);
			_nodeAllocator.destroy(node);
			_nodeAllocator.deallocate(node, 1);
		}

		Node<value_type> *_move(const_reference val) const 
		{
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

		Node<value_type> *_lower_bound(value_type const &value, Node<value_type> *node) const 
		{
			if (!node)
				return(_end);
		
			if(_compare(*node->value, value))
				return(_lower_bound(value, node->right));
			else
			{
				Node<value_type> *left = _lower_bound(value, node->left);
				return(left != _end ? left : node);
			}
		}

		Node<value_type> *_upper_bound(value_type const &value, Node<value_type> *node) const 
		{
			if (!node)
				return(_end);
			
			if(!_compare(value, *node->value))
				return(_upper_bound(value, node->right));
			else
			{
				Node<value_type> *left = _upper_bound(value, node->left);
				return(left != _end ? left : node);
			}
		}

		void _balance(Node<value_type> *node) 
		{
			if(!node)
				return;
			Node<value_type> *parent = NULL;
			Node<value_type> *grandpa = NULL;
			Node<value_type> *uncle = NULL;

			while ((node != _root) && (node->color != false) &&
				(node->parent->color == true)) {
				parent = node->parent;
				grandpa = node->parent->parent;

				if (parent == grandpa->left) {
					uncle = grandpa->right;

					if (uncle && uncle->color == true) {
						grandpa->color = true;
						parent->color = false;
						uncle->color = false;
						node = grandpa;
					}
					else {
						if (node == parent->right) {
							_rotate_left(parent);
							node = parent;
							parent = node->parent;
						}
						_rotate_right(grandpa);
						ft::swap(parent->color, grandpa->color);
						node = parent;
					}
				}
				else {
					uncle = grandpa->left;
		
					if (uncle && uncle->color == true) {
						grandpa->color = true;
						parent->color = false;
						uncle->color = false;
						node = grandpa;
					}
					else {
						if (node == parent->left) {
							_rotate_right(parent);
							node = parent;
							parent = node->parent;
						}
						_rotate_left(grandpa);
						ft::swap(parent->color, grandpa->color);
						node = parent;
					}
				}
			}
			_root->color = false;
		}

		void _rotate_left(Node<value_type> *node) 
		{
			Node<value_type> *right = node->right;
			node->right = right->left;
			if (node->right)
				node->right->parent = node;
			right->parent = node->parent;
			if (!node->parent)
				_root = right;
			else if (node == node->parent->left)
				node->parent->left = right;
			else
				node->parent->right = right;
			right->left = node;
			node->parent = right;
		}

		void _rotate_right(Node<value_type> *node) 
		{
			Node<value_type> *left = node->left;
			node->left = left->right;
			if (node->left)
				node->left->parent = node;
			left->parent = node->parent;
			if (!node->parent)
				_root = left;
			else if (node == node->parent->left)
				node->parent->left = left;
			else
				node->parent->right = left;
			left->right = node;
			node->parent = left;
		}

		Node<value_type> *_erase(Node<value_type> *node) 
		{
			if(!node)
				return(NULL);

			Node<value_type> *tmp = NULL;

			if(!node->left || !node->right)
			{
				if(!node->left && !node->right)
				{
					tmp = node->parent;
					if(tmp == NULL){_root = NULL;}
					else if (tmp->left == node){tmp->left = NULL;}
					else {tmp->right = NULL;}
				}
				else
				{
					tmp = !node->right ? node->left : node->right;
					if(node->parent == NULL)
					{
						_root = tmp;
						tmp->parent = NULL;
					}
					else if(node->parent->left == node)
					{
						node->parent->left = tmp;
						tmp->parent = node->parent;
					}
					else
					{
						node->parent->right = tmp;
						tmp->parent = node->parent;
					}
				}
				_clear_for_erase(node);
				return (tmp);
			}

			tmp = node->left;
			while(tmp->right)
				tmp = tmp->right;

			_allocator.destroy(node->value);
			_allocator.construct(node->value, *tmp->value);
			return(_erase(tmp));
		}

		void _clear_for_erase(Node<value_type> *node) 
		{
			if (!node)
				return;

			_allocator.destroy(node->value);
			_allocator.deallocate(node->value, 1);
			_nodeAllocator.destroy(node);
			_nodeAllocator.deallocate(node, 1);
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