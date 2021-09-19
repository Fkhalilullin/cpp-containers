#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "swap.hpp"
#include "random_access_iterator.hpp"
#include "lexicographical_compare.hpp"
#include "equal.hpp"
#include "reverse_iterator.hpp"
#include "enable_if.hpp"
#include <exception>
#include <iostream>
#include <iterator>

namespace ft {
	template < class T, class Alloc = std::allocator<T> >
	class vector {
	public:
		typedef T																	value_type;
		typedef Alloc																allocator_type;

		typedef std::size_t															size_type;
		typedef typename ft::random_access_iterator<T, T*, T&>::difference_type		difference_type;

		typedef typename ft::random_access_iterator<T, T*, T&>						iterator;
		typedef typename ft::random_access_iterator<T, const T*, const T&>			const_iterator;
		
		typedef typename ft::reverse_iterator<iterator>								reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>						const_reverse_iterator;
		
		typedef typename allocator_type::reference									reference;
		typedef typename allocator_type::const_reference							const_reference;
		typedef typename allocator_type::pointer									pointer;
		typedef typename allocator_type::const_pointer								const_pointer;
		
	public:
		///////////////////////MEMBER FUNCTION///////////////////////

		explicit vector(const allocator_type& alloc = allocator_type()) : 
		_ptr(0), _size(0), _alloc_size(0), _allocator(alloc) {}

		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : 
		_ptr(0), _size(n), _alloc_size(n), _allocator(alloc) 
		{
			_ptr = _allocator.allocate(n);
			for (size_type i = 0; i < _size; ++i) {
				_allocator.construct(_ptr + i, val);
			}
		}

		template <class InputIterator>
		vector (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, 
		const allocator_type& alloc = allocator_type()) : _ptr(0), _size(0), _alloc_size(0), _allocator(alloc) 
		{
			_size = std::distance(first, last);
			_alloc_size = std::distance(first, last);
			_ptr = _allocator.allocate(_alloc_size);
			for (size_type i = 0; i < _size; ++i) {
				_allocator.construct(_ptr + i, *(first + i));
			}
		}
		
		vector (const vector& x) : _ptr(0), _size(x._size), _alloc_size(x._alloc_size), _allocator(x._allocator) 
		{
			_ptr = _allocator.allocate(_alloc_size);
			for (size_type i = 0; i < _size; ++i) {
				_allocator.construct(_ptr + i, *(x._ptr + i));
			}
		}

		~vector() 
		{
			for (size_type i = 0; i < _size; ++i) {
				if (_ptr + i)
					_allocator.destroy(_ptr + i);
			}
			_allocator.deallocate(_ptr, _alloc_size);
			_ptr = NULL;
		}

		vector& operator=(const vector& x) 
		{
			if (this == &x)
				return *this;
			this->~vector();
				_ptr = _allocator.allocate(x._alloc_size);
			_size = x._size;
			_alloc_size = x._alloc_size;
			for (size_type i = 0; i < _size; ++i)
				_allocator.construct(_ptr + i, *(x._ptr + i));
			return *this;
		}

		/////////////////////////////////////////////////////////////

		/////////////////////////ITERATORS///////////////////////////

		iterator				begin() { return iterator(_ptr); }
		const_iterator			begin() const { return const_iterator(_ptr); }

		iterator				end() { return iterator(_ptr + _size); }
		const_iterator			end() const { return const_iterator(_ptr + _size); }

		reverse_iterator 		rbegin() { return reverse_iterator(end()); }
		const_reverse_iterator	rbegin () const { return const_reverse_iterator(end()); }

		reverse_iterator 		rend() { return reverse_iterator(begin()); }
		const_reverse_iterator 	rend() const { return const_everse_iterator(begin()); }

		/////////////////////////////////////////////////////////////

		//////////////////////////CAPACITY///////////////////////////

		size_type	size() const { return _size; }

		size_type	max_size() const { return std::numeric_limits<difference_type>::max(); }

		void		resize (size_type n, value_type val = value_type()) 
		{
			if (_size < n)
				insert(end(), n - size(), val);
			else if (n < _size)
				erase(begin() + n, end());
		}

		size_type	capacity() const { return _alloc_size; }

		bool		empty() const { return _size == 0; }

		void		reserve (size_type n) 
		{
			pointer _ptr_tmp;

			if (n <= _alloc_size)
				return ;
				_ptr_tmp = _allocator.allocate(n);
			for (size_type i = 0; i < _size; ++i) {
				_ptr_tmp[i] = _ptr[i];
			}
			if (_ptr != NULL)
				_allocator.deallocate(_ptr, _alloc_size);
			_alloc_size = n;
			_ptr = _ptr_tmp;
		}

