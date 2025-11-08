NAME	= PhoneBook

CC		= c++

CFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC		= Contact.cpp PhoneBook.cpp  Main.cpp

OBJ 	= $(SRC:.cpp=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo '$(NAME) is compiled!'

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re