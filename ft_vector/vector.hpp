#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "enable_if.hpp"
#include <exception>
#include <iostream>
#include <iterator>

namespace ft {
	template < class T, class Alloc = std::allocator<T> >
	class vector {
	public:
		typedef T														value_type;
		typedef Alloc													allocator_type;

		typedef std::size_t												size_type;
		typedef std::ptrdiff_t											difference_type;

		typedef typename ft::random_access_iterator<value_type>			iterator;
		typedef typename ft::random_access_iterator<const value_type>	const_iterator;
		
		typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
	public:

		explicit vector(const allocator_type& alloc = allocator_type()) : _ptr(0), 
													_size(0), _alloc_size(0), _allocator(alloc) {}
								
		explicit vector(size_type n, const value_type& val = value_type(), 
						const allocator_type& alloc = allocator_type()) : 
			_ptr(0), _size(n), _alloc_size(n), _allocator(alloc) {
			try {
				_ptr = _allocator.allocate(n);
			}
			catch (std::exception &e) {
				this->~vector();
				throw std::length_error("vector");
			}
			for (size_type i = 0; i < _size; ++i) {
				_allocator.construct(_ptr + i, val);
			}
		}

		template <class InputIterator>
		vector (InputIterator first, typename ft::enable_if< !std::numeric_limits<InputIterator>::is_integer, InputIterator >::type last, const allocator_type& alloc = allocator_type()) :
		_ptr(0), _size(0), _alloc_size(0), _allocator(alloc) {
			_size = std::distance(first, last);
			_alloc_size = std::distance(first, last);
			try {
				_ptr = _allocator.allocate(_alloc_size);
			}
			catch (std::exception &e) {
				this->~vector();
				throw std::length_error("vector");
			}
			for (size_type i = 0; i < _size; ++i) {
				_allocator.construct(_ptr + i, *(first + i));
			}
		}
		
		vector (const vector& x) : _ptr(0), _size(x._size), _alloc_size(x._alloc_size), _allocator(x._allocator) {
			try {
				_ptr = _allocator.allocate(_alloc_size);
			}
			catch (std::exception &e) {
				this->~vector();
				throw std::length_error("vector");
			}
			for (size_type i = 0; i < _size; ++i) {
				_allocator.construct(_ptr + i, *(x._ptr + i));
			}
		}

		~vector() {
			for (size_type i = 0; i < _size; ++i)
				_allocator.destroy(_ptr + i);
			_allocator.deallocate(_ptr, _alloc_size);
			_ptr = NULL;
		}
	private:
		pointer				_ptr;
		size_type			_size;
		size_type			_alloc_size;
		allocator_type		_allocator;
	};
}
#endif