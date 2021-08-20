#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>
#include "random_access_iterator"


namespace ft {
	template < class T, class Alloc = std::allocator<T> >
	class vector {
	public:
		typedef T													value_type;
		typedef Alloc												allocator_type;

		typedef std::size_t											size_type;
		typedef std::ptrdiff_t										difference_type;

		typedef typename random_access_iterator<value_type>			iterator;
		typedef typename random_access_iterator<const value_type>	const_iterator;
		
		typedef typename allocator_type::reference					reference;
		typedef typename allocator_type::const_reference			const_reference;
		typedef typename allocator_type::pointer					pointer;
		typedef typename allocator_type::const_pointer				const_pointer;
		
	};
}
#endif