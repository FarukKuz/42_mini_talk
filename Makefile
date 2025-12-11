NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = server.c client.c ft_atoi.c
SRC_BONUS = server_bonus.c client_bonus.c ft_atoi.c

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

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

bonus: $(PRINTF_LIB) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): server_bonus.o ft_atoi.o $(PRINTF_LIB)
	$(CC) $(CFLAGS) $^ -o $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): client_bonus.o ft_atoi.o $(PRINTF_LIB)
	$(CC) $(CFLAGS) $^ -o $(NAME_CLIENT_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus