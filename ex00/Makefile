NAME = megaphone
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = megaphone.cpp

all: $(NAME)

$(NAME): $(SRCFILE)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all