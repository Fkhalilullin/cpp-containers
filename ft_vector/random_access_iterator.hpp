#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "remove_const.hpp"
#include <iterator>

namespace ft {
	template <class T>
	class random_access_iterator : public std::iterator<std::random_access_iterator_tag, T> {
	public:
		typedef T																				value_type;
		typedef T*																				pointer;
		typedef T&																				reference;
		typedef random_access_iterator<T>														It;
		typedef ptrdiff_t																		difference_type;
		typedef typename std::iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;

		random_access_iterator() { this->_ptr = 0; }

		random_access_iterator(pointer ptr) { this->_ptr = ptr; }

		random_access_iterator(const random_access_iterator &rhs) { this->_ptr = rhs.getPointer(); }

		virtual ~random_access_iterator() {}

		It				&operator=(const It &rhs) {
			if (*this != rhs)
				this->_ptr = rhs.getPointer();
			return *this;
		}

		reference		operator*() { return *this->_ptr; }
	
		pointer			operator->() { return this->_ptr; }

		reference		operator[](difference_type index) { return this->_ptr[index]; }

		It&				operator++() { ++this->_ptr; return *this; } 
		It&				operator--() { --this->_ptr; return *this; }
		It				operator++(int) { It it(*this); ++this->_ptr; return it; }
		It				operator--(int) { It it(*this); --this->_ptr; return it; }
		It				operator+(difference_type n) const { return random_access_iterator(this->_ptr + n); }
		It				operator-(difference_type n) const { return random_access_iterator(this->_ptr - n); }
		It&				operator+=(difference_type n) const { return random_access_iterator(this->_ptr += n); }
		It&				operator-=(difference_type n) const { return random_access_iterator(this->_ptr -= n); }

		pointer getPointer() const { return this->_ptr; }

	private:
		pointer		_ptr;
	};

	template <class T>
	random_access_iterator<T>	operator+
	(typename random_access_iterator<T>::difference_type n, random_access_iterator<T> &rhs) {
		return (rhs + n);	
	}
	
	template <class T>
	typename random_access_iterator<T>::difference_type operator-(const random_access_iterator<T> &lhs, 
																const random_access_iterator<T> &rhs) {
		return (lhs.getPointer() - rhs.getPointer());
	}

	template <class T>
	bool	operator==(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs) {
		return (lhs.getPointer() == rhs.getPointer());
	}
	
	template <class T>
	bool	operator!=(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs) {
		return (!(lhs == rhs));
	}

	template <class T>
	bool	operator>(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs) {
		return (lhs.getPointer() > rhs.getPointer());
	}
	
	template <class T>
	bool	operator<(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs) {
		return (lhs.getPointer() <rhs.getPointer());
	}
	
	template <class T>
	bool	operator>=(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs) {
		return (lhs > rhs || lhs == rhs);
	}
	template <class T>
	bool	operator<=(const random_access_iterator<T> &lhs, const random_access_iterator<T> &rhs) {
		return (lhs < rhs || lhs == rhs);
	}
}

#endif