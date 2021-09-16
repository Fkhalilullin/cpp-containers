#include "../map/map.hpp"
#include <map>
#include <iostream>

void mapTest() {
    ft::map<int,int> map;
    ft::pair<int, int> pair_1(5, 6);
    ft::pair<int, int> pair_2(10, 3);
    ft::pair<int, int> pair_3(3, 9);
    map.insert(pair_1);
    map.insert(pair_2);
    map.insert(pair_3);
    ft::map<int, int>::iterator it = map.begin();
    std::cout << it->first << " " << it->second << std::endl;
    ++it;
    std::cout << it->first << " " << it->second << std::endl;
    ++it;
    std::cout << it->first << " " << it->second << std::endl;

}