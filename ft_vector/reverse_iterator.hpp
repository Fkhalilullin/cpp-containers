#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iterator>
#include "iterator_traits.hpp"

namespace ft {
	template <class Iterator>
	class reverse_iterator : public std::iterator<std::random_access_iterator_tag, Iterator> {
	public:
		typedef Iterator														iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category		iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type				value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference				reference;

		reverse_iterator() { this->_it = 0; }

		explicit reverse_iterator (iterator_type it) { this->_it = it; }

		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter>& rev_it) { this->_it = rev_it; }

		template< class U > 
		reverse_iterator& operator=( const reverse_iterator<U>& other ) {
			if (*this != other)
				this->_it = other.getIterator();
			return *this;
		}

		iterator_type		base() const { return (_it); }
		
		reference 			operator*() { return *this->_it; }
		pointer 			operator->() {return this->_it; }

		reference 			operator[]( difference_type n ) const { return this->_it[n]; };
		
		reverse_iterator&	operator++() { --this->_it; return *this; }
		reverse_iterator&	operator--() { ++this->_it; return *this; }
		reverse_iterator	operator++(int) {reverse_iterator it(*this); --this->_it; return it; }
		reverse_iterator	operator--(int) {reverse_iterator it(*this); ++this->_it; return it; }
		reverse_iterator	operator+( difference_type n ) const { return reverse_iterator(this->_it - n); }
		reverse_iterator	operator-( difference_type n ) const { return reverse_iterator(this->_it + n); }
		reverse_iterator&	operator+=( difference_type n ) { return reverse_iterator(this->_it -= n); }
		reverse_iterator&	operator-=( difference_type n ) { return reverse_iterator(this->_it += n); }

		iterator_type getIterator() const { return this->_it; }

	private:
		iterator_type _it;

	};

	template< class Iterator1, class Iterator2 >
	bool operator==( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ) {
		return lhs == rhs;
	}

	template< class Iterator1, class Iterator2 >
	bool operator!=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ) {
		return lhs != rhs;
	}

	template< class Iterator1, class Iterator2 >
	bool operator<( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ) {
		return lhs.base() > rhs.base();
	}

	template< class Iterator1, class Iterator2 >
	bool operator<=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ) {
		return lhs.base() >= rhs.base();
	}

	template< class Iterator1, class Iterator2 >
	bool operator>( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ) {
		return lhs.base() < rhs.base();
	}

	template< class Iterator1, class Iterator2 >
	bool operator>=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ) {
		return lhs.base() <= rhs.base();
	}

	template< class Iter > 
	reverse_iterator<Iter> operator+( typename reverse_iterator<Iter>::difference_type n, 
										const reverse_iterator<Iter>& it ) {
		return reverse_iterator<Iter>(it - n);
	}

	template< class Iter > 
	reverse_iterator<Iter> operator-( typename reverse_iterator<Iter>::difference_type n, 
										const reverse_iterator<Iter>& it ) {
		return reverse_iterator<Iter>(it + n);
	}
}

#endif