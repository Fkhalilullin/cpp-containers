NAME = test

SRCS = main.cpp testContainers/vectorTest.cpp testContainers/stackTest.cpp testContainers/mapTest.cpp testContainers/setTest.cpp

OBJS = $(SRCS:.cpp=.o)

CLANG = clang++ -g -Wall -Werror -Wextra
all: $(NAME)

$(NAME): $(OBJS)
	$(CLANG) $(OBJS) -o $(NAME)

$(OBJS): %.o : %.cpp
	$(CLANG) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all