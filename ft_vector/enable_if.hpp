#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

namespace ft {
	template <bool, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T> {
		typedef T type;
	};

	// template <bool B, typename T = void>
	// typedef enable_if_t = typename enable_if<B, T>::type;
}
#endif