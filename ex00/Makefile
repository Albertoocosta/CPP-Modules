NAME = Megaphone
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = megaphone.cpp
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(NAME) $(OBJS)

fclean: clean

re: fclean all