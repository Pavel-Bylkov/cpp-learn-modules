
NAME =  getstring
CC = clang++
CFLAG = -Wall -Wextra -Werror
INCLUDES = mystring.hpp
SRCS = main.cpp mystring.cpp
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