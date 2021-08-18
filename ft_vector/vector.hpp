#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>
/* 
1) Что такое аллокатор и как работать
2) Для чего конкретно нужно делать typename 
3) Что такое итератор и как работать
*/


namespace ft {
	template < class T, class Alloc = std::allocator<T> >
	class Vector {
	public:
		typedef T												value_type;
		typedef Alloc											allocator_type;

		typedef size_t											size_type;
		typedef std::ptrdiff_t									difference_type;

		typedef typename allocator_type::reference				reference; //Изучить
		typedef typename allocator_type::const_reference		const_reference; //Изучить
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		
	public:	
		class VectorIterator : public std::iterator<std::random_access_iterator_tag, value_type> {
			public:
				typedef value_type&																			reference;
				typedef value_type*																			pointer;
				typedef VectorIterator																		It;
				typedef typename std::iterator<std::random_access_iterator_tag, T>::iterator_category		iterator_category;
				typedef std::ptrdiff_t																		difference_type;

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

				
			private:
				pointer		_ptr;
		};

	};
}
#endif