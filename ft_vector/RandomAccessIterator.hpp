#ifndef FT_VECTOR_RANDOM_ITERATOR_HPP
#define FT_VECTOR_RANDOM_ITERATOR_HPP

#include <iterator>

namespace ft {
	template <class T>
	class VectorRandomIterator : public std::iterator<std::random_access_iterator_tag, T> {
	private:
		pointer		_ptr;
	};
}

#endif