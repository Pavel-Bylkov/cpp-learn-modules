NAME = test2
CC = clang++
CFLAG = -Wall -Wextra -Werror -std=c++98
INCLUDES = ClapTrap.hpp ScavTrap.hpp
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp
O_FILES = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(O_FILES) $(INCLUDES)
	$(CC) $(CFLAG) $(O_FILES) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(O_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re