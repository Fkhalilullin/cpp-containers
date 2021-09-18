#ifndef IS_INPUT_ITERATOR_TAG_HPP
#define IS_INPUT_ITERATOR_TAG_HPP

class bidirectional_iterator_tag{};

namespace ft {

	template <bool res, typename T>
	struct is_iterator_tag
	{
		typedef T type;
		static const bool value = res;
	};

	template<typename T>
	struct is_input_iterator_tag: public is_iterator_tag<false, T>{};

	template<>
	struct is_input_iterator_tag<bidirectional_iterator_tag>: public is_iterator_tag<true, bidirectional_iterator_tag>{};

	template<typename T>
	struct is_random_access_iterator_tag: public is_iterator_tag<false, T>{};	
}

#endif