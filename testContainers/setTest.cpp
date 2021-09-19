#include <set>
#include <iostream>
#include "../set/set.hpp"
#include "setTest.hpp"

void testSetIterator() 
{
    // int val;
    std::set<int, int> std_set;
    ft::set<int, int> ft_set;

    // std::cout << GREEN << "set elem: " << RESET;
    // for (int i = 0; i <= 10; i++) {
    //     val = rand() % 10;
    //     std_set[i] = val;
    //     ft_set[i] = val;
    //     std::cout << val << " ";
    // }
    // std::cout << std::endl << std::endl;
	// /////////////////////////////////////////////////////////////////////////
    // std::cout << GREEN << "FT  iterator: " << RESET;
	// ft::set<int, int>::iterator ft_it = ft_set.begin();
	// for (;ft_it != ft_set.end(); ++ft_it) {
	// 	std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << " | ";
	// }
	// std::cout << GREEN << "\nSTD iterator: " << RESET;
	// std::set<int, int>::iterator std_it = std_set.begin();
	// for (;std_it != std_set.end(); ++std_it) {
	// 	std::cout << "[" << std_it->first << "]" << " " << std_it->second << " | ";
	// }
	// std::cout << std::endl << std::endl;
	// /////////////////////////////////////////////////////////////////////////
    // std::cout << GREEN << "FT  reverse iterator: " << RESET;
	// ft::set<int, int>::reverse_iterator ft_rit = ft_set.rbegin();
	// for (;ft_rit != ft_set.rend(); ++ft_rit) {
	// 	std::cout << "[" << ft_rit->first << "]" << " " << ft_rit->second << " | ";
	// }
	// std::cout << GREEN << "\nSTD resverse iterator: " << RESET;
	// std::set<int, int>::reverse_iterator std_rit = std_set.rbegin();
	// for (;std_rit != std_set.rend(); ++std_rit) {
	// 	std::cout << "[" << std_rit->first << "]" << " " << std_rit->second << " | ";
	// }
	// /////////////////////////////////////////////////////////////////////////
	// std::cout << std::endl << RED << LINE << RESET << std::endl;
	// std::cout << std::endl;
}

void testSetCapacity() 
{
    // int val;
    // std::set<int, int> std_set;
    // ft::set<int, int> ft_set;

    // std::cout << GREEN << "FT  set empty: " << RESET << ft_set.empty() << std::endl;
	// std::cout << GREEN << "STD set empty: " << RESET << std_set.empty() << std::endl << std::endl;

	// std::cout << GREEN << "FT  set size: " << RESET << ft_set.size() << std::endl;
	// std::cout << GREEN << "STD set size: " << RESET << std_set.size() << std::endl << std::endl;

    // std::cout << GREEN << "set elem: " << RESET;
    // for (int i = 0; i <= 10; i++) {
    //     val = rand() % 10;
    //     std_set[i] = val;
    //     ft_set[i] = val;
    //     std::cout << val << " ";
    // }
    // std::cout << std::endl << std::endl;

    // std::cout << GREEN << "FT  set size: " << RESET << ft_set.size() << std::endl;
	// std::cout << GREEN << "STD set size: " << RESET << std_set.size() << std::endl << std::endl;

    // std::cout << GREEN << "FT  set max size: " << RESET << ft_set.max_size() << std::endl;
	// std::cout << GREEN << "STD set max size: " << RESET << ft_set.max_size() << std::endl;

	// std::cout << RED << LINE << RESET << std::endl << std::endl;
}

