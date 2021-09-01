#ifndef STACK_HPP
#define STACK_HPP

#include "../ft_vector/vector.hpp"

namespace ft {
	template<class T, class Cont = ft::vector<T> 
	class stack {
	public:
		typedef typename T			value_type;
		typedef typename Cont		container_type;
		typedef typename size_t		size_type;

		stack() {};
		explicit stack(const container_type& cont) : _cont(cont) {}
	};

	private: 
		container_type _cont 
}