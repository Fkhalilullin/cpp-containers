
#include <iostream>
#include <iomanip>
#include <string.h>

#include "vector/vector.hpp"
#include "testContainers/vectorTest.hpp"

#include "stack/stack.hpp"
#include "testContainers/stackTest.hpp"

#include "map/map.hpp"


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
	testIterator();

	std::cout << RED << "<Capacity Test>" << RESET << std::endl;
	std::cout << RED << LINE << RESET << std::endl;
	testCapacity();

	std::cout << RED << "<Element Access>" << RESET << std::endl;
	std::cout << RED << LINE << RESET << std::endl;
	testElementAccess();


	std::cout << RED << "<Modifiers>" << RESET << std::endl;
	std::cout << RED << LINE << RESET << std::endl;
	testModifiers();
}

void stackTest() {
	std::cout << MAGENTA << "[STACK TEST]" << RESET << std::endl;
	std::cout << MAGENTA << LINE  << std::endl;
	std::cout << RED << "<Member Function Test>" << RESET << std::endl;
	std::cout << RED << LINE << RESET << std::endl;
	testMemberFunction();
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
		// else if (cont == "map") 
			// mapTest();
		else
			std::cout << "Wrong Input" << std::endl;
	}
	return 0;
}