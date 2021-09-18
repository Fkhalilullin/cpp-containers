#include "../map/map.hpp"
#include <map>
#include <iostream>

#define RESET	"\033[0m"
#define GREEN	"\033[32m"
#define RED		"\033[31m"
#define MAGENTA "\033[35m"
#define LINE	"-----------------------------------------------"

void testMapIterator() {
    int val;
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;

    std::cout << GREEN << "Map elem: " << RESET;
    for (int i = 0; i < 10; i++) {
        val = rand() % 10;
        std_map[i] = val;
        ft_map[i] = val;
        std::cout << val << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << GREEN << "FT iterator: " << RESET;
	ft::map<int, int>::iterator ft_it = ft_map.begin();
	for (;ft_it != ft_map.end(); ++ft_it) {
		std::cout << "[" << ft_it->first << "]" << " " << ft_it->second;
	}
	std::cout << GREEN << "\nSTD iterator: " << RESET;
	std::map<int, int>::iterator std_it = std_map.begin();
	for (;std_it != std_map.end(); ++std_it) {
		std::cout << "[" << std_it->first << "]" << " " << std_it->second;
	}
	std::cout << std::endl << RED << LINE << RESET << std::endl;
	std::cout << std::endl;
}