		/////////////////////////////////////////////////////////////

		///////////////////////ELEMENT ACCESS////////////////////////

		reference		operator[] (size_type n) { return *(begin() + n); }
		const_reference	operator[] (size_type n) const { return *(begin() + n); }

		reference		at(size_type n) 
		{
			if (n >= _size)
				throw std::out_of_range("Out of range");
			return *(_ptr + n);
		}

		const_reference	at (size_type n) const 
		{
			if (n >= _size)
				throw std::out_of_range("Out of range");
			return *(_ptr + n);
		}

		reference		front() { return *(begin()); }
		const_reference	front() const { return *(begin()); }

		reference		back() { return *(end() - 1); }
		const_reference	back() const { return *(end() - 1); }

		/////////////////////////////////////////////////////////////

		//////////////////////////MODIFIERS//////////////////////////

		template <class InputIterator>
		void	assign (InputIterator first, 
	    typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) 
		{
         	clear();
            for ( ; first != last; first++) {
                push_back(*first);
            }
		}

		void	assign (size_type n, const value_type& val) 
		{
            clear();
            for (size_t i = 0; i < n; i++) {
                push_back(val);
            }
		}

		void	push_back (const value_type& val) 
		{
			if (_size >= _alloc_size) {
				this->reserve(_alloc_size * 2 + (_alloc_size == 0));
			}
			_allocator.construct(this->end().getPointer(), val);
			_size++;
		}

		void	pop_back() 
		{
			if (_size == 0)
				return ;
			_allocator.destroy(_ptr + _size - 1);
			_size--;
		}

		iterator	insert (iterator position, const value_type& val) 
		{
			vector tmp(position, end());
            iterator it = tmp.begin();
            difference_type insertPos = std::distance(begin(), position);
            while (end() != position) {
                pop_back();
            }
            push_back(val);
            while (it != tmp.end()) {
                push_back(*it);
                it++;
            }
            return begin() + insertPos;
		}

		void		insert (iterator position, size_type n, const value_type& val) 
		{
			vector tmp(position, end());
            iterator it = tmp.begin();

            while (end() != position) {
                pop_back();
            }
            for (size_t i = 0; i < n; i++) {
                push_back(val);
            }
            while (it != tmp.end()) {
                push_back(*it);
                it++;
            }
		}

		template <class InputIterator>
		void		insert (iterator position, InputIterator first, 
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) 
		{
			vector tmp(position, end());
            iterator it = tmp.begin();
            while (end() != position) {
                pop_back();
            }
            while (first != last) {
                push_back(*first);
                first++;
            }
            while (it != tmp.end()) {
                push_back(*it);
                it++;
            }
		}

		iterator	erase (iterator position) 
		{
			vector tmp(position + 1, end());
            for (size_t i = 0; i < tmp.size(); i++) {
                pop_back();
            }
            pop_back();
            iterator it(tmp.begin());
            while (it != tmp.end()) {
                push_back(*it);
                it++;
            }
            return position;
		}
		
		iterator	erase (iterator first, iterator last) 
		{
			iterator it(first);
			while (it != last) {
				erase(first);
				it++;
			}
			return first;
		}

		void	swap(vector& x) 
		{
			ft::swap(this->_ptr, x._ptr);
			ft::swap(this->_size, x._size);
			ft::swap(this->_alloc_size, x._alloc_size);
			ft::swap(this->_allocator, x._allocator);
		}

		void	clear() 
		{
			if (_ptr == NULL)
				return ;
			for (size_type i = 0; i < _size; ++i)
				_allocator.destroy(_ptr + i);
			_size = 0;
		}

		allocator_type	get_allocator() const { return this->_allocator; }

	private:
		pointer				_ptr;
		size_type			_size;
		size_type			_alloc_size;
		allocator_type		_allocator;
	};

	template<class T, class Alloc>
	bool operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return !(lhs == rhs);
	}

	template<class T, class Alloc>
	bool operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template<class T, class Alloc>
	bool operator<(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template<class T, class Alloc>
	bool operator<=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return !(rhs < lhs);
	}

	template<class T, class Alloc>
	bool operator>(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return rhs < lhs;
	}

	template<class T, class Alloc>
	bool operator>=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return !(lhs < rhs);
	}

	template<class T, class Alloc>
	void swap(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		lhs.swap(rhs);
	}
}

#endif