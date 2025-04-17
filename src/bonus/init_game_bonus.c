/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:19:46 by gada-sil          #+#    #+#             */
/*   Updated: 2025/02/03 13:36:22 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main_bonus.h"
#include <sys/time.h>

long    gettime(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		exit(1);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	isleep(long time)
{
	long	start;

	start = gettime() + time;
	while (gettime() < start);
}

static void	draw_scene(t_game *game)
{
	t_player	*player;
	t_spaceship	*spaceship;

	player = game->player;
	spaceship = game->spaceship;
	animate_exit(game, player->exit_y * 64, player->exit_x * 64);
	game->anim_counter++;
	if (player->direction == 'w')
		mlx_put_image_to_window(game->mlx, game->win, spaceship->up,
			player->y, player->x);
	else if (player->direction == 'a')
		mlx_put_image_to_window(game->mlx, game->win, spaceship->left,
			player->y, player->x);
	else if (player->direction == 's')
		mlx_put_image_to_window(game->mlx, game->win, spaceship->down,
			player->y, player->x);
	else if (player->direction == 'd')
		mlx_put_image_to_window(game->mlx, game->win, spaceship->right,
			player->y, player->x);
	if (game->projectile_delay < 30)
		game->projectile_delay++;
	move_projectiles(&game->projectiles, game);
}

static void	delay_scene(void)
{
	isleep(2);
}

static int	game_loop(t_game *game)
{
	t_player	*player;
	t_matrix	*map;

	player = game->player;
	map = game->map;
	game->enemy_delay++;
	delay_scene();
	movement_struct(game, player, map);
	can_exit(game, map, player);
	mlx_clear_window(game->mlx, game->win);
	mlx_put_image_to_window(game->mlx, game->win, game->numbers->moves, 0, 0);
	draw_collectable(game, map);
	draw_scene(game);
	move_enemy(&game->enemies, game, map);
	draw_walls(game, map);
	count_squares(player);
	draw_movements(game);
	return (0);
}

static void	init_map(t_game *game, t_matrix *map)
{
	int			x;
	int			y;
	t_numbers	*numbers;

	numbers = game->numbers;
	x = map->x * 64;
	y = map->y * 64;
	game->win = mlx_new_window(game->mlx, y, x, "so_long");
	game->anim_counter = 0;
	mlx_put_image_to_window(game->mlx, game->win, numbers->moves, 0, 0);
	game->enemies = create_enemy_list(map);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_hook(game->win, 17, 0, close_window_x, game);
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 3, 1L << 1, handle_keyrelease, game);
	mlx_loop(game->mlx);
}

void	init_game(t_game *game, t_matrix *map)
{
	t_player	*player;
	int			i;

	player = game->player;
	game->projectile_delay = 30;
	game->enemy_delay = 4;
	player->num_of_movements = 0;
	player->can_exit = false;
	load_enemy(game, map);
	game->map = map;
	player->x = player->x * 64 + 17;
	player->y = player->y * 64 + 20;
	player->direction = 'd';
	i = -1;
	while (++i < 256)
		game->key_states[i] = 0;
	if (!game->mlx)
	{
		free_map(map);
		map_error();
	}
	load_images(game);
	init_map(game, map);
}
