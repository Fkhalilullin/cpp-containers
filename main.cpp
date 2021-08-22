
#include <iostream>
#include "ft_vector/reverse_iterator.hpp"
#include "ft_vector/random_access_iterator.hpp"

#include "ft_vector/vector.hpp"

#include <vector>

int main() {
	
	ft::vector<int> vec1(5,10);
	
	std::vector<int> vec(5,20);

	std::vector<int>::iterator it = vec.begin();
	std::vector<int>::iterator ite = vec.end();

	ft::vector<int> vec2(it, ite);
	// ft::vector<int> vec2(vec);
	return 0;
}