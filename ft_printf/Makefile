CC = cc

FLAGS = -Wall -Wextra -Werror

SRC_DIR = src

FUNCTIONS = $(SRC_DIR)/ft_putnbr.c \
	    $(SRC_DIR)/ft_putchar.c \
	    $(SRC_DIR)/ft_putstr.c \
	    $(SRC_DIR)/format.c \
	    $(SRC_DIR)/ft_print_hex.c \
	    $(SRC_DIR)/ft_putnbr_u.c \
	    $(SRC_DIR)/ft_print_pointer.c \
	    ft_printf.c

OBJS = $(FUNCTIONS:.c=.o)

NAME = libftprintf.a

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)
all: $(NAME)

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)
clean:
	@rm -f $(OBJS)
fclean: clean
	@rm -f $(NAME)

re: fclean all
