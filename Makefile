NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = 

RM = rm -rf

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc -o $(NAME) $(OBJS)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re