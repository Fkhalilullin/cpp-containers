#ifndef IS_INPUT_ITERATOR_TAG_HPP
#define IS_INPUT_ITERATOR_TAG_HPP

namespace ft
{
	class input_iterator_tag{};
	class output_iterator_tag{};
	class forward_iterator_tag{};
	class bidirectional_iterator_tag{};
	class random_access_iterator_tag{};


	template <bool res, typename T>
	struct is_iterator_tag
	{
		typedef T type;
		static const bool value = res;
	};

	template<typename T>
	struct is_input_iterator_tag: public is_iterator_tag<false, T>{};

	template<>
	struct is_input_iterator_tag<input_iterator_tag>: public is_iterator_tag<true, input_iterator_tag>{};

	template<>
	struct is_input_iterator_tag<forward_iterator_tag>: public is_iterator_tag<true, forward_iterator_tag>{};

	template<>
	struct is_input_iterator_tag<bidirectional_iterator_tag>: public is_iterator_tag<true, bidirectional_iterator_tag>{};

	template<>
	struct is_input_iterator_tag<random_access_iterator_tag>: public is_iterator_tag<true, random_access_iterator_tag>{};


	template<typename T>
	struct is_random_access_iterator_tag: public is_iterator_tag<false, T>{};

	template<>
	struct is_random_access_iterator_tag<random_access_iterator_tag>: public is_iterator_tag<true, random_access_iterator_tag>{};
}

#endif