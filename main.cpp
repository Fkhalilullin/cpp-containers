
#include <iostream>
#include <iomanip>
// #include "ft_vector/reverse_iterator.hpp"
// #include "ft_vector/random_access_iterator.hpp"

#include "ft_vector/vector.hpp"
#include <vector>


void testIterator() {
	ft::vector<int> ft_vec(10, 5);
	std::vector<int> std_vec(10, 5);

	std::cout << "FT iterator: ";
	ft::vector<int>::iterator ft_it = ft_vec.begin();
	for (;ft_it < ft_vec.end(); ++ft_it) {
		*ft_it = 6;
		std::cout  << *ft_it << " ";
	}
	std::cout << "\nSTD iterator: ";
	std::vector<int>::iterator std_it = std_vec.begin();
	for (;std_it < std_vec.end(); ++std_it) {
		*std_it = 6;
		std::cout << *std_it << " ";
	}
	std::cout << std::endl;
}

int main() {
	
	ft::vector<int> ft_vec(10, 5);
	std::vector<int> std_vec(10, 5);

	testIterator();
	// std::cout << "FT const iterator: ";
	// ft::vector<int>::const_iterator ft_c_it = ft_vec.begin();
	// for (;ft_c_it < ft_vec.end(); ++ft_c_it) {
	// 	std::cout  << *ft_c_it << " ";
	// }
	// std::cout << "\nSTD const iterator: ";
	// std::vector<int>::const_iterator std_c_it = std_vec.begin();
	// for (;std_c_it < std_vec.end(); ++std_c_it) {
	// 	std::cout << *std_c_it << " ";
	// }
	return 0;
}