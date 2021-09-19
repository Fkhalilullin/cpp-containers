
#include <iostream>
#include <iomanip>
#include <string.h>

#include "vector/vector.hpp"
#include "testContainers/vectorTest.hpp"

#include "stack/stack.hpp"
#include "testContainers/stackTest.hpp"

#include "map/map.hpp"
#include "testContainers/mapTest.hpp"

#define RESET	"\033[0m"
#define GREEN	"\033[32m"
#define RED		"\033[31m"
#define MAGENTA "\033[35m"
#define LINE	"-----------------------------------------------"

void vectorTest() {
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
}

void stackTest() {
	std::cout << MAGENTA << "[STACK TEST]" << RESET << std::endl;
	std::cout << MAGENTA << LINE  << std::endl;
	std::cout << RED << "<Member Function Test>" << RESET << std::endl;
	std::cout << RED << LINE << RESET << std::endl;
	testMemberFunction();
}

void mapTest() {
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
}

int main() {
	srand(time(NULL));
	std::string cont;

	while (1) {
		std::cout << MAGENTA << "Input Containers for testing [vector, stack, map]: " << RESET;
		std::getline(std::cin, cont);
		if (cont == "vector") 
			vectorTest();
		else if (cont == "stack")
			stackTest();
		else if (cont == "map") 
			mapTest();
		else
			std::cout << "Wrong Input" << std::endl;
	}
	return 0;
}