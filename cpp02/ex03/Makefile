NAME = BSP
CC = clang++
CFLAG = -Wall -Wextra -Werror -std=c++98
INCLUDES = Fixed.hpp Point.hpp
SRCS = main.cpp Fixed.cpp Point.cpp bsp.cpp
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