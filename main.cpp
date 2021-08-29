
#include <iostream>
#include <iomanip>
// #include "ft_vector/reverse_iterator.hpp"
// #include "ft_vector/random_access_iterator.hpp"

#include "ft_vector/vector.hpp"
#include <vector>

#define RESET	"\033[0m"
#define GREEN	"\033[32m"
#define RED		"\033[31m"
#define LINE	"-----------------------------------------------"

void testIterator() {
	int val;
	ft::vector<int> ft_vec;
	std::vector<int> std_vec;
	std::cout << GREEN << "Vector elem: " << RESET;
	for (int i = 0; i < 10; i++) {
		val = rand() % 10;
		ft_vec.push_back(val);
		std_vec.push_back(val);
				std::cout << val << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << GREEN << "FT iterator: " << RESET;
	ft::vector<int>::iterator ft_it = ft_vec.begin();
	for (;ft_it < ft_vec.end(); ++ft_it) {
		std::cout  << *ft_it << " ";
	}
	std::cout << GREEN << "\nSTD iterator: " << RESET;
	std::vector<int>::iterator std_it = std_vec.begin();
	for (;std_it < std_vec.end(); ++std_it) {
		std::cout << *std_it << " ";
	}
	std::cout << std::endl << RED << LINE << RESET << std::endl;
	std::cout << std::endl;
}

void testModifiers() {
	ft::vector<int> ft_vec;
	std::vector<int> std_vec;

	ft_vec.assign(5,5);
	std_vec.assign(5,5);
	
	std::cout << GREEN << "FT vector after assign: " << RESET;
	for (size_t i = 0; i < ft_vec.size(); i++) {
		std::cout << ft_vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << GREEN << "STD vector after assign: " << RESET;
	for (size_t i = 0; i < std_vec.size(); i++) {
		std::cout << std_vec[i] << " ";
	}
	std::cout << std::endl << std::endl;

	int val;
	ft::vector<int> ft_buf_vec;
	std::vector<int> std_buf_vec;

	std::cout << GREEN << "Vector: " << RESET;
	for (int i = 0; i < 10; i++) {
		val = rand() % 10;
		ft_buf_vec.push_back(val);
		std_buf_vec.push_back(val);
		std::cout << val << " ";
	}
	std::cout << std::endl << std::endl;

	ft::vector<int>::iterator ft_it = ft_buf_vec.begin();
	ft::vector<int>::iterator ft_ite = ft_buf_vec.end();
	ft_vec.assign(ft_it,ft_ite);

	std::vector<int>::iterator std_it = std_buf_vec.begin();
	std::vector<int>::iterator std_ite = std_buf_vec.end();
	std_vec.assign(std_it,std_ite);

	std::cout << GREEN << "FT vector after assign: " << RESET;
	for (size_t i = 0; i < ft_vec.size(); i++) {
		std::cout << ft_vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << GREEN << "STD vector after assign: " << RESET;
	for (size_t i = 0; i < std_vec.size(); i++) {
		std::cout << std_vec[i] << " ";
	}
	std::cout << std::endl << std::endl;

	ft_vec.pop_back();
	ft_vec.pop_back();
	ft_vec.pop_back();
	ft_vec.pop_back();

	std_vec.pop_back();
	std_vec.pop_back();
	std_vec.pop_back();
	std_vec.pop_back();

	std::cout << GREEN << "FT vector after pop back: " << RESET;
	for (size_t i = 0; i < ft_vec.size(); i++) {
		std::cout << ft_vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << GREEN << "STD vector after pop back: " << RESET;
	for (size_t i = 0; i < std_vec.size(); i++) {
		std::cout << std_vec[i] << " ";
	}
	std::cout << std::endl << std::endl;

	ft_vec.insert(ft_vec.end(), 777);
	std_vec.insert(std_vec.end(), 777);

	ft_vec.insert(ft_vec.begin(),5 ,777);
	std_vec.insert(std_vec.begin(),5 ,777);

	std::cout << GREEN << "FT vector after insert: " << RESET;
	for (size_t i = 0; i < ft_vec.size(); i++) {
		std::cout << ft_vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << GREEN << "STD vector after insert: " << RESET;
	for (size_t i = 0; i < std_vec.size(); i++) {
		std::cout << std_vec[i] << " ";
	}
	std::cout << std::endl << std::endl;

	ft_vec.insert(ft_vec.begin(),ft_it ,ft_ite);
	std_vec.insert(std_vec.begin(),std_it ,std_ite);

	std::cout << GREEN << "FT vector after insert: " << RESET;
	for (size_t i = 0; i < ft_vec.size(); i++) {
		std::cout << ft_vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << GREEN << "STD vector after insert: " << RESET;
	for (size_t i = 0; i < std_vec.size(); i++) {
		std::cout << std_vec[i] << " ";
	}
	std::cout << std::endl << std::endl;


	// ft_vec.erase(ft_vec.begin()); ////////repair
	ft_vec.erase(ft_it, ft_ite);
	// std_vec.erase(std_vec.begin());
	std_vec.erase(std_it, std_ite);

	std::cout << GREEN << "FT vector after erase: " << RESET;
	for (size_t i = 0; i < ft_vec.size(); i++) {
		std::cout << ft_vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << GREEN << "STD vector after erase: " << RESET;
	for (size_t i = 0; i < std_vec.size(); i++) {
		std::cout << std_vec[i] << " ";
	}

	std::cout << std::endl << std::endl;
}

void testReverseItetator() {
	int val;
	ft::vector<int> ft_vec;
	std::vector<int> std_vec;

	std::cout << GREEN << "Vector elem: " << RESET;
	for (int i = 0; i < 10; i++) {
		val = rand() % 10;
		ft_vec.push_back(val);
		std_vec.push_back(val);
		std::cout << val << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << GREEN << "FT reverse iterator: " << RESET;
	ft::vector<int>::reverse_iterator ft_it = ft_vec.rbegin();
	for (;ft_it < ft_vec.rend(); ++ft_it) {
		std::cout  << *ft_it << " ";
	}
	std::cout << GREEN << "\nSTD reverse iterator: " << RESET;
	std::vector<int>::reverse_iterator std_it = std_vec.rbegin();
	for (;std_it < std_vec.rend(); ++std_it) {
		std::cout << *std_it << " ";
	}
	std::cout << std::endl << RED << LINE << RESET << std::endl;
	std::cout << std::endl;
}

void testCapacity() {
	ft::vector<int> ft_vec(10, 5);
	std::vector<int> std_vec(10, 5);

	ft::vector<int> ft_empty_vec;
	std::vector<int> std_empty_vec;

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


	ft_vec.resize(5);
	std_vec.resize(5);

	std::cout << GREEN << "FT vector after resize: " << RESET << ft_vec.size() << std::endl;
	std::cout << GREEN << "STD vector after resize: " << RESET << std_vec.size() << std::endl << std::endl;

	std::cout << GREEN << "FT vector capacity: " << RESET << ft_vec.capacity() << std::endl;
	std::cout << GREEN << "STD vector capacity: " << RESET << std_vec.capacity() << std::endl << std::endl;

	std::cout << GREEN << "FT vector empty: " << RESET << ft_vec.empty() << std::endl;
	std::cout << GREEN << "STD vector empty: " << RESET << std_vec.empty() << std::endl << std::endl;
	
	std::cout << GREEN << "FT vector empty: " << RESET << ft_empty_vec.empty() << std::endl;
	std::cout << GREEN << "STD vector empty: " << RESET << std_empty_vec.empty() << std::endl << std::endl;

	ft_vec.reserve(100);
	std_vec.reserve(100);

	std::cout << GREEN << "FT vector capacity after reserve: " << RESET << ft_vec.capacity() << std::endl;
	std::cout << GREEN << "STD vector capacity after reserve: " << RESET << std_vec.capacity() << std::endl << std::endl;

	std::cout << GREEN << "FT vector max size: " << RESET << ft_vec.max_size() << std::endl;
	std::cout << GREEN << "STD vector max size: " << RESET << ft_vec.max_size() << std::endl;

	std::cout << RED << LINE << RESET << std::endl << std::endl;
}

void testElementAccess() {
	int val;
	ft::vector<int> ft_vec;
	std::vector<int> std_vec;

	std::cout << GREEN << "Vector: " << RESET;
	for (int i = 0; i < 10; i++) {
		val = rand() % 10;
		ft_vec.push_back(val);
		std_vec.push_back(val);
		std::cout << val << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << GREEN << "FT vector: " << RESET;
	for (size_t i = 0; i < ft_vec.size(); i++) {
		std::cout << ft_vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << GREEN << "STD vector: " << RESET;
	for (size_t i = 0; i < std_vec.size(); i++) {
		std::cout << std_vec[i] << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << GREEN << "FT at() vector: " << RESET;
	for (size_t i = 0; i < ft_vec.size(); i++) {
		std::cout << ft_vec.at(i) << " ";
	}
	std::cout << std::endl;

	std::cout << GREEN << "STD at() vector: " << RESET;
	for (size_t i = 0; i < std_vec.size(); i++) {
		std::cout << std_vec.at(i) << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << GREEN << "FT front elem vector: " << RESET << ft_vec.front() << std::endl;
	std::cout << GREEN <<"STD front elem vector: " << RESET <<std_vec.front() << std::endl << std::endl;

	std::cout << GREEN << "FT back elem vector: " << RESET << ft_vec.back() << std::endl;
	std::cout << GREEN << "STD back elem vector: " << RESET << std_vec.back() << std::endl;

	std::cout << RED << LINE << RESET << std::endl << std::endl;
}

int main() {
	srand(time(NULL));
	std::cout << RED << "<Iterator Test>" << RESET << std::endl;
	std::cout << RED << LINE << RESET << std::endl;
	testIterator();
	// testConstIterator(); // DONT WORK
	// testConstReverseIterator(); // DONT WORK
	std::cout << RED << "<Reverse Iterator Test>" << RESET << std::endl;
	std::cout << RED << LINE << RESET << std::endl;
	testReverseItetator();

	std::cout << RED << "<Capacity Test>" << RESET << std::endl;
	std::cout << RED << LINE << RESET << std::endl;
	testCapacity();

	std::cout << RED << "<Element Access>" << RESET << std::endl;
	std::cout << RED << LINE << RESET << std::endl;
	testElementAccess();


	std::cout << RED << "<Modifiers>" << RESET << std::endl;
	std::cout << RED << LINE << RESET << std::endl;
	testModifiers();
	return 0;
}