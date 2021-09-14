#include "../map/map.hpp"
#include <map>
#include <iostream>

void mapTest() {
    RBTree<int> tree;
 
    tree.insert(7);
    tree.insert(3);
    tree.insert(18);
    tree.insert(10);
    tree.insert(22);
    tree.insert(8);
    tree.insert(11);
    tree.insert(26);
    tree.insert(2);
    tree.insert(6);
    tree.insert(13);
    
    tree.printInOrder();
    tree.printLevelOrder();
    
    std::cout<<std::endl<<"Deleting 18, 11, 3, 10, 22"<<std::endl;
    
    tree.deleteByVal(18);
    tree.deleteByVal(11);
    tree.deleteByVal(3);
    tree.deleteByVal(10);
    tree.deleteByVal(22);
    
    tree.printInOrder();
    tree.printLevelOrder();
}