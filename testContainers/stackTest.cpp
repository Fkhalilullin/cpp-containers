#define RESET	"\033[0m"
#define GREEN	"\033[32m"
#define RED		"\033[31m"
#define MAGNETA "\033[35m"
#define LINE	"-----------------------------------------------"

#include "../stack/stack.hpp"
#include <stack>
#include <vector>

void testMemberFunction() {
	std::vector<int> vec;

	std::cout << GREEN << "Vector elem: " << RESET;
	for (int i = 0; i < 10; i++) {
		vec.push_back(rand() % 123 );
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	ft::stack<int, std::vector<int> > ft_s1(vec);
	std::stack<int, std::vector<int> > std_s1(vec);

	ft::stack<int> ft_s2;
	std::stack<int> std_s2;
	std::cout << GREEN << "FT stack 1 empty: " << RESET << ft_s1.empty() << std::endl;
	std::cout << GREEN << "STD stack 1 empty: " << RESET << std_s1.empty() << std::endl << std::endl;

	std::cout << GREEN << "FT stack 1 size: " << RESET << ft_s1.size() << std::endl;
	std::cout << GREEN << "STD stack 1 size: " << RESET << std_s1.size() << std::endl << std::endl;

	std::cout << GREEN << "FT stack 2 empty: " << RESET << ft_s2.empty() << std::endl;
	std::cout << GREEN << "STD stack 2 empty: " << RESET << std_s2.empty() << std::endl << std::endl;

	std::cout << GREEN << "FT stack top: " << RESET << ft_s1.top() << std::endl;
	std::cout << GREEN << "STD stack top: " << RESET << std_s1.top() << std::endl << std::endl;

	ft_s1.push(777);
	std_s1.push(777);

	std::cout << GREEN << "FT stack top after push: " << RESET << ft_s1.top() << std::endl;
	std::cout << GREEN << "STD stack top after push: " << RESET << std_s1.top() << std::endl << std::endl;

	ft_s1.top() += 111;
	std_s1.top() += 111;

	std::cout << GREEN << "FT stack top: " << RESET << ft_s1.top() << std::endl;
	std::cout << GREEN << "STD stack top: " << RESET << std_s1.top() << std::endl << std::endl;

	ft_s1.pop();
	std_s1.pop();
	ft_s1.pop();
	std_s1.pop();

	std::cout << GREEN << "FT stack top: " << RESET << ft_s1.top() << std::endl;
	std::cout << GREEN << "STD stack top: " << RESET << std_s1.top() << std::endl << std::endl;

	std::cout << GREEN << "FT Stack elem: " << RESET;
	while (!ft_s1.empty())
  	{
		std::cout << ' ' << ft_s1.top();
		ft_s1.pop();
	}
	std::cout << std::endl;

	std::cout << GREEN << "STD Stack elem: " << RESET;
	while (!std_s1.empty())
  	{
		std::cout << ' ' << std_s1.top();
		std_s1.pop();
	}
	std::cout << std::endl;
	std::cout << RED << LINE << RESET << std::endl << std::endl;
}