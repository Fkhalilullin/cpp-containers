#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include <iterator>

//iterator_traits<Iterator> write

namespace ft {
	template <class Iterator>
	class reverse_iterator : public std::iterator<std::random_access_iterator_tag, Iterator> {
	public:
		typedef Iterator												iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iterator>::value_type			value_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::pointer				pointer;
		typedef typename iterator_traits<Iterator>::reference			reference;

		reverse_iterator() { this->_it = 0; }
		explicit reverse_iterator (iterator_type it) { this->_it = it; }

		template <class Iter>
  		reverse_iterator (const reverse_iterator<Iter>& rev_it) {this->_it = rev_it;}
	private:
		iterator_type _it;
	// 	reverse_iterator() { this->_ptr = 0; }
	// 	reverse_iterator(pointer ptr) { this->_ptr = ptr; }
	// 	reverse_iterator(const reverse_iterator &rhs) { this->_ptr = rhs.getPointer(); }
	// 	virtual ~reverse_iteratorr() {}

	// 	value_type				&operator=(const value_type &rhs) {
	// 		if (this != rhs)
	// 			this->_ptr = rhs.getPointer();
	// 		return *this;
	// 	}

	// 	reference		operator*() { return *this->_ptr; }
	
	// 	pointer			operator->() { return this->_ptr; }

	// 	reference		operator[](difference_type index) { return this->_ptr[index]; }

	// 	value_type				&operator++() { ++this->_ptr; return *this; } 
	// 	value_type				&operator--() { --this->_ptr; return *this; }

	// 	value_type				operator++(int) { value_type it(*this); ++this->_ptr; return it; }
	// 	value_type				operator--(int) { value_type it(*this); --this->_ptr; return it; }

	// 	value_type				operator+(difference_type n) const { value_type it(*this); return it += n; }
	// 	value_type				operator-(difference_type n) const { value_type it(*this); return it -= n; }

	// 	pointer getPointer() const { return this->_ptr; }

	// private:
	// 	pointer		_ptr;
	};

	// template <typename Iterator>
	// reverse_iterator<Iterator> operator+
	// (typename reverse_iterator<Iterator>::difference_type n, reverse_iterator<Iterator> &rhs) {
	// 	return (n + rhs);
	// } 

	// template <typename Iterator>
	// reverse_iterator<Iterator> operator+
	// (reverse_iterator<Iterator> &lhs, typename reverse_iterator<Iterator>::difference_type n) {
	// 	return (lhs + n);
	// } 

	// template <class Iterator>
	// typename reverse_iterator<Iterator>::difference_type operator-
	// (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
	// 	return (lhs.getPointer() - rhs.getPointer());
	// }

	// template <class Iterator>
	// bool	operator!=
	// (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
	// 	return (!(lhs == rhs));
	// }

	// template <class Iterator>
	// bool	operator>
	// (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
	// 	return (lhs.getPointer() > rhs.getPointer());
	// }
	
	// template <class Iterator>
	// bool	operator<
	// (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
	// 	return (lhs.getPointer() < rhs.getPointer());
	// }
	
	// template <class Iterator>
	// bool	operator>=
	// (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
	// 	return (lhs > rhs || lhs == rhs);
	// }
	// template <class Iterator>
	// bool	operator<=
	// (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) {
	// 	return (lhs < rhs || lhs == rhs);
	// }
}
#endif