#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>
/* 
1) Что такое аллокатор 
2) Для чего конкретно нужно делать typename 

*/


namespace ft {
	template < class T, class Alloc = std::allocator<T> >
	class Vector {
	public:
		typedef T											value_type;
		typedef Alloc										allocator_type;

		typedef typename allocator_type::reference			reference; //Изучить
		typedef typename allocator_type::const_reference	const_reference; //Изучить
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
	};
}

#endif