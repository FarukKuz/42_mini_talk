NAME_SERVER = server
NAME_CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = server.c client.c ft_atoi.c
OBJS = $(SRC:.c=.o)

PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

RM = rm -rf

all: $(PRINTF_LIB) $(NAME_SERVER) $(NAME_CLIENT)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME_SERVER): server.o ft_atoi.o $(PRINTF_LIB)
	$(CC) $(CFLAGS) $^ -o $(NAME_SERVER)

$(NAME_CLIENT): client.o ft_atoi.o $(PRINTF_LIB)
	$(CC) $(CFLAGS) $^ -o $(NAME_CLIENT)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re