FLAGS = -Wall -Wextra -Werror

MAP_PARSING_DIR = map_parsing

GAME_DIR = src/mandatory

GAME_BONUS_DIR = src/bonus

DIR_PRINTF = ft_printf

DIR_GNL = get_next_line

DIR_PRINTF_SRC = ft_printf/src

LIB_PRINTF = $(DIR_PRINTF)/libftprintf.a

FUNCTIONS =	main.c \
			$(MAP_PARSING_DIR)/map_error.c \
			$(MAP_PARSING_DIR)/map_counting.c \
			$(MAP_PARSING_DIR)/create_map.c \
			$(MAP_PARSING_DIR)/map_parsing_utils.c \
			$(MAP_PARSING_DIR)/map_check.c \
			$(MAP_PARSING_DIR)/free_map.c \
			$(MAP_PARSING_DIR)/flood_fill.c \
			$(MAP_PARSING_DIR)/strlcpy.c \
			$(GAME_DIR)/init_game.c \
			$(GAME_DIR)/draw_collectable.c \
			$(GAME_DIR)/mlx_error.c \
			$(GAME_DIR)/game_utils.c \
			$(GAME_DIR)/load_images.c \
			$(GAME_DIR)/game_utils.c \
			$(GAME_DIR)/is_wall.c \
			$(GAME_DIR)/draw_game_stuff.c \
			$(GAME_DIR)/movement_structure.c \
			$(GAME_DIR)/handle_key_events.c \
			$(GAME_DIR)/count_squares.c \
			$(GAME_DIR)/animate_exit.c \
			$(GAME_DIR)/can_exit.c \
			$(GAME_DIR)/is_collectable.c
 
OBJS =	main.o \
		$(MAP_PARSING_DIR)/map_error.o \
		$(MAP_PARSING_DIR)/map_counting.o \
		$(MAP_PARSING_DIR)/create_map.o \
		$(MAP_PARSING_DIR)/map_parsing_utils.o \
		$(MAP_PARSING_DIR)/map_check.o \
		$(MAP_PARSING_DIR)/free_map.o \
		$(MAP_PARSING_DIR)/flood_fill.o \
		$(MAP_PARSING_DIR)/strlcpy.o \
		$(GAME_DIR)/init_game.o \
		$(GAME_DIR)/draw_collectable.o \
		$(GAME_DIR)/mlx_error.o \
		$(GAME_DIR)/game_utils.o \
		$(GAME_DIR)/load_images.o \
		$(GAME_DIR)/game_utils.o \
		$(GAME_DIR)/is_wall.o \
		$(GAME_DIR)/draw_game_stuff.o \
		$(GAME_DIR)/movement_structure.o \
		$(GAME_DIR)/handle_key_events.o \
		$(GAME_DIR)/count_squares.o \
		$(GAME_DIR)/animate_exit.o \
		$(GAME_DIR)/can_exit.o \
		$(GAME_DIR)/is_collectable.o

BONUS_FUNCTIONS = main.c \
			$(MAP_PARSING_DIR)/map_error.c \
			$(MAP_PARSING_DIR)/map_counting.c \
			$(MAP_PARSING_DIR)/create_map.c \
			$(MAP_PARSING_DIR)/map_parsing_utils.c \
			$(MAP_PARSING_DIR)/map_check_bonus.c \
			$(MAP_PARSING_DIR)/free_map.c \
			$(MAP_PARSING_DIR)/flood_fill.c \
			$(MAP_PARSING_DIR)/valid_chars_bonus.c \
			$(GAME_BONUS_DIR)/init_game_bonus.c \
			$(GAME_BONUS_DIR)/draw_collectable_bonus.c \
			$(GAME_BONUS_DIR)/enemy_utils_bonus.c \
			$(GAME_BONUS_DIR)/free_stuff_bonus.c \
			$(GAME_BONUS_DIR)/abs_and_max_bonus.c \
			$(GAME_BONUS_DIR)/mlx_error_bonus.c \
			$(GAME_BONUS_DIR)/game_utils_bonus.c \
			$(GAME_BONUS_DIR)/load_images_bonus.c \
			$(GAME_BONUS_DIR)/game_utils_bonus.c \
			$(GAME_BONUS_DIR)/create_projectile_bonus.c \
			$(GAME_BONUS_DIR)/is_wall_bonus.c \
			$(GAME_BONUS_DIR)/itoa_bonus.c \
			$(GAME_BONUS_DIR)/create_enemies_bonus.c \
			$(GAME_BONUS_DIR)/draw_movements_bonus.c \
			$(GAME_BONUS_DIR)/draw_game_stuff_bonus.c \
			$(GAME_BONUS_DIR)/handle_key_events_bonus.c \
			$(GAME_BONUS_DIR)/movement_structure_bonus.c \
			$(GAME_BONUS_DIR)/load_enemy_bonus.c \
			$(GAME_BONUS_DIR)/animate_exit_bonus.c \
			$(GAME_BONUS_DIR)/count_squares_bonus.c \
			$(GAME_BONUS_DIR)/can_exit_bonus.c \
			$(GAME_BONUS_DIR)/is_collectable_bonus.c
 
