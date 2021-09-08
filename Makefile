NAME = test

SRCS = main.cpp testContainers/vectorTest.cpp testContainers/stackTest.cpp

HEADER = vector/reverse_iterator.hpp vector/vector.hpp vector/random_access_iterator.hpp map/pair.hpp

OBJS = $(SRCS:.cpp=.o)

CLANG = clang++ -g -Wall -Werror -Wextra
all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CLANG) $(OBJS) -o $(NAME)

$(OBJS): %.o : %.cpp
	$(CLANG) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all