void testSetElementAccess() 
{
	// int val;
	// std::set<int, int> std_set;
	// ft::set<int, int> ft_set;

    // std::cout << GREEN << "set elem: " << RESET;
    // for (int i = 0; i <= 10; i++) {
    //     val = rand() % 10;
    //     std_set[i] = val;
    //     ft_set[i] = val;
    //     std::cout << val << " ";
    // }
	// std::cout << std::endl << std::endl;
	// /////////////////////////////////////////////////////////////////////////
	// std::cout << GREEN << "FT  set elements: " << RESET;
	// ft::set<int, int>::iterator ft_it = ft_set.begin();
	// for (;ft_it != ft_set.end(); ++ft_it) {
	// 	std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << " | ";
	// }
	// std::cout << GREEN << "\nSTD set elements: " << RESET;
	// std::set<int, int>::iterator std_it = std_set.begin();
	// for (;std_it != std_set.end(); ++std_it) {
	// 	std::cout << "[" << std_it->first << "]" << " " << std_it->second << " | ";
	// }
	// std::cout << std::endl << std::endl;
	// /////////////////////////////////////////////////////////////////////////
    // int j = 10;
    // for (int i = 0; i <= 5; ++i) {
    //     ft_set[i] = ft_set[j];
    //     std_set[i] = std_set[j];
    //     j--;
    // }

    // ft_it = ft_set.begin();
    // std_it = std_set.begin();
	// /////////////////////////////////////////////////////////////////////////
    // std::cout << GREEN << "FT  set elements: " << RESET;
	// for (;ft_it != ft_set.end(); ++ft_it) {
	// 	std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << " | ";
	// }

	// std::cout << GREEN << "\nSTD set elements: " << RESET;
	// for (;std_it != std_set.end(); ++std_it) {
	// 	std::cout << "[" << std_it->first << "]" << " " << std_it->second << " | ";
	// }
    // /////////////////////////////////////////////////////////////////////////
    // std::cout << std::endl << RED << LINE << RESET << std::endl;
	// std::cout << std::endl;
}

