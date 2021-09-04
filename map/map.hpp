#ifndef MAP_HPP
#define MAP_HPP

#include <functional>
#include <iterator>
#include <exception>

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


	};
}
	#endif