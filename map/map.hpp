#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
#include <iterator>
#include <exception>
#include "pair.hpp"
#include "tree.hpp"
#include "bidirectional_iterator.hpp"
#include "../vector/reverse_iterator.hpp"

namespace ft {

	template <class Key, class T, class Compare = std::less<Key>, 
			class Alloc = std::allocator<std::pair<const Key,T> > > 
	class map {
	public:
		typedef Key												key_type;
		typedef T												mapped_type;
		typedef typename std::pair<const key_type,mapped_type>	value_type;
		typedef Compare											key_compare;
		//typedef value_compare ?
		typedef Alloc											allocator_type;

		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;

		typedef typename ft::bidirectional_iterator<T>			iterator;
		typedef typename ft::bidirectional_iterator<const T>	const_iterator;

		typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		





	};
}
	#endif