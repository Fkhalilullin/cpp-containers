#ifndef EQUAL_HPP
#define EQUAL_HPP

namespace ft {
	template <class InputIterator>
	bool equal ( InputIterator first1, InputIterator last1, InputIterator first2 )
	{
		while (first1!=last1) {
			if (!(*first1 == *first2))
				return (false);
			++first1;
			++first2;
		}
		return true;
	}
}

#endif