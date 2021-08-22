NAME = test

SRCS = main.cpp

HEADER = ft_vector/reverse_iterator.hpp ft_vector/vector.hpp ft_vector/random_access_iterator.hpp

OBJS = $(SRCS:.cpp=.o)

CLANG = clang++ -Wshadow -Wno-shadow -Wall -Werror -Wextra
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