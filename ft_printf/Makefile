NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_putchr.c ft_putstr.c ft_print_mem_adress.c ft_putnbr.c\
		ft_print_hex.c ft_putunsigned.c

RM = rm -rf

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	ar rcs -o $(NAME) $(OBJS)

all: $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
