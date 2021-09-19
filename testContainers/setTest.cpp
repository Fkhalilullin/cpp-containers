#include <set>
#include <iostream>
#include "../set/set.hpp"
#include "setTest.hpp"

void testSetIterator() 
{
    int val;
    std::set<int> std_set;
    ft::set<int> ft_set;

    std::cout << GREEN << "set elem: " << RESET;
    for (int i = 0; i <= 10; i++) {
        val = rand() % 10;
        std_set.insert(val);
        ft_set.insert(val);
        std::cout << val << " ";
    }
    std::cout << std::endl << std::endl;
	/////////////////////////////////////////////////////////////////////////
    std::cout << GREEN << "FT  iterator: " << RESET;
	ft::set<int>::iterator ft_it = ft_set.begin();
	for (;ft_it != ft_set.end(); ++ft_it) {
		std::cout << *ft_it << " ";
	}
	std::cout << GREEN << "\nSTD iterator: " << RESET;
	std::set<int>::iterator std_it = std_set.begin();
	for (;std_it != std_set.end(); ++std_it) {
		std::cout << *std_it << " ";
	}
	std::cout << std::endl << std::endl;
	/////////////////////////////////////////////////////////////////////////
    std::cout << GREEN << "FT  reverse iterator: " << RESET;
	ft::set<int>::reverse_iterator ft_rit = ft_set.rbegin();
	for (;ft_rit != ft_set.rend(); ++ft_rit) {
		std::cout << *ft_rit << " " ;
	}
	std::cout << GREEN << "\nSTD reverse iterator: " << RESET;
	std::set<int>::reverse_iterator std_rit = std_set.rbegin();
	for (;std_rit != std_set.rend(); ++std_rit) {
		std::cout << *std_rit << " " ;
	}
	/////////////////////////////////////////////////////////////////////////
	std::cout << std::endl << RED << LINE << RESET << std::endl;
	std::cout << std::endl;
}

void testSetCapacity() 
{
    int val;
    std::set<int> std_set;
    ft::set<int> ft_set;

    std::cout << GREEN << "FT  set empty: " << RESET << ft_set.empty() << std::endl;
	std::cout << GREEN << "STD set empty: " << RESET << std_set.empty() << std::endl << std::endl;

	std::cout << GREEN << "FT  set size: " << RESET << ft_set.size() << std::endl;
	std::cout << GREEN << "STD set size: " << RESET << std_set.size() << std::endl << std::endl;

    std::cout << GREEN << "set elem: " << RESET;
    for (int i = 0; i <= 10; i++) {
        val = rand() % 10;
        std_set.insert(val);
        ft_set.insert(val);
        std::cout << val << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << GREEN << "FT  set size: " << RESET << ft_set.size() << std::endl;
	std::cout << GREEN << "STD set size: " << RESET << std_set.size() << std::endl << std::endl;

    std::cout << GREEN << "FT  set max size: " << RESET << ft_set.max_size() << std::endl;
	std::cout << GREEN << "STD set max size: " << RESET << ft_set.max_size() << std::endl;

	std::cout << RED << LINE << RESET << std::endl << std::endl;
}

void testSetElementAccess() 
{
	int val;
	std::set<int> std_set;
	ft::set<int> ft_set;

    std::cout << GREEN << "set elem: " << RESET;
    for (int i = 0; i <= 10; i++) {
        val = rand() % 10;
  		std_set.insert(val);
        ft_set.insert(val);
        std::cout << val << " ";
    }
	std::cout << std::endl << std::endl;
	/////////////////////////////////////////////////////////////////////////
	std::cout << GREEN << "FT  set elements: " << RESET;
	ft::set<int>::iterator ft_it = ft_set.begin();
	for (;ft_it != ft_set.end(); ++ft_it) {
		std::cout << *ft_it << " " ;
	}
	std::cout << GREEN << "\nSTD set elements: " << RESET;
	std::set<int>::iterator std_it = std_set.begin();
	for (;std_it != std_set.end(); ++std_it) {
		std::cout << *std_it << " ";
	}
	/////////////////////////////////////////////////////////////////////////
    std::cout << std::endl << RED << LINE << RESET << std::endl;
	std::cout << std::endl;
}

void testSetModifiers() 
{
	int val;
	std::set<int> std_set;
	ft::set<int> ft_set;

    std::cout << GREEN << "set insert elem: " << RESET;
    for (int i = 0; i <= 3; i++) {
        val = rand() % 10;
        std_set.insert(val);
        ft_set.insert(val);
        std::cout << val << " ";
    }
	std::cout << std::endl << std::endl;
	/////////////////////////////////////////////////////////////////////////
	std::cout << GREEN << "FT  set elements: " << RESET;
	ft::set<int>::iterator ft_it = ft_set.begin();
	for (;ft_it != ft_set.end(); ++ft_it) {
		std::cout << *ft_it << " " ;
	}
	std::cout << GREEN << "\nSTD set elements: " << RESET;
	std::set<int>::iterator std_it = std_set.begin();
	for (;std_it != std_set.end(); ++std_it) {
		std::cout << *std_it << " ";
	}
	std::cout << std::endl << std::endl;
	/////////////////////////////////////////////////////////////////////////
	ft_set.insert(ft_set.begin(), 777);
	std_set.insert(std_set.begin(), 777);
	/////////////////////////////////////////////////////////////////////////
	std::cout << GREEN << "FT  set elements: " << RESET;
	ft_it = ft_set.begin();
	for (;ft_it != ft_set.end(); ++ft_it) {
		std::cout << *ft_it << " " ;
	}
	std::cout << GREEN << "\nSTD set elements: " << RESET;
	std_it = std_set.begin();
	for (;std_it != std_set.end(); ++std_it) {
		std::cout << *std_it << " ";
	}
	std::cout << std::endl << std::endl;
	/////////////////////////////////////////////////////////////////////////
	std::set<int> std_set1;
	ft::set<int> ft_set1;

    std::cout << GREEN << "set insert elem: " << RESET;
    for (int i = 5; i <= 10; i++) {
        val = rand() % 10;
        std_set1.insert(val);
        ft_set1.insert(val);
        std::cout << val << " ";
    }
	std::cout << std::endl << std::endl;

	ft_set.insert(ft_set1.begin(), ft_set1.end());
	std_set.insert(std_set1.begin(), std_set1.end());
	/////////////////////////////////////////////////////////////////////////
	std::cout << GREEN << "FT  set elements: " << RESET;
	ft_it = ft_set.begin();
	for (;ft_it != ft_set.end(); ++ft_it) {
		std::cout << *ft_it << " " ;
	}
	std::cout << GREEN << "\nSTD set elements: " << RESET;
	std_it = std_set.begin();
	for (;std_it != std_set.end(); ++std_it) {
		std::cout << *std_it << " ";
	}
	std::cout << std::endl << std::endl;
	/////////////////////////////////////////////////////////////////////////
	ft_set.erase(ft_set.begin());
	std_set.erase(std_set.begin());

	std::cout << GREEN << "FT  set elements after erase: " << RESET;
	ft_it = ft_set.begin();
	for (;ft_it != ft_set.end(); ++ft_it) {
		std::cout << *ft_it << " " ;
	}
	std::cout << GREEN << "\nSTD set elements after erase: " << RESET;
	std_it = std_set.begin();
	for (;std_it != std_set.end(); ++std_it) {
		std::cout << *std_it << " ";
	}
	std::cout << std::endl << std::endl;
	/////////////////////////////////////////////////////////////////////////
	ft_set.erase(5);
	std_set.erase(5);
	/////////////////////////////////////////////////////////////////////////
	std::cout << GREEN << "FT  set elements after erase: " << RESET;
	ft_it = ft_set.begin();
	for (;ft_it != ft_set.end(); ++ft_it) {
		std::cout << *ft_it << " " ;
	}
	std::cout << GREEN << "\nSTD set elements after erase: " << RESET;
	std_it = std_set.begin();
	for (;std_it != std_set.end(); ++std_it) {
		std::cout << *std_it << " ";
	}
	std::cout << std::endl << std::endl;
	/////////////////////////////////////////////////////////////////////////
	ft_it = ft_set.find(8);
	std_it = std_set.find(8);

	ft_set.erase(ft_set.begin(), ft_it);
	std_set.erase(std_set.begin(), std_it);
	/////////////////////////////////////////////////////////////////////////
	std::cout << GREEN << "FT  set elements after erase: " << RESET;
	ft_it = ft_set.begin();
	for (;ft_it != ft_set.end(); ++ft_it) {
		std::cout << *ft_it << " " ;
	}

	std::cout << GREEN << "\nSTD set elements after erase: " << RESET;
	std_it = std_set.begin();
	for (;std_it != std_set.end(); ++std_it) {
		std::cout << *std_it << " ";
	}
	std::cout << std::endl << std::endl;
	/////////////////////////////////////////////////////////////////////////
	ft_set.swap(ft_set1);
	std_set.swap(std_set1);

	std::cout << GREEN << "FT  set elements after swap: " << RESET;
	ft_it = ft_set.begin();
	for (;ft_it != ft_set.end(); ++ft_it) {
		std::cout << *ft_it << " " ;
	}

	std::cout << GREEN << "\nSTD set elements after swap: " << RESET;
	std_it = std_set.begin();
	for (;std_it != std_set.end(); ++std_it) {
		std::cout << *std_it << " ";
	}
	std::cout << std::endl << std::endl;
	/////////////////////////////////////////////////////////////////////////
	ft_set.clear();
	std_set.clear();

	std::cout << GREEN << "FT  set elements after clear: " << RESET;
	ft_it = ft_set.begin();
	for (;ft_it != ft_set.end(); ++ft_it) {
		std::cout << *ft_it << " " ;
	}

	std::cout << GREEN << "\nSTD set elements after clear: " << RESET;
	std_it = std_set.begin();
	for (;std_it != std_set.end(); ++std_it) {
		std::cout << *std_it << " ";
	}
	/////////////////////////////////////////////////////////////////////////
	std::cout << std::endl << RED << LINE << RESET << std::endl << std::endl;
}

void testSetObserversModifiers() 
{
	{
		ft::set<int> ft_set;
		std::set<int> std_set;

		ft::set<int>::key_compare ft_comp = ft_set.key_comp();
		std::set<int>::key_compare std_comp = std_set.key_comp();

		ft_set.insert(100);
		ft_set.insert(200);
		ft_set.insert(300);

		std_set.insert(100);
		std_set.insert(200);
		std_set.insert(300);

		int ft_highest = *ft_set.rbegin();    
		int std_highest = *std_set.rbegin();   
	/////////////////////////////////////////////////////////////////////////
		std::cout << GREEN << "FT  set elements: " << RESET;
		ft::set<int>::iterator ft_it = ft_set.begin();
		do {
			std::cout << *ft_it << " " ;
		} while ( ft_comp((*ft_it++), ft_highest) );
		std::cout << std::endl;

		std::cout << GREEN << "STD set elements: " << RESET;
		std::set<int>::iterator std_it = std_set.begin();
		do {
			std::cout << *std_it << " ";
		} while ( std_comp((*std_it++), std_highest) );
		std::cout << std::endl << std::endl;
	/////////////////////////////////////////////////////////////////////////
	}
	{
		ft::set<int> ft_set;
		std::set<int> std_set;

		ft_set.insert(1001);
		ft_set.insert(2002);
		ft_set.insert(3003);

		std_set.insert(1001);
		std_set.insert(2002);
		std_set.insert(3003);

		int ft_highest = *ft_set.rbegin();
		int std_highest = *std_set.rbegin();
	/////////////////////////////////////////////////////////////////////////
		std::cout << GREEN << "FT set elements:   " << RESET;
		ft::set<int>::iterator ft_it = ft_set.begin();
		do {
			std::cout << *ft_it << " " ;
		} while ( ft_set.value_comp()(*ft_it++, ft_highest) );
		std::cout << std::endl;

		std::cout << GREEN << "STD set elements:  " << RESET;
		std::set<int>::iterator std_it = std_set.begin();
		do {
			std::cout << *std_it << " ";
		} while ( std_set.value_comp()(*std_it++, std_highest) );
		std::cout << std::endl;
	}
	/////////////////////////////////////////////////////////////////////////
	std::cout << RED << LINE << RESET << std::endl << std::endl;
}

void testSetOperationsModifiers() 
{
	int val;
	std::set<int> std_set;
	ft::set<int> ft_set;

    std::cout << GREEN << "set elem: " << RESET;
    for (int i = 0; i <= 5; i++) {
        val = rand() % 10;
        std_set.insert(val);
        ft_set.insert(val);
        std::cout << val << " ";
    }
	std::cout << std::endl << std::endl;
	/////////////////////////////////////////////////////////////////////////
	std::cout << GREEN << "FT  set find elements: " << RESET;
	for(int i = 0; i <= 5; i++) {
		if (ft_set.count(i))
			std::cout << *ft_set.find(i) << " ";
	}
	std::cout << std::endl;

	std::cout << GREEN << "STD set find elements: " << RESET;
	for(int i = 0; i <= 5; i++) {
		if (std_set.count(i))
			std::cout << *std_set.find(i) << " " ;
	}
	std::cout << std::endl << std::endl;
	/////////////////////////////////////////////////////////////////////////
	ft::set<int>::iterator ft_it = ft_set.begin();
	std::cout << GREEN << "FT  set lower_bound: " << RESET;
	ft_it = ft_set.lower_bound(4);
	std::cout << *ft_it << " " << std::endl;

	std::set<int>::iterator std_it = std_set.begin();
	std::cout << GREEN << "STD set lower_bound: " << RESET;
	std_it = std_set.lower_bound(4);
	std::cout << *std_it << " "<< std::endl<<std::endl;
	/////////////////////////////////////////////////////////////////////////
	std::cout << GREEN << "FT  set upper_bound: " << RESET;
	ft_it = ft_set.upper_bound(4);
	std::cout << *ft_it << " " << std::endl;

	std::cout << GREEN << "STD set upper_bound: " << RESET;
	std_it = std_set.upper_bound(4);
	std::cout << *std_it << " "<< std::endl;
	std::cout << std::endl;
	/////////////////////////////////////////////////////////////////////////
	std::cout << GREEN << "FT  set equal_range: " << RESET;
	ft::pair<ft::set<int>::iterator, ft::set<int>::iterator> ft_ret = ft_set.equal_range(3);
	std::cout  << *ft_ret.first  << " " << *ft_ret.second << std::endl;

	std::cout << GREEN << "STD set equal_range: " << RESET;
	std::pair<std::set<int>::iterator, std::set<int>::iterator> std_ret = std_set.equal_range(3);
	std::cout << *ft_ret.first  << " " << *std_ret.second << std::endl;
	/////////////////////////////////////////////////////////////////////////
	std::cout << RED << LINE << RESET << std::endl << std::endl;
}

void testSetSpeed() {
		/////////////////////////////////////////////////////////////////////////
	{
		ft::set<int> ft_set;
		time_t start, end;

		time(&start);
		for (int i = 0; i < 10000000; i++) {
			ft_set.insert(i);
		}
		time(&end);
		double seconds = difftime(end, start);
		std::cout << GREEN << "FT  set insert: " << RESET; 
		std::cout << seconds << " sec" << std::endl;
	}
	/////////////////////////////////////////////////////////////////////////
	{
		std::set<int> std_set;
		time_t start, end;

		time(&start);
		for (int i = 0; i < 10000000; i++) {
			std_set.insert(i);
		}
		time(&end);

		double seconds = difftime(end, start);
		std::cout << GREEN << "STD set insert: " << RESET; 
		std::cout << seconds << " sec" << std::endl<<std::endl;
	}
	/////////////////////////////////////////////////////////////////////////
	{
		ft::set<int> ft_set;
		time_t start, end;

		for (int i = 0; i < 10000000; i++) {
			ft_set.insert(i);
		}
		time(&start);
		for (int i = 10000000; i > 0; i--) {
			ft_set.erase(i);
		}
		time(&end);
		double seconds = difftime(end, start);
		std::cout << GREEN << "FT  set erase: " << RESET; 
		std::cout << seconds << " sec" << std::endl;
	}
	/////////////////////////////////////////////////////////////////////////
	{
		std::set<int> std_set;
		time_t start, end;

		for (int i = 0; i < 10000000; i++) {
			std_set.insert(i);
		}
		time(&start);
		for (int i = 10000000; i > 0; i--) {
			std_set.erase(i);
		}
		time(&end);

		double seconds = difftime(end, start);
		std::cout << GREEN << "STD set erase: " << RESET; 
		std::cout << seconds << " sec" << std::endl << std::endl;
	}
	/////////////////////////////////////////////////////////////////////////
	{
		ft::set<int> ft_set;
		time_t start, end;

		for (int i = 0; i < 10000000; i++) {
			ft_set.insert(i);
		}
		time(&start);
		ft_set.find(10000000);
		time(&end);
		double seconds = difftime(end, start);
		std::cout << GREEN << "FT  set find: " << RESET; 
		std::cout << seconds << " sec" << std::endl;
	}
	/////////////////////////////////////////////////////////////////////////
	{
		std::set<int> std_set;
		time_t start, end;

		for (int i = 0; i < 10000000; i++) {
			std_set.insert(i);
		}
		time(&start);
		std_set.find(10000000);
		time(&end);
		double seconds = difftime(end, start);
		std::cout << GREEN << "FT  set find: " << RESET; 
		std::cout << seconds << " sec" << std::endl;
	}
	std::cout << RED << LINE << RESET << std::endl;
	std::cout << MAGENTA<< LINE << std::endl << std::endl;
}