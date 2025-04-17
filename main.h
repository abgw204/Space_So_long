/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:19:34 by gada-sil          #+#    #+#             */
/*   Updated: 2024/12/29 19:42:09 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "./minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include "ft_printf/ft_printf.h"

# define WALL '1'
# define PATH '0'
# define EXIT 'E'
# define VISITED 'V'
# define COLLECTABLE 'C'
# define PLAYER_START 'P'
# define ENEMY 'X'

typedef struct gameObjects
{
	int		x;
	int		y;
	int		exit_x;
	int		exit_y;
	int		x_map;
	int		y_map;
	char	direction;
	int		flag_x;
	int		flag_y;
	int		num_of_movements;
	bool	can_exit;
}	t_player;

typedef struct gameMap
{
	char	**matrix;
	int		x;
	int		y;
	int		player_exits;
	int		collectables;
}	t_matrix;

typedef struct spaceshipImgs
{
	void	*up;
	void	*down;
	void	*left;
	void	*right;
	void	*orb;
	void	*astronaut;
}	t_spaceship;

typedef struct gameData
{
	void		*mlx;
	void		*win;
	void		*ground;
	void		*wall;
	void		*up;
	void		*right_up;
	void		*right;
	void		*right_down;
	void		*left_up;
	void		*left;
	void		*left_down;
	void		*down;
	t_player	*player;
	t_matrix	*map;
	t_spaceship	*spaceship;
	int			anim_counter;
	int			key_states[256];
}	t_game;

void		map_error(void);
int			ft_strcmp(const char *s1, const char *s2);
void		init_matrix(t_matrix *matrix, char *filename);
char		**create_matrix(int rows, int cols);
bool		valid_chars(char c);
bool		is_chars_valid(t_matrix *matrix);
bool		num_validation(t_matrix *map);
bool		check_errors(t_matrix *map);
void		free_map(t_matrix *map);
void		is_map_valid(t_matrix *map, char *argv, t_player *player);
void		get_player_start(t_matrix *map, t_player *player);
void		flood_fill(t_matrix *map, int x, int y);
void		count_collectables(t_matrix *map);
void		load_images(t_game *data);
void		init_game(t_game *game, t_matrix *map);
void		get_exit_pos(t_matrix *map, t_player *player);
int			key_structure(int key, t_game *game);
void		draw_path(t_game *game, t_matrix *map);
void		draw_walls(t_game *game, t_matrix *map);
int			close_window(int key, t_game *game);
void		draw_path(t_game *game, t_matrix *map);
void		draw_walls(t_game *game, t_matrix *map);
void		draw_collectable(t_game *game, t_matrix *map);
void		draw_astronaut(int x, int y, t_game *game);
bool		is_wall_left(int x, int y, t_matrix *map, t_player *player);
bool		is_wall_right(int x, int y, t_matrix *map, t_player *player);
bool		is_wall_up(int x, int y, t_matrix *map, t_player *player);
bool		is_wall_down(int x, int y, t_matrix *map, t_player *player);
bool		is_collectable(t_matrix *map, t_player *player);
void		malloc_game_structures(t_game *game);
void		load_spaceship(t_spaceship **spaceship, t_game *game);
char		*ft_itoa(int n);
void		draw_movements(t_game *game);
void		draw_path(t_game *game, t_matrix *map);
void		draw_walls(t_game *game, t_matrix *map);
void		draw_collectable(t_game *game, t_matrix *map);
int			handle_keypress(int keycode, t_game *game);
int			handle_keyrelease(int keycode, t_game *game);
bool		valid_chars_bonus(char c);
void		count_squares(t_player *player);
void		movement_structure(t_game *game, t_player *player, t_matrix *map);
int			count_exits(t_matrix *map);
void		animate_exit(t_game *game, int j, int i);
void		can_exit(t_game *game, t_matrix *map, t_player *player);
void		ft_strlcpy(char *dest, const char *src, size_t size);
int			close_window_x(t_game *game);
t_matrix	create_map(int argc, char *argv[]);

#endif