BONUS_OBJS = main.o \
		$(MAP_PARSING_DIR)/map_error.o \
		$(MAP_PARSING_DIR)/map_counting.o \
		$(MAP_PARSING_DIR)/create_map.o \
		$(MAP_PARSING_DIR)/map_parsing_utils.o \
		$(MAP_PARSING_DIR)/map_check_bonus.o \
		$(MAP_PARSING_DIR)/free_map.o \
		$(MAP_PARSING_DIR)/flood_fill.o \
		$(MAP_PARSING_DIR)/valid_chars_bonus.o \
		$(GAME_BONUS_DIR)/init_game_bonus.o \
		$(GAME_BONUS_DIR)/draw_collectable_bonus.o \
		$(GAME_BONUS_DIR)/enemy_utils_bonus.o \
		$(GAME_BONUS_DIR)/free_stuff_bonus.o \
		$(GAME_BONUS_DIR)/abs_and_max_bonus.o \
		$(GAME_BONUS_DIR)/mlx_error_bonus.o \
		$(GAME_BONUS_DIR)/game_utils_bonus.o \
		$(GAME_BONUS_DIR)/load_images_bonus.o \
		$(GAME_BONUS_DIR)/game_utils_bonus.o \
		$(GAME_BONUS_DIR)/create_projectile_bonus.o \
		$(GAME_BONUS_DIR)/is_wall_bonus.o \
		$(GAME_BONUS_DIR)/itoa_bonus.o \
		$(GAME_BONUS_DIR)/create_enemies_bonus.o \
		$(GAME_BONUS_DIR)/draw_movements_bonus.o \
		$(GAME_BONUS_DIR)/draw_game_stuff_bonus.o \
		$(GAME_BONUS_DIR)/handle_key_events_bonus.o \
		$(GAME_BONUS_DIR)/movement_structure_bonus.o \
		$(GAME_BONUS_DIR)/load_enemy_bonus.o \
		$(GAME_BONUS_DIR)/animate_exit_bonus.o \
		$(GAME_BONUS_DIR)/count_squares_bonus.o \
		$(GAME_BONUS_DIR)/can_exit_bonus.o \
		$(GAME_BONUS_DIR)/is_collectable_bonus.o

LIB = so_long.a

LIB_BONUS = so_long_bonus.a

NAME = so_long

NAME_BONUS = so_long_bonus

.c.o:
	@cc $(FLAGS) -c $< -o $(<:.c=.o)
all: $(LIB_PRINTF) $(NAME)

$(LIB_PRINTF):
	$(MAKE) -C $(DIR_PRINTF)

$(NAME): $(OBJS)
	@clear
	@rm -f $(NAME_BONUS) $(LIB_BONUS)
	@ar -rc $(LIB) $(OBJS)
	@cc $(FLAGS) main.c $(LIB) $(LIB_PRINTF) $(DIR_GNL)/get_next_line.c $(DIR_GNL)/get_next_line_utils.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext -o $(NAME)
	@echo "\033[40;40m░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\033[0m"
	@echo "\033[40;40m░░░░░░░▄▄▀▀▀▀▀▀▀▀▀▀▄▄█▄░░░░▄░░░░█░░░░░░░\033[0m"
	@echo "\033[40;40m░░░░░░█▀░░░░░░░░░░░░░▀▀█▄░░░▀░░░░░░░░░▄░\033[0m"
	@echo "\033[40;40m░░░░▄▀░░░░░░░░░░░░░░░░░▀██░░░▄▀▀▀▄▄░░▀░░\033[0m"
	@echo "\033[40;40m░░▄█▀▄█▀▀▀▀▄░░░░░░▄▀▀█▄░▀█▄░░█▄░░░▀█░░░░\033[0m"
	@echo "\033[40;40m░▄█░▄▀░░▄▄▄░█░░░▄▀▄█▄░▀█░░█▄░░▀█░░░░█░░░\033[0m"
	@echo "\033[40;40m▄█░░█░░░▀▀▀░█░░▄█░▀▀▀░░█░░░█▄░░█░░░░█░░░\033[0m"
	@echo "\033[40;40m██░░░▀▄░░░▄█▀░░░▀▄▄▄▄▄█▀░░░▀█░░█▄░░░█░░░\033[0m"
	@echo "\033[40;40m██░░░░░▀▀▀░░░░░░░░░░░░░░░░░░█░▄█░░░░█░░░\033[0m"
	@echo "\033[40;40m██░░░░░░░░░░░░░░░░░░░░░█░░░░██▀░░░░█▄░░░\033[0m"
	@echo "\033[40;40m██░░░░░░░░░░░░░░░░░░░░░█░░░░█░░░░░░░▀▀█▄\033[0m"
	@echo "\033[40;40m██░░░░░░░░░░░░░░░░░░░░█░░░░░█░░░░░░░▄▄██\033[0m"
	@echo "\033[40;40m░██░░░░░░░░░░░░░░░░░░▄▀░░░░░█░░░░░░░▀▀█▄\033[0m"
	@echo "\033[40;40m░▀█░░░░░░█░░░░░░░░░▄█▀░░░░░░█░░░░░░░▄▄██\033[0m"
	@echo "\033[40;40m░▄██▄░░░░░▀▀▀▄▄▄▄▀▀░░░░░░░░░█░░░░░░░▀▀█▄\033[0m"
	@echo "\033[40;40m░░▀▀▀▀░░░░░░░░░░░░░░░░░░░░░░█▄▄▄▄▄▄▄▄▄██\033[0m"
	@echo "\033[40;40m░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\033[0m"
	@echo "\033[46mso long was created succesfully!\033[0m"
clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
fclean:
	@rm -f $(OBJS) $(BONUS_OBJS) $(LIB_BONUS) $(LIB) $(NAME) $(NAME_BONUS)
	@rm -f $(DIR_PRINTF)/ft_printf.o  $(DIR_PRINTF)/libftprintf.a
	@rm -f $(DIR_PRINTF_SRC)/format.o $(DIR_PRINTF_SRC)/ft_print_hex.o $(DIR_PRINTF_SRC)/ft_print_pointer.o
	@rm -f $(DIR_PRINTF_SRC)/ft_putchar.o $(DIR_PRINTF_SRC)/ft_putnbr.o $(DIR_PRINTF_SRC)/ft_putnbr_u.o
	@rm -f $(DIR_PRINTF_SRC)/ft_putstr.o
re: fclean all

bonus: $(BONUS_OBJS)
	@clear
	@rm -f $(NAME) $(LIB)
	@ar -rc $(LIB_BONUS) $(BONUS_OBJS)
	@cc $(FLAGS) main_bonus.c $(LIB_BONUS) $(DIR_GNL)/get_next_line.c $(DIR_GNL)/get_next_line_utils.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext -o $(NAME_BONUS)
	@echo "\033[40;40m░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\033[0m"
	@echo "\033[40;40m░░░░░░░▄▄▀▀▀▀▀▀▀▀▀▀▄▄█▄░░░░▄░░░░█░░░░░░░\033[0m"
	@echo "\033[40;40m░░░░░░█▀░░░░░░░░░░░░░▀▀█▄░░░▀░░░░░░░░░▄░\033[0m"
	@echo "\033[40;40m░░░░▄▀░░░░░░░░░░░░░░░░░▀██░░░▄▀▀▀▄▄░░▀░░\033[0m"
	@echo "\033[40;40m░░▄█▀▄█▀▀▀▀▄░░░░░░▄▀▀█▄░▀█▄░░█▄░░░▀█░░░░\033[0m"
	@echo "\033[40;40m░▄█░▄▀░░▄▄▄░█░░░▄▀▄█▄░▀█░░█▄░░▀█░░░░█░░░\033[0m"
	@echo "\033[40;40m▄█░░█░░░▀▀▀░█░░▄█░▀▀▀░░█░░░█▄░░█░░░░█░░░\033[0m"
	@echo "\033[40;40m██░░░▀▄░░░▄█▀░░░▀▄▄▄▄▄█▀░░░▀█░░█▄░░░█░░░\033[0m"
	@echo "\033[40;40m██░░░░░▀▀▀░░░░░░░░░░░░░░░░░░█░▄█░░░░█░░░\033[0m"
	@echo "\033[40;40m██░░░░░░░░░░░░░░░░░░░░░█░░░░██▀░░░░█▄░░░\033[0m"
	@echo "\033[40;40m██░░░░░░░░░░░░░░░░░░░░░█░░░░█░░░░░░░▀▀█▄\033[0m"
	@echo "\033[40;40m██░░░░░░░░░░░░░░░░░░░░█░░░░░█░░░░░░░▄▄██\033[0m"
	@echo "\033[40;40m░██░░░░░░░░░░░░░░░░░░▄▀░░░░░█░░░░░░░▀▀█▄\033[0m"
	@echo "\033[40;40m░▀█░░░░░░█░░░░░░░░░▄█▀░░░░░░█░░░░░░░▄▄██\033[0m"
	@echo "\033[40;40m░▄██▄░░░░░▀▀▀▄▄▄▄▀▀░░░░░░░░░█░░░░░░░▀▀█▄\033[0m"
	@echo "\033[40;40m░░▀▀▀▀░░░░░░░░░░░░░░░░░░░░░░█▄▄▄▄▄▄▄▄▄██\033[0m"
	@echo "\033[40;40m░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\033[0m"
	@echo "\033[46mso long + was created succesfully!\033[0m"