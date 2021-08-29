
#include <iostream>
#include <iomanip>
// #include "ft_vector/reverse_iterator.hpp"
// #include "ft_vector/random_access_iterator.hpp"

#include "ft_vector/vector.hpp"
#include <vector>

#define RESET	"\033[0m"
#define GREEN	"\033[32m"
#define RED		"\033[31m"
#define LINE	"---------------------------------------"

void testIterator() {
	ft::vector<int> ft_vec(10, 5);
	std::vector<int> std_vec(10, 5);

	std::cout << GREEN << "FT iterator: " << RESET;
	ft::vector<int>::iterator ft_it = ft_vec.begin();
	for (;ft_it < ft_vec.end(); ++ft_it) {
		*ft_it = 6;
		std::cout  << *ft_it << " ";
	}
	std::cout << GREEN << "\nSTD iterator: " << RESET;
	std::vector<int>::iterator std_it = std_vec.begin();
	for (;std_it < std_vec.end(); ++std_it) {
		*std_it = 6;
		std::cout << *std_it << " ";
	}
	std::cout << std::endl << RED << LINE << RESET << std::endl;
	std::cout << std::endl;
}

void testCapacity() {
	ft::vector<int> ft_vec(10, 5);
	std::vector<int> std_vec(10, 5);

	std::cout << GREEN << "FT vector size: " << RESET << ft_vec.size() << std::endl;
	std::cout << GREEN << "STD vector size: " << RESET << std_vec.size() << std::endl << std::endl;

	ft_vec.push_back(10);
	std_vec.push_back(10);
	ft_vec.push_back(20);
	std_vec.push_back(20);

	std::cout << GREEN << "FT vector size: " << RESET << ft_vec.size() << std::endl;
	std::cout << GREEN << "STD vector size: " << RESET << std_vec.size() << std::endl << std::endl;

	ft_vec.pop_back();
	std_vec.pop_back();

	std::cout << GREEN << "FT vector size: " << RESET << ft_vec.size() << std::endl;
	std::cout << GREEN << "STD vector size: " << RESET << std_vec.size() << std::endl << std::endl;

	std::cout << GREEN << "FT vector max_size: " << RESET << ft_vec.max_size() << std::endl;
	std::cout << GREEN << "STD vector max size: " << RESET << ft_vec.max_size() << std::endl << std::endl;

	ft_vec.resize(5);
	std_vec.resize(5);

	std::cout << GREEN << "STD vector after resize: " << RESET << ft_vec.size() << std::endl;
	std::cout << GREEN << "STD vector after resize: " << RESET << std_vec.size() << std::endl;

	std::cout << RED << LINE << RESET << std::endl;
}

int main() {
	
	std::cout << RED << "<Iterator Test>" << RESET << std::endl;
	std::cout << RED << LINE << RESET << std::endl;
	testIterator();
	//test const iter
	//test reverse iter
	//test const reverse iter
	std::cout << RED << "<Capacity Test>" << RESET << std::endl;
	testCapacity();
	return 0;
}