
#include <iostream>
#include <iomanip>
#include <string.h>

#include "vector/vector.hpp"
#include "testContainers/vectorTest.hpp"

#include "stack/stack.hpp"
#include "testContainers/stackTest.hpp"

#include "map/map.hpp"
#include "testContainers/mapTest.hpp"

#include "set/set.hpp"
#include "testContainers/setTest.hpp"

void vectorTest() 
{
	std::cout << MAGENTA << "[VECTOR TEST]" << RESET << std::endl;
	std::cout << MAGENTA << LINE  << std::endl;

	std::cout << RED << "<Iterator Test>" << RESET << std::endl;
	std::cout << RED << LINE << RESET << std::endl;
	testVectorIterator();

	std::cout << RED << "<Capacity Test>" << RESET << std::endl;
	std::cout << RED << LINE << RESET << std::endl;
	testVectorCapacity();

	std::cout << RED << "<Element Access>" << RESET << std::endl;
	std::cout << RED << LINE << RESET << std::endl;
	testVectorElementAccess();

	std::cout << RED << "<Modifiers>" << RESET << std::endl;
	std::cout << RED << LINE << RESET << std::endl;
	testVectorModifiers();

	std::cout << RED << "<Speed>" << RESET << std::endl;
	std::cout << RED << LINE << RESET << std::endl;
	testVectorSpeed();
}

void stackTest() 
{
	std::cout << MAGENTA << "[STACK TEST]" << RESET << std::endl;
	std::cout << MAGENTA << LINE  << std::endl;
	std::cout << RED << "<Member Function Test>" << RESET << std::endl;
	std::cout << RED << LINE << RESET << std::endl;
	testMemberFunction();
}

void mapTest() 
{
	std::cout << MAGENTA << "[MAP TEST]" << RESET << std::endl;
	std::cout << MAGENTA << LINE  << std::endl;

	std::cout << RED << "<Iterator Test>" << RESET << std::endl;
	std::cout << RED << LINE << RESET << std::endl;
	testMapIterator();

	std::cout << RED << "<Capacity Test>" << RESET << std::endl;
	std::cout << RED << LINE << RESET << std::endl;
	testMapCapacity();

	std::cout << RED << "<Element Access>" << RESET << std::endl;
	std::cout << RED << LINE << RESET << std::endl;
	testMapElementAccess();

	std::cout << RED << "<Modifiers>" << RESET << std::endl;
	std::cout << RED << LINE << RESET << std::endl;
	testMapModifiers();

	std::cout << RED << "<Observers>" << RESET << std::endl;
	std::cout << RED << LINE << RESET << std::endl;
	testObserversModifiers();

	std::cout << RED << "<Operations>" << RESET << std::endl;
	std::cout << RED << LINE << RESET << std::endl;
	testOperationsModifiers();

	std::cout << RED << "<Speed>" << RESET << std::endl;
	std::cout << RED << LINE << RESET << std::endl;
	testMapSpeed();
}

// void setTest() 
// {
// 	std::cout << MAGENTA << "[SET TEST]" << RESET << std::endl;
// 	std::cout << MAGENTA << LINE  << std::endl;

// 	std::cout << RED << "<Iterator Test>" << RESET << std::endl;
// 	std::cout << RED << LINE << RESET << std::endl;
// 	testSetIterator();

// 	std::cout << RED << "<Capacity Test>" << RESET << std::endl;
// 	std::cout << RED << LINE << RESET << std::endl;
// 	testSetCapacity();

// 	std::cout << RED << "<Element Access>" << RESET << std::endl;
// 	std::cout << RED << LINE << RESET << std::endl;
// 	testSetElementAccess();

// 	std::cout << RED << "<Modifiers>" << RESET << std::endl;
// 	std::cout << RED << LINE << RESET << std::endl;
// 	testSetModifiers();

// 	std::cout << RED << "<Observers>" << RESET << std::endl;
// 	std::cout << RED << LINE << RESET << std::endl;
// 	testSetObserversModifiers();

// 	std::cout << RED << "<Operations>" << RESET << std::endl;
// 	std::cout << RED << LINE << RESET << std::endl;
// 	testSetOperationsModifiers();

// 	std::cout << RED << "<Speed>" << RESET << std::endl;
// 	std::cout << RED << LINE << RESET << std::endl;
// 	testSetSpeed();
// }

int main() 
{
	srand(time(NULL));
	std::string cont;

	while (1) {
		std::cout << MAGENTA << "Input Containers for testing [vector, stack, map, set]: " << RESET;
		std::getline(std::cin, cont);
		if (cont == "vector") 
			vectorTest();
		else if (cont == "stack")
			stackTest();
		else if (cont == "map") 
			mapTest();
		// else if (cont == "set")
			// setTest();
		else
			std::cout << "Wrong Input" << std::endl;
	}
	return 0;
}