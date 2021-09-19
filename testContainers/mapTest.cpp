#include <map>
#include <iostream>
#include "../map/map.hpp"
#include "mapTest.hpp"

void testMapIterator() 
{
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
	/////////////////////////////////////////////////////////////////////////
    std::cout << GREEN << "FT  iterator: " << RESET;
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
	/////////////////////////////////////////////////////////////////////////
    std::cout << GREEN << "FT  reverse iterator: " << RESET;
	ft::map<int, int>::reverse_iterator ft_rit = ft_map.rbegin();
	for (;ft_rit != ft_map.rend(); ++ft_rit) {
		std::cout << "[" << ft_rit->first << "]" << " " << ft_rit->second << " | ";
	}
	std::cout << GREEN << "\nSTD reverse iterator: " << RESET;
	std::map<int, int>::reverse_iterator std_rit = std_map.rbegin();
	for (;std_rit != std_map.rend(); ++std_rit) {
		std::cout << "[" << std_rit->first << "]" << " " << std_rit->second << " | ";
	}
	/////////////////////////////////////////////////////////////////////////
	std::cout << std::endl << RED << LINE << RESET << std::endl;
	std::cout << std::endl;
}

void testMapCapacity() 
{
    int val;
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;

    std::cout << GREEN << "FT  map empty: " << RESET << ft_map.empty() << std::endl;
	std::cout << GREEN << "STD map empty: " << RESET << std_map.empty() << std::endl << std::endl;

	std::cout << GREEN << "FT  map size: " << RESET << ft_map.size() << std::endl;
	std::cout << GREEN << "STD map size: " << RESET << std_map.size() << std::endl << std::endl;

    std::cout << GREEN << "Map elem: " << RESET;
    for (int i = 0; i <= 10; i++) {
        val = rand() % 10;
        std_map[i] = val;
        ft_map[i] = val;
        std::cout << val << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << GREEN << "FT  map size: " << RESET << ft_map.size() << std::endl;
	std::cout << GREEN << "STD map size: " << RESET << std_map.size() << std::endl << std::endl;

    std::cout << GREEN << "FT  map max size: " << RESET << ft_map.max_size() << std::endl;
	std::cout << GREEN << "STD map max size: " << RESET << ft_map.max_size() << std::endl;

	std::cout << RED << LINE << RESET << std::endl << std::endl;
}

void testMapElementAccess() 
{
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
	/////////////////////////////////////////////////////////////////////////
	std::cout << GREEN << "FT  map elements: " << RESET;
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
	/////////////////////////////////////////////////////////////////////////
    int j = 10;
    for (int i = 0; i <= 5; ++i) {
        ft_map[i] = ft_map[j];
        std_map[i] = std_map[j];
        j--;
    }

    ft_it = ft_map.begin();
    std_it = std_map.begin();
	/////////////////////////////////////////////////////////////////////////
    std::cout << GREEN << "FT  map elements: " << RESET;
	for (;ft_it != ft_map.end(); ++ft_it) {
		std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << " | ";
	}

	std::cout << GREEN << "\nSTD map elements: " << RESET;
	for (;std_it != std_map.end(); ++std_it) {
		std::cout << "[" << std_it->first << "]" << " " << std_it->second << " | ";
	}
    /////////////////////////////////////////////////////////////////////////
    std::cout << std::endl << RED << LINE << RESET << std::endl;
	std::cout << std::endl;
}

void testMapModifiers() 
{
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
	/////////////////////////////////////////////////////////////////////////
	std::cout << GREEN << "FT  map elements: " << RESET;
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
	/////////////////////////////////////////////////////////////////////////
	ft_map.insert(ft_map.begin(), ft::pair<int,int>(4,777));
	std_map.insert(std_map.begin(), std::pair<int,int>(4,777));
	/////////////////////////////////////////////////////////////////////////
	std::cout << GREEN << "FT  map elements: " << RESET;
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
	/////////////////////////////////////////////////////////////////////////
	std::map<int, int> std_map1;
	ft::map<int, int> ft_map1;

    std::cout << GREEN << "Map insert elem: " << RESET;
    for (int i = 5; i <= 10; i++) {
        val = rand() % 10;
        std_map1.insert(std::pair<int,int>(i, val));
        ft_map1.insert(ft::pair<int,int>(i, val));
        std::cout << val << " ";
    }
	std::cout << std::endl << std::endl;

	ft_map.insert(ft_map1.begin(), ft_map1.end());
	std_map.insert(std_map1.begin(), std_map1.end());
	/////////////////////////////////////////////////////////////////////////
	std::cout << GREEN << "FT  map elements: " << RESET;
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
	/////////////////////////////////////////////////////////////////////////
	ft_map.erase(ft_map.begin());
	std_map.erase(std_map.begin());

	std::cout << GREEN << "FT  map elements after erase: " << RESET;
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
	/////////////////////////////////////////////////////////////////////////
	ft_map.erase(5);
	std_map.erase(5);
	/////////////////////////////////////////////////////////////////////////
	std::cout << GREEN << "FT  map elements after erase: " << RESET;
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
	/////////////////////////////////////////////////////////////////////////
	ft_it = ft_map.find(8);
	std_it = std_map.find(8);

	ft_map.erase(ft_map.begin(), ft_it);
	std_map.erase(std_map.begin(), std_it);
	/////////////////////////////////////////////////////////////////////////
	std::cout << GREEN << "FT  map elements after erase: " << RESET;
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
	/////////////////////////////////////////////////////////////////////////
	ft_map.swap(ft_map1);
	std_map.swap(std_map1);

	std::cout << GREEN << "FT  map elements after swap: " << RESET;
	ft_it = ft_map.begin();
	for (;ft_it != ft_map.end(); ++ft_it) {
		std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << " | ";
	}

	std::cout << GREEN << "\nSTD map elements after swap: " << RESET;
	std_it = std_map.begin();
	for (;std_it != std_map.end(); ++std_it) {
		std::cout << "[" << std_it->first << "]" << " " << std_it->second << " | ";
	}
	std::cout << std::endl << std::endl;
	/////////////////////////////////////////////////////////////////////////
	ft_map.clear();
	std_map.clear();

	std::cout << GREEN << "FT  map elements after clear: " << RESET;
	ft_it = ft_map.begin();
	for (;ft_it != ft_map.end(); ++ft_it) {
		std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << " | ";
	}

	std::cout << GREEN << "\nSTD map elements after clear: " << RESET;
	std_it = std_map.begin();
	for (;std_it != std_map.end(); ++std_it) {
		std::cout << "[" << std_it->first << "]" << " " << std_it->second << " | ";
	}
	/////////////////////////////////////////////////////////////////////////
	std::cout << std::endl << RED << LINE << RESET << std::endl << std::endl;
}

void testObserversModifiers() 
{

	{
		ft::map<char,int> ft_map;
		std::map<char,int> std_map;

		ft::map<char,int>::key_compare ft_comp = ft_map.key_comp();
		std::map<char,int>::key_compare std_comp = std_map.key_comp();

		ft_map['a']=100;
		ft_map['b']=200;
		ft_map['c']=300;

		std_map['a']=100;
		std_map['b']=200;
		std_map['c']=300;

		char ft_highest = ft_map.rbegin()->first;    
		char std_highest = std_map.rbegin()->first;   
	/////////////////////////////////////////////////////////////////////////
		std::cout << GREEN << "FT  map elements: " << RESET;
		ft::map<char,int>::iterator ft_it = ft_map.begin();
		do {
			std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << " | ";
		} while ( ft_comp((*ft_it++).first, ft_highest) );
		std::cout << std::endl;

		std::cout << GREEN << "STD map elements: " << RESET;
		std::map<char,int>::iterator std_it = std_map.begin();
		do {
			std::cout << "[" << std_it->first << "]" << " " << std_it->second << " | ";
		} while ( std_comp((*std_it++).first, std_highest) );
		std::cout << std::endl << std::endl;
	/////////////////////////////////////////////////////////////////////////
	}
	{
		ft::map<char,int> ft_map;
		std::map<char,int> std_map;

		ft_map['x']=1001;
		ft_map['y']=2002;
		ft_map['z']=3003;

		std_map['x']=1001;
		std_map['y']=2002;
		std_map['z']=3003;

		ft::pair<char,int> ft_highest = *ft_map.rbegin();
		std::pair<char,int> std_highest = *std_map.rbegin();
	/////////////////////////////////////////////////////////////////////////
		std::cout << GREEN << "FT map elements:   " << RESET;
		ft::map<char,int>::iterator ft_it = ft_map.begin();
		do {
			std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << " | ";
		} while ( ft_map.value_comp()(*ft_it++, ft_highest) );
		std::cout << std::endl;

		std::cout << GREEN << "STD map elements:  " << RESET;
		std::map<char,int>::iterator std_it = std_map.begin();
		do {
			std::cout << "[" << std_it->first << "]" << " " << std_it->second << " | ";
		} while ( std_map.value_comp()(*std_it++, std_highest) );
		std::cout << std::endl;
	}
	/////////////////////////////////////////////////////////////////////////
	std::cout << RED << LINE << RESET << std::endl << std::endl;
}

void testOperationsModifiers() 
{
	int val;
	std::map<int, int> std_map;
	ft::map<int, int> ft_map;

    std::cout << GREEN << "Map elem: " << RESET;
    for (int i = 0; i <= 5; i++) {
        val = rand() % 10;
        std_map[i] = val;
        ft_map[i] = val;
        std::cout << val << " ";
    }
	std::cout << std::endl << std::endl;
	/////////////////////////////////////////////////////////////////////////
	std::cout << GREEN << "FT  map find elements: " << RESET;
	for(int i = 0; i <= 5; i++) {
		if (ft_map.count(i))
			std::cout << "[" << ft_map.find(i)->first << "]" << " " << ft_map.find(i)->second << " | ";
	}
	std::cout << std::endl;

	std::cout << GREEN << "STD map find elements: " << RESET;
	for(int i = 0; i <= 5; i++) {
		if (std_map.count(i))
			std::cout << "[" << std_map.find(i)->first << "]" << " " << std_map.find(i)->second << " | ";
	}
	std::cout << std::endl << std::endl;
	/////////////////////////////////////////////////////////////////////////
	ft::map<int, int>::iterator ft_it = ft_map.begin();
	std::cout << GREEN << "FT  map lower_bound: " << RESET;
	ft_it = ft_map.lower_bound(4);
	std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << std::endl;

	std::map<int, int>::iterator std_it = std_map.begin();
	std::cout << GREEN << "STD map lower_bound: " << RESET;
	std_it = std_map.lower_bound(4);
	std::cout << "[" << std_it->first << "]" << " " << std_it->second << std::endl<<std::endl;
	/////////////////////////////////////////////////////////////////////////
	std::cout << GREEN << "FT  map upper_bound: " << RESET;
	ft_it = ft_map.upper_bound(4);
	std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << std::endl;

	std::cout << GREEN << "STD map upper_bound: " << RESET;
	std_it = std_map.upper_bound(4);
	std::cout << "[" << std_it->first << "]" << " " << std_it->second << std::endl;
	std::cout << std::endl;
	/////////////////////////////////////////////////////////////////////////
	std::cout << GREEN << "FT  map equal_range: " << RESET;
	ft::pair<ft::map<int,int>::iterator, ft::map<int,int>::iterator> ft_ret = ft_map.equal_range(3);
	std::cout << "[" << ft_ret.first->first << "]" << " " << ft_ret.second->second << std::endl;

	std::cout << GREEN << "STD map equal_range: " << RESET;
	std::pair<std::map<int,int>::iterator, std::map<int,int>::iterator> std_ret = std_map.equal_range(3);
	std::cout << "[" << ft_ret.first->first << "]" << " " << std_ret.second->second << std::endl;
	/////////////////////////////////////////////////////////////////////////
	std::cout << RED << LINE << RESET << std::endl << std::endl;
}

void testMapSpeed() {
		/////////////////////////////////////////////////////////////////////////
	{
		ft::map<int, int> ft_map;
		time_t start, end;

		time(&start);
		for (int i = 0; i < 10000000; i++) {
			ft_map.insert(ft::pair<int, int>(i, i));
		}
		time(&end);
		double seconds = difftime(end, start);
		std::cout << GREEN << "FT  map insert: " << RESET; 
		std::cout << seconds << " sec" << std::endl;
	}
	/////////////////////////////////////////////////////////////////////////
	{
		std::map<int, int> std_map;
		time_t start, end;

		time(&start);
		for (int i = 0; i < 10000000; i++) {
			std_map.insert(std::pair<int, int>(i, i));
		}
		time(&end);

		double seconds = difftime(end, start);
		std::cout << GREEN << "STD map insert: " << RESET; 
		std::cout << seconds << " sec" << std::endl<<std::endl;
	}
	/////////////////////////////////////////////////////////////////////////
	{
		ft::map<int, int> ft_map;
		time_t start, end;

		for (int i = 0; i < 10000000; i++) {
			ft_map.insert(ft::pair<int, int>(i, i));
		}
		time(&start);
		for (int i = 10000000; i > 0; i--) {
			ft_map.erase(i);
		}
		time(&end);
		double seconds = difftime(end, start);
		std::cout << GREEN << "FT  map erase: " << RESET; 
		std::cout << seconds << " sec" << std::endl;
	}
	/////////////////////////////////////////////////////////////////////////
	{
		std::map<int, int> std_map;
		time_t start, end;

		for (int i = 0; i < 10000000; i++) {
			std_map.insert(std::pair<int, int>(i, i));
		}
		time(&start);
		for (int i = 10000000; i > 0; i--) {
			std_map.erase(i);
		}
		time(&end);

		double seconds = difftime(end, start);
		std::cout << GREEN << "STD map erase: " << RESET; 
		std::cout << seconds << " sec" << std::endl << std::endl;
	}
	/////////////////////////////////////////////////////////////////////////
	{
		ft::map<int, int> ft_map;
		time_t start, end;

		for (int i = 0; i < 10000000; i++) {
			ft_map.insert(ft::pair<int, int>(i, i));
		}
		time(&start);
		ft_map.find(10000000);
		time(&end);
		double seconds = difftime(end, start);
		std::cout << GREEN << "FT  map find: " << RESET; 
		std::cout << seconds << " sec" << std::endl;
	}
	/////////////////////////////////////////////////////////////////////////
	{
		std::map<int, int> std_map;
		time_t start, end;

		for (int i = 0; i < 10000000; i++) {
			std_map.insert(std::pair<int, int>(i, i));
		}
		time(&start);
		std_map.find(10000000);
		time(&end);
		double seconds = difftime(end, start);
		std::cout << GREEN << "FT  map find: " << RESET; 
		std::cout << seconds << " sec" << std::endl;
	}
	std::cout << RED << LINE << RESET << std::endl;
	std::cout << MAGENTA<< LINE << std::endl << std::endl;
}