void testSetModifiers() 
{
	// int val;
	// std::set<int, int> std_set;
	// ft::set<int, int> ft_set;

    // std::cout << GREEN << "set insert elem: " << RESET;
    // for (int i = 0; i <= 3; i++) {
    //     val = rand() % 10;
    //     std_set.insert(std::pair<int,int>(i, val));
    //     ft_set.insert(ft::pair<int,int>(i, val));
    //     std::cout << val << " ";
    // }
	// std::cout << std::endl << std::endl;
	// /////////////////////////////////////////////////////////////////////////
	// std::cout << GREEN << "FT  set elements: " << RESET;
	// ft::set<int, int>::iterator ft_it = ft_set.begin();
	// for (;ft_it != ft_set.end(); ++ft_it) {
	// 	std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << " | ";
	// }
	// std::cout << GREEN << "\nSTD set elements: " << RESET;
	// std::set<int, int>::iterator std_it = std_set.begin();
	// for (;std_it != std_set.end(); ++std_it) {
	// 	std::cout << "[" << std_it->first << "]" << " " << std_it->second << " | ";
	// }
	// std::cout << std::endl << std::endl;
	// /////////////////////////////////////////////////////////////////////////
	// ft_set.insert(ft_set.begin(), ft::pair<int,int>(4,777));
	// std_set.insert(std_set.begin(), std::pair<int,int>(4,777));
	// /////////////////////////////////////////////////////////////////////////
	// std::cout << GREEN << "FT  set elements: " << RESET;
	// ft_it = ft_set.begin();
	// for (;ft_it != ft_set.end(); ++ft_it) {
	// 	std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << " | ";
	// }
	// std::cout << GREEN << "\nSTD set elements: " << RESET;
	// std_it = std_set.begin();
	// for (;std_it != std_set.end(); ++std_it) {
	// 	std::cout << "[" << std_it->first << "]" << " " << std_it->second << " | ";
	// }
	// std::cout << std::endl << std::endl;
	// /////////////////////////////////////////////////////////////////////////
	// std::set<int, int> std_set1;
	// ft::set<int, int> ft_set1;

    // std::cout << GREEN << "set insert elem: " << RESET;
    // for (int i = 5; i <= 10; i++) {
    //     val = rand() % 10;
    //     std_set1.insert(std::pair<int,int>(i, val));
    //     ft_set1.insert(ft::pair<int,int>(i, val));
    //     std::cout << val << " ";
    // }
	// std::cout << std::endl << std::endl;

	// ft_set.insert(ft_set1.begin(), ft_set1.end());
	// std_set.insert(std_set1.begin(), std_set1.end());
	// /////////////////////////////////////////////////////////////////////////
	// std::cout << GREEN << "FT  set elements: " << RESET;
	// ft_it = ft_set.begin();
	// for (;ft_it != ft_set.end(); ++ft_it) {
	// 	std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << " | ";
	// }
	// std::cout << GREEN << "\nSTD set elements: " << RESET;
	// std_it = std_set.begin();
	// for (;std_it != std_set.end(); ++std_it) {
	// 	std::cout << "[" << std_it->first << "]" << " " << std_it->second << " | ";
	// }
	// std::cout << std::endl << std::endl;
	// /////////////////////////////////////////////////////////////////////////
	// ft_set.erase(ft_set.begin());
	// std_set.erase(std_set.begin());

	// std::cout << GREEN << "FT  set elements after erase: " << RESET;
	// ft_it = ft_set.begin();
	// for (;ft_it != ft_set.end(); ++ft_it) {
	// 	std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << " | ";
	// }
	// std::cout << GREEN << "\nSTD set elements after erase: " << RESET;
	// std_it = std_set.begin();
	// for (;std_it != std_set.end(); ++std_it) {
	// 	std::cout << "[" << std_it->first << "]" << " " << std_it->second << " | ";
	// }
	// std::cout << std::endl << std::endl;
	// /////////////////////////////////////////////////////////////////////////
	// ft_set.erase(5);
	// std_set.erase(5);
	// /////////////////////////////////////////////////////////////////////////
	// std::cout << GREEN << "FT  set elements after erase: " << RESET;
	// ft_it = ft_set.begin();
	// for (;ft_it != ft_set.end(); ++ft_it) {
	// 	std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << " | ";
	// }
	// std::cout << GREEN << "\nSTD set elements after erase: " << RESET;
	// std_it = std_set.begin();
	// for (;std_it != std_set.end(); ++std_it) {
	// 	std::cout << "[" << std_it->first << "]" << " " << std_it->second << " | ";
	// }
	// std::cout << std::endl << std::endl;
	// /////////////////////////////////////////////////////////////////////////
	// ft_it = ft_set.find(8);
	// std_it = std_set.find(8);

	// ft_set.erase(ft_set.begin(), ft_it);
	// std_set.erase(std_set.begin(), std_it);
	// /////////////////////////////////////////////////////////////////////////
	// std::cout << GREEN << "FT  set elements after erase: " << RESET;
	// ft_it = ft_set.begin();
	// for (;ft_it != ft_set.end(); ++ft_it) {
	// 	std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << " | ";
	// }

	// std::cout << GREEN << "\nSTD set elements after erase: " << RESET;
	// std_it = std_set.begin();
	// for (;std_it != std_set.end(); ++std_it) {
	// 	std::cout << "[" << std_it->first << "]" << " " << std_it->second << " | ";
	// }
	// std::cout << std::endl << std::endl;
	// /////////////////////////////////////////////////////////////////////////
	// ft_set.swap(ft_set1);
	// std_set.swap(std_set1);

	// std::cout << GREEN << "FT  set elements after swap: " << RESET;
	// ft_it = ft_set.begin();
	// for (;ft_it != ft_set.end(); ++ft_it) {
	// 	std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << " | ";
	// }

	// std::cout << GREEN << "\nSTD set elements after swap: " << RESET;
	// std_it = std_set.begin();
	// for (;std_it != std_set.end(); ++std_it) {
	// 	std::cout << "[" << std_it->first << "]" << " " << std_it->second << " | ";
	// }
	// std::cout << std::endl << std::endl;
	// /////////////////////////////////////////////////////////////////////////
	// ft_set.clear();
	// std_set.clear();

	// std::cout << GREEN << "FT  set elements after clear: " << RESET;
	// ft_it = ft_set.begin();
	// for (;ft_it != ft_set.end(); ++ft_it) {
	// 	std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << " | ";
	// }

	// std::cout << GREEN << "\nSTD set elements after clear: " << RESET;
	// std_it = std_set.begin();
	// for (;std_it != std_set.end(); ++std_it) {
	// 	std::cout << "[" << std_it->first << "]" << " " << std_it->second << " | ";
	// }
	// /////////////////////////////////////////////////////////////////////////
	// std::cout << std::endl << RED << LINE << RESET << std::endl << std::endl;
}

