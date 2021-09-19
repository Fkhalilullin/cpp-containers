// #ifndef SET_HPP
// # define SET_HPP

// #include <functional>
// #include <iterator>
// #include <exception>
// #include "../utility/pair.hpp"
// #include "../utility/tree.hpp"
// #include "../iterator/bidirectional_iterator.hpp"
// #include "../iterator/reverse_iterator.hpp"
// #include "../iterator/is_input_iterator_tag.hpp"

// namespace ft
// {
// 	template <typename T>
// 	struct Node;


// 	template <class Arg1, class Arg2, class Result>
//   	struct binary_function;

// 	template <class T> 
// 	struct less;
// }
// 	template <typename T, typename Compare, typename Alloc, typename NAlloc>
// 	class RBTree;

// namespace ft
// {
//     template < class T, class Compare = ft::less<T>, class Alloc = std::allocator<T> >
//     class set : public ft::RBTree<T, Compare, Alloc>
//     {
//         public:

//         typedef T			key_type;
//         typedef T			value_type;
//         typedef Compare		key_compare;
//         typedef Compare	    value_compare;
//         typedef Alloc		allocator_type;


//         explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): ft::RBTree<T, Compare, Alloc>(comp, alloc){}
//         // template <class InputIterator>
//         // set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
//         //     ft::RBTree<T, Compare, Alloc>(first, last, comp, alloc){}
//         // set (const set& x): ft::RBTree<T, Compare, Alloc>(x){}
//         // ~set(){}
//         // set& operator= (const set& x)
//         // {
//         //     ft::RBTree<T, Compare, Alloc>::operator=(x);
//         //     return(*this);
//         // }

//         // key_compare key_comp() const {return (key_compare());}
//         // value_compare value_comp() const {return (value_compare());}
//     };
// }

// #endif