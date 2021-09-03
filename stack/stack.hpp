#ifndef STACK_HPP
#define STACK_HPP

#include "../vector/vector.hpp"

namespace ft {
	template< class T, class Cont = ft::vector<T> >
	class stack {
	public:
		typedef T				value_type;
		typedef Cont			container_type;
		typedef std::size_t		size_type;

		///////////////////////MEMBER FUNCTION///////////////////////

		stack() {};
		explicit	stack(const container_type& cont) : _cont(cont) {}

		bool				empty() const { return _cont.empty(); }

		size_type			size() const {return _cont.size(); }

		value_type&			top() { return _cont.back(); }
		const value_type&	top() const { return _cont.back(); }

		void				push (const value_type& val) { return _cont.push_back(val); }
		void 				pop() {return _cont.pop_back(); }

		/////////////////////////////////////////////////////////////
	private: 
		container_type _cont;
	};

	template <class T, class Cont>
  	bool operator== (const stack<T,Cont>& lhs, const stack<T,Cont>& rhs) {
		  return lhs == rhs;
	  }

	template <class T, class Cont>
	bool operator!= (const stack<T,Cont>& lhs, const stack<T,Cont>& rhs) {
		return !(lhs == rhs);
	}

	template <class T, class Cont>
	bool operator< (const stack<T,Cont>& lhs, const stack<T,Cont>& rhs) {
		return lhs < rhs;
	}

	template <class T, class Cont>
	bool operator<= (const stack<T,Cont>& lhs, const stack<T,Cont>& rhs) {
		return lhs <= rhs;
	}

	template <class T, class Cont>
	bool operator> (const stack<T,Cont>& lhs, const stack<T,Cont>& rhs) {
		return lhs > rhs;
	}

	template <class T, class Cont>
	bool operator>= (const stack<T,Cont>& lhs, const stack<T,Cont>& rhs) {
		return lhs >= rhs;
	}
}

#endif