NAME = recap
CC = clang++
CFLAG = -Wall -Wextra -Werror -std=c++98
INCLUDES = AMateria.hpp ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp Character.hpp Cure.hpp Ice.hpp
SRCS = main.cpp AMateria.cpp Character.cpp MateriaSource.cpp Cure.cpp Ice.cpp
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