NAME = buttle
CC = clang++
CFLAG = -Wall -Wextra -Werror -std=c++98
INCLUDES = Weapon.hpp HumanA.hpp HumanB.hpp
SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
O_FILES = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(O_FILES) $(INCLUDES)
	$(CC) $(CFLAG) $(O_FILES) -I$(INCLUDES) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(O_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
