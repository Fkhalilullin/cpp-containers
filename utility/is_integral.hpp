#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace ft 
{
	template< class T >
	struct is_integral
	{
		static const bool value;
		typedef std::integral_constant<bool, value> type;
	};
}

#endif