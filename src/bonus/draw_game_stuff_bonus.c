/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game_stuff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:14:11 by gada-sil          #+#    #+#             */
/*   Updated: 2025/02/03 13:14:12 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main_bonus.h"

static void	if_path(t_game *game, t_matrix *map, int gap_y, int gap_x)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++j < map->x - 1)
	{
		while (++i < map->y - 1)
		{
			if (map->matrix[j][i] == PATH ||
					map->matrix[j][i] == PLAYER_START ||
					map->matrix[j][i] == ENEMY)
			{
				mlx_put_image_to_window(game->mlx,
					game->win, game->ground, gap_y, gap_x);
				gap_y += 64;
			}
			else
				gap_y += 64;
		}
		gap_y = 0;
		gap_x += 64;
		i = -1;
	}
}

void	draw_path(t_game *game, t_matrix *map)
{
	int	gap_y;
	int	gap_x;

	gap_y = 0;
	gap_x = 0;
	if_path(game, map, gap_y, gap_x);
}

static void	if_wall(t_game *game, t_matrix *map, int gap_y, int gap_x)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (++j < map->x)
	{
		while (++i < map->y)
		{
			if (map->matrix[j][i] == WALL)
			{
				mlx_put_image_to_window(game->mlx,
					game->win, game->wall, gap_y, gap_x);
				gap_y += 64;
			}
			else
				gap_y += 64;
		}
		gap_y = 0;
		gap_x += 64;
		i = -1;
	}
}

void	draw_walls(t_game *game, t_matrix *map)
{
	int	gap_y;
	int	gap_x;

	gap_y = 64;
	gap_x = 0;
	if_wall(game, map, gap_y, gap_x);
}
