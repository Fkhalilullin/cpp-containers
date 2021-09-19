#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include <iterator>

namespace ft {
	template <class T, class P, class R>
	class random_access_iterator : public std::iterator<std::random_access_iterator_tag, T> {
	public:
		typedef T															value_type;
		typedef P															pointer;
		typedef R															reference;
		typedef random_access_iterator<T, P, R>								It;
		typedef std::ptrdiff_t												difference_type;
		typedef typename std::random_access_iterator_tag					iterator_category;

		random_access_iterator() : _ptr(0) {}

		random_access_iterator(pointer ptr) : _ptr(ptr) {}

		random_access_iterator(random_access_iterator<T, T*, T&> const &rhs) : _ptr( rhs.getPointer() ) {}

		virtual ~random_access_iterator() {}

		It				&operator=(const It &rhs) {
			if (this == &rhs)
				return *this;
			this->_ptr = rhs._ptr;
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

	template <class T, class P, class R>
	random_access_iterator<T, P, R>	operator+
	(typename random_access_iterator<T, P, R>::difference_type n, random_access_iterator<T, P, R> &rhs) {
		return (rhs + n);	
	}
	
	template <class T, class P, class R>
	typename random_access_iterator<T, P, R>::difference_type operator-(const random_access_iterator<T, P, R> &lhs, 
																const random_access_iterator<T, P, R> &rhs) {
		return (lhs.getPointer() - rhs.getPointer());
	}

	template <class T, class P, class R>
	bool	operator==(const random_access_iterator<T, P, R> &lhs, const random_access_iterator<T, P, R> &rhs) {
		return (lhs.getPointer() == rhs.getPointer());
	}
	
	template <class T, class P, class R>
	bool	operator!=(const random_access_iterator<T, P, R> &lhs, const random_access_iterator<T, P, R> &rhs) {
		return (!(lhs == rhs));
	}

	template <class T, class P, class R>
	bool	operator>(const random_access_iterator<T, P, R> &lhs, const random_access_iterator<T, P, R> &rhs) {
		return (lhs.getPointer() > rhs.getPointer());
	}
	
	template <class T, class P, class R>
	bool	operator<(const random_access_iterator<T, P, R> &lhs, const random_access_iterator<T, P, R> &rhs) {
		return (lhs.getPointer() <rhs.getPointer());
	}
	
	template <class T, class P, class R>
	bool	operator>=(const random_access_iterator<T, P, R> &lhs, const random_access_iterator<T, P, R> &rhs) {
		return (lhs > rhs || lhs == rhs);
	}

	template <class T, class P, class R>
	bool	operator<=(const random_access_iterator<T, P, R> &lhs, const random_access_iterator<T, P, R> &rhs) {
		return (lhs < rhs || lhs == rhs);
	}
}

#endif