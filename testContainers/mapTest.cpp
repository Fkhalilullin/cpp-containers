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
    for (int i = 0; i <= 10; i++) {
        val = rand() % 10;
        std_map[i] = val;
        ft_map[i] = val;
        std::cout << val << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << GREEN << "FT iterator:  " << RESET;
	ft::map<int, int>::iterator ft_it = ft_map.begin();
	for (;ft_it != ft_map.end(); ++ft_it) {
		std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << " | ";
	}
	std::cout << GREEN << "\nSTD iterator: " << RESET;
	std::map<int, int>::iterator std_it = std_map.begin();
	for (;std_it != std_map.end(); ++std_it) {
		std::cout << "[" << std_it->first << "]" << " " << std_it->second << " | ";
	}
	std::cout << std::endl << std::endl;

    std::cout << GREEN << "FT reverse iterator:   " << RESET;
	ft::map<int, int>::reverse_iterator ft_rit = ft_map.rbegin();
	for (;ft_rit != ft_map.rend(); ++ft_rit) {
		std::cout << "[" << ft_rit->first << "]" << " " << ft_rit->second << " | ";
	}
	std::cout << GREEN << "\nSTD resverse iterator: " << RESET;
	std::map<int, int>::reverse_iterator std_rit = std_map.rbegin();
	for (;std_rit != std_map.rend(); ++std_rit) {
		std::cout << "[" << std_rit->first << "]" << " " << std_rit->second << " | ";
	}
	std::cout << std::endl << RED << LINE << RESET << std::endl;
	std::cout << std::endl;
}

void testMapCapacity() {
    int val;
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;

    std::cout << GREEN << "FT map empty: " << RESET << ft_map.empty() << std::endl;
	std::cout << GREEN << "STD map empty: " << RESET << std_map.empty() << std::endl << std::endl;

	std::cout << GREEN << "FT map size: " << RESET << ft_map.size() << std::endl;
	std::cout << GREEN << "STD map size: " << RESET << std_map.size() << std::endl << std::endl;

    std::cout << GREEN << "Map elem: " << RESET;
    for (int i = 0; i <= 10; i++) {
        val = rand() % 10;
        std_map[i] = val;
        ft_map[i] = val;
        std::cout << val << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << GREEN << "FT map size: " << RESET << ft_map.size() << std::endl;
	std::cout << GREEN << "STD map size: " << RESET << std_map.size() << std::endl << std::endl;

    std::cout << GREEN << "FT map max size: " << RESET << ft_map.max_size() << std::endl;
	std::cout << GREEN << "STD map max size: " << RESET << ft_map.max_size() << std::endl;

	std::cout << RED << LINE << RESET << std::endl << std::endl;
}

void testMapElementAccess() {
	int val;
	std::map<int, int> std_map;
	ft::map<int, int> ft_map;

    std::cout << GREEN << "Map elem: " << RESET;
    for (int i = 0; i <= 10; i++) {
        val = rand() % 10;
        std_map[i] = val;
        ft_map[i] = val;
        std::cout << val << " ";
    }
	std::cout << std::endl << std::endl;

	std::cout << GREEN << "FT map elements:  " << RESET;
	ft::map<int, int>::iterator ft_it = ft_map.begin();
	for (;ft_it != ft_map.end(); ++ft_it) {
		std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << " | ";
	}
	std::cout << GREEN << "\nSTD map elements: " << RESET;
	std::map<int, int>::iterator std_it = std_map.begin();
	for (;std_it != std_map.end(); ++std_it) {
		std::cout << "[" << std_it->first << "]" << " " << std_it->second << " | ";
	}
	std::cout << std::endl << std::endl;

    int j = 10;
    for (int i = 0; i <= 5; ++i) {
        ft_map[i] = ft_map[j];
        std_map[i] = std_map[j];
        j--;
    }

    ft_it = ft_map.begin();
    std_it = std_map.begin();

    std::cout << GREEN << "FT map elements:  " << RESET;
	for (;ft_it != ft_map.end(); ++ft_it) {
		std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << " | ";
	}

	std::cout << GREEN << "\nSTD map elements: " << RESET;
	for (;std_it != std_map.end(); ++std_it) {
		std::cout << "[" << std_it->first << "]" << " " << std_it->second << " | ";
	}
    
    std::cout << std::endl << RED << LINE << RESET << std::endl;
	std::cout << std::endl;
}

void testMapModifiers() {
	int val;
	std::map<int, int> std_map;
	ft::map<int, int> ft_map;

    std::cout << GREEN << "Map insert elem: " << RESET;
    for (int i = 0; i <= 3; i++) {
        val = rand() % 10;
        std_map.insert(std::pair<int,int>(i, val));
        ft_map.insert(ft::pair<int,int>(i, val));
        std::cout << val << " ";
    }
	std::cout << std::endl << std::endl;

	std::cout << GREEN << "FT map elements:  " << RESET;
	ft::map<int, int>::iterator ft_it = ft_map.begin();
	for (;ft_it != ft_map.end(); ++ft_it) {
		std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << " | ";
	}
	std::cout << GREEN << "\nSTD map elements: " << RESET;
	std::map<int, int>::iterator std_it = std_map.begin();
	for (;std_it != std_map.end(); ++std_it) {
		std::cout << "[" << std_it->first << "]" << " " << std_it->second << " | ";
	}
	std::cout << std::endl << std::endl;

	ft_map.insert(ft_map.begin(), ft::pair<int,int>(5,777));
	std_map.insert(std_map.begin(), std::pair<int,int>(5,777));

	std::cout << GREEN << "FT map elements:  " << RESET;
	ft_it = ft_map.begin();
	for (;ft_it != ft_map.end(); ++ft_it) {
		std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << " | ";
	}
	std::cout << GREEN << "\nSTD map elements: " << RESET;
	std_it = std_map.begin();
	for (;std_it != std_map.end(); ++std_it) {
		std::cout << "[" << std_it->first << "]" << " " << std_it->second << " | ";
	}
	std::cout << std::endl << std::endl;

	std::map<int, int> std_map1;
	ft::map<int, int> ft_map1;

    std::cout << GREEN << "Map insert elem: " << RESET;
    for (int i = 6; i <= 10; i++) {
        val = rand() % 10;
        std_map1.insert(std::pair<int,int>(i, val));
        ft_map1.insert(ft::pair<int,int>(i, val));
        std::cout << val << " ";
    }
	std::cout << std::endl << std::endl;

	ft_map.insert(ft_map1.begin(), ft_map1.end());
	std_map.insert(std_map1.begin(), std_map1.end());

	std::cout << GREEN << "FT map elements:  " << RESET;
	ft_it = ft_map.begin();
	for (;ft_it != ft_map.end(); ++ft_it) {
		std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << " | ";
	}
	std::cout << GREEN << "\nSTD map elements: " << RESET;
	std_it = std_map.begin();
	for (;std_it != std_map.end(); ++std_it) {
		std::cout << "[" << std_it->first << "]" << " " << std_it->second << " | ";
	}
	std::cout << std::endl << std::endl;

	ft_map.erase(ft_map.end());
	std_map.erase(std_map.end());

	std::cout << GREEN << "FT map elements after erase:  " << RESET;
	ft_it = ft_map.begin();
	for (;ft_it != ft_map.end(); ++ft_it) {
		std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << " | ";
	}
	std::cout << GREEN << "\nSTD map elements after erase: " << RESET;
	std_it = std_map.begin();
	for (;std_it != std_map.end(); ++std_it) {
		std::cout << "[" << std_it->first << "]" << " " << std_it->second << " | ";
	}
	std::cout << std::endl << std::endl;

}