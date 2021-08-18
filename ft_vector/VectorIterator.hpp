#ifndef FT_VECTOR_RANDOM_ITERATOR_HPP
#define FT_VECTOR_RANDOM_ITERATOR_HPP

#include <iterator>

namespace ft {
	template <class T>
	class VectorIterator : public std::iterator<std::random_access_iterator_tag, T> {
	public:
		typedef T																				value_type;
		typedef T*																				pointer;
		typedef T&																				reference;
		typedef VectorIterator<T>													It;
		typedef ptrdiff_t																		difference_type;
		typedef typename std::iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;

		VectorIterator() { this->_ptr = 0; }
		VectorIterator(pointer ptr) { this->_ptr = ptr; }
		VectorIterator(const VectorIterator &rhs) { this->_ptr = rhs.getPointer(); }
		virtual ~VectorIterator() {}

		reference		operator*() { return *this->_ptr; }
	
		pointer			operator->() { return this->_ptr; }

		reference		operator[](difference_type index) { return this->_ptr[index]; }

		It				&operator++() { ++this->_ptr; return *this; } 
		It				&operator--() { --this->_ptr; return *this; }

		It				operator++(int) { It it(*this); ++this->_ptr; return it; }
		It				operator--(int) { It it(*this); --this->_ptr; return it; }

		It				operator+(difference_type n) const { It it(*this); return it += n; }
		It				operator-(difference_type n) const { It it(*this); return it -= n; }

		difference_type	operator-(const It &other) const { return _ptr - other._ptr; }

		pointer getPointer() const { return this->_ptr; }

		boo

	private:
		pointer		_ptr;
	};
}

#endif