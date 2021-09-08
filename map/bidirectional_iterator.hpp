#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include <iterator>

namespace ft {
    template <class T>
    class bidirectional_iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
    public:
        typedef T															value_type;
		typedef T*															pointer;
		typedef T&															reference;
		typedef bidirectional_iterator<T>								    It;
		typedef std::ptrdiff_t												difference_type;
		typedef typename std::bidirectional_iterator_tag					iterator_category;

		bidirectional_iterator() : _ptr(0) {}

		bidirectional_iterator(pointer ptr) : _ptr(ptr) {}

		bidirectional_iterator(bidirectional_iterator<T> const &rhs) : _ptr ( rhs.getPointer() ) {}

		virtual ~bidirectional_iterator() {}

		It		&operator=(const It &rhs) {
			if (this == &rhs)
				return *this;
			this->_ptr = rhs.getPointer();
			return *this;
		}

		reference		operator*() { return *this->_ptr; }
		pointer			operator->() { return this->_ptr; }

		It&				operator++() { ++this->_ptr; return *this; } 
		It&				operator--() { --this->_ptr; return *this; }
		It				operator++(int) { It it(*this); ++this->_ptr; return it; }
		It				operator--(int) { It it(*this); --this->_ptr; return it; }

		pointer getPointer() { return this->_ptr; }
	private:
		pointer _ptr;
    };

	template <class T>
	bool	operator!=(const bidirectional_iterator<T> &lhs, const bidirectional_iterator<T> &rhs) {
		return (!(lhs == rhs));
	}

	template <class T>
	bool	operator==(const bidirectional_iterator<T> &lhs, const bidirectional_iterator<T> &rhs) {
		return (lhs.getPointer() == rhs.getPointer());
	}
}

#endif