void testSetObserversModifiers() 
{

	// {
	// 	ft::set<char,int> ft_set;
	// 	std::set<char,int> std_set;

	// 	ft::set<char,int>::key_compare ft_comp = ft_set.key_comp();
	// 	std::set<char,int>::key_compare std_comp = std_set.key_comp();

	// 	ft_set['a']=100;
	// 	ft_set['b']=200;
	// 	ft_set['c']=300;

	// 	std_set['a']=100;
	// 	std_set['b']=200;
	// 	std_set['c']=300;

	// 	char ft_highest = ft_set.rbegin()->first;    
	// 	char std_highest = std_set.rbegin()->first;   
	// /////////////////////////////////////////////////////////////////////////
	// 	std::cout << GREEN << "FT  set elements: " << RESET;
	// 	ft::set<char,int>::iterator ft_it = ft_set.begin();
	// 	do {
	// 		std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << " | ";
	// 	} while ( ft_comp((*ft_it++).first, ft_highest) );
	// 	std::cout << std::endl;

	// 	std::cout << GREEN << "STD set elements: " << RESET;
	// 	std::set<char,int>::iterator std_it = std_set.begin();
	// 	do {
	// 		std::cout << "[" << std_it->first << "]" << " " << std_it->second << " | ";
	// 	} while ( std_comp((*std_it++).first, std_highest) );
	// 	std::cout << std::endl << std::endl;
	// /////////////////////////////////////////////////////////////////////////
	// }
	// {
	// 	ft::set<char,int> ft_set;
	// 	std::set<char,int> std_set;

	// 	ft_set['x']=1001;
	// 	ft_set['y']=2002;
	// 	ft_set['z']=3003;

	// 	std_set['x']=1001;
	// 	std_set['y']=2002;
	// 	std_set['z']=3003;

	// 	ft::pair<char,int> ft_highest = *ft_set.rbegin();
	// 	std::pair<char,int> std_highest = *std_set.rbegin();
	// /////////////////////////////////////////////////////////////////////////
	// 	std::cout << GREEN << "FT set elements:   " << RESET;
	// 	ft::set<char,int>::iterator ft_it = ft_set.begin();
	// 	do {
	// 		std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << " | ";
	// 	} while ( ft_set.value_comp()(*ft_it++, ft_highest) );
	// 	std::cout << std::endl;

	// 	std::cout << GREEN << "STD set elements:  " << RESET;
	// 	std::set<char,int>::iterator std_it = std_set.begin();
	// 	do {
	// 		std::cout << "[" << std_it->first << "]" << " " << std_it->second << " | ";
	// 	} while ( std_set.value_comp()(*std_it++, std_highest) );
	// 	std::cout << std::endl;
	// }
	// /////////////////////////////////////////////////////////////////////////
	// std::cout << RED << LINE << RESET << std::endl << std::endl;
}

void testSetOperationsModifiers() 
{
	// int val;
	// std::set<int, int> std_set;
	// ft::set<int, int> ft_set;

    // std::cout << GREEN << "set elem: " << RESET;
    // for (int i = 0; i <= 5; i++) {
    //     val = rand() % 10;
    //     std_set[i] = val;
    //     ft_set[i] = val;
    //     std::cout << val << " ";
    // }
	// std::cout << std::endl << std::endl;
	// /////////////////////////////////////////////////////////////////////////
	// std::cout << GREEN << "FT  set find elements: " << RESET;
	// for(int i = 0; i <= 5; i++) {
	// 	if (ft_set.count(i))
	// 		std::cout << "[" << ft_set.find(i)->first << "]" << " " << ft_set.find(i)->second << " | ";
	// }
	// std::cout << std::endl;

	// std::cout << GREEN << "STD set find elements: " << RESET;
	// for(int i = 0; i <= 5; i++) {
	// 	if (std_set.count(i))
	// 		std::cout << "[" << std_set.find(i)->first << "]" << " " << std_set.find(i)->second << " | ";
	// }
	// std::cout << std::endl << std::endl;
	// /////////////////////////////////////////////////////////////////////////
	// ft::set<int, int>::iterator ft_it = ft_set.begin();
	// std::cout << GREEN << "FT  set lower_bound: " << RESET;
	// ft_it = ft_set.lower_bound(4);
	// std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << std::endl;

	// std::set<int, int>::iterator std_it = std_set.begin();
	// std::cout << GREEN << "STD set lower_bound: " << RESET;
	// std_it = std_set.lower_bound(4);
	// std::cout << "[" << std_it->first << "]" << " " << std_it->second << std::endl<<std::endl;
	// /////////////////////////////////////////////////////////////////////////
	// std::cout << GREEN << "FT  set upper_bound: " << RESET;
	// ft_it = ft_set.upper_bound(4);
	// std::cout << "[" << ft_it->first << "]" << " " << ft_it->second << std::endl;

	// std::cout << GREEN << "STD set upper_bound: " << RESET;
	// std_it = std_set.upper_bound(4);
	// std::cout << "[" << std_it->first << "]" << " " << std_it->second << std::endl;
	// std::cout << std::endl;
	// /////////////////////////////////////////////////////////////////////////
	// std::cout << GREEN << "FT  set equal_range: " << RESET;
	// ft::pair<ft::set<int,int>::iterator, ft::set<int,int>::iterator> ft_ret = ft_set.equal_range(3);
	// std::cout << "[" << ft_ret.first->first << "]" << " " << ft_ret.second->second << std::endl;

	// std::cout << GREEN << "STD set equal_range: " << RESET;
	// std::pair<std::set<int,int>::iterator, std::set<int,int>::iterator> std_ret = std_set.equal_range(3);
	// std::cout << "[" << ft_ret.first->first << "]" << " " << std_ret.second->second << std::endl;
	// /////////////////////////////////////////////////////////////////////////
	// std::cout << RED << LINE << RESET << std::endl << std::endl;
}

void testSetSpeed() {
	// 	/////////////////////////////////////////////////////////////////////////
	// {
	// 	ft::set<int, int> ft_set;
	// 	time_t start, end;

	// 	time(&start);
	// 	for (int i = 0; i < 10000000; i++) {
	// 		ft_set.insert(ft::pair<int, int>(i, i));
	// 	}
	// 	time(&end);
	// 	double seconds = difftime(end, start);
	// 	std::cout << GREEN << "FT  set insert: " << RESET; 
	// 	std::cout << seconds << " sec" << std::endl;
	// }
	// /////////////////////////////////////////////////////////////////////////
	// {
	// 	std::set<int, int> std_set;
	// 	time_t start, end;

	// 	time(&start);
	// 	for (int i = 0; i < 10000000; i++) {
	// 		std_set.insert(std::pair<int, int>(i, i));
	// 	}
	// 	time(&end);

	// 	double seconds = difftime(end, start);
	// 	std::cout << GREEN << "STD set insert: " << RESET; 
	// 	std::cout << seconds << " sec" << std::endl<<std::endl;
	// }
	// /////////////////////////////////////////////////////////////////////////
	// {
	// 	ft::set<int, int> ft_set;
	// 	time_t start, end;

	// 	for (int i = 0; i < 10000000; i++) {
	// 		ft_set.insert(ft::pair<int, int>(i, i));
	// 	}
	// 	time(&start);
	// 	for (int i = 10000000; i > 0; i--) {
	// 		ft_set.erase(i);
	// 	}
	// 	time(&end);
	// 	double seconds = difftime(end, start);
	// 	std::cout << GREEN << "FT  set erase: " << RESET; 
	// 	std::cout << seconds << " sec" << std::endl;
	// }
	// /////////////////////////////////////////////////////////////////////////
	// {
	// 	std::set<int, int> std_set;
	// 	time_t start, end;

	// 	for (int i = 0; i < 10000000; i++) {
	// 		std_set.insert(std::pair<int, int>(i, i));
	// 	}
	// 	time(&start);
	// 	for (int i = 10000000; i > 0; i--) {
	// 		std_set.erase(i);
	// 	}
	// 	time(&end);

	// 	double seconds = difftime(end, start);
	// 	std::cout << GREEN << "STD set erase: " << RESET; 
	// 	std::cout << seconds << " sec" << std::endl << std::endl;
	// }
	// /////////////////////////////////////////////////////////////////////////
	// {
	// 	ft::set<int, int> ft_set;
	// 	time_t start, end;

	// 	for (int i = 0; i < 10000000; i++) {
	// 		ft_set.insert(ft::pair<int, int>(i, i));
	// 	}
	// 	time(&start);
	// 	ft_set.find(10000000);
	// 	time(&end);
	// 	double seconds = difftime(end, start);
	// 	std::cout << GREEN << "FT  set find: " << RESET; 
	// 	std::cout << seconds << " sec" << std::endl;
	// }
	// /////////////////////////////////////////////////////////////////////////
	// {
	// 	std::set<int, int> std_set;
	// 	time_t start, end;

	// 	for (int i = 0; i < 10000000; i++) {
	// 		std_set.insert(std::pair<int, int>(i, i));
	// 	}
	// 	time(&start);
	// 	std_set.find(10000000);
	// 	time(&end);
	// 	double seconds = difftime(end, start);
	// 	std::cout << GREEN << "FT  set find: " << RESET; 
	// 	std::cout << seconds << " sec" << std::endl;
	// }
	// std::cout << RED << LINE << RESET << std::endl;
	// std::cout << MAGENTA<< LINE << std::endl << std::endl;
}