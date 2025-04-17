/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:01:57 by gada-sil          #+#    #+#             */
/*   Updated: 2025/02/03 13:02:54 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

bool	is_wall_left(int x, int y, t_matrix *map, t_player *player)
{
	if (!player->can_exit)
	{
		if ((map->matrix[(x + 31) / 64][(y - 2) / 64] == WALL
			|| map->matrix[x / 64][(y - 2) / 64] == WALL)
				|| (map->matrix[(x + 31) / 64][(y - 2) / 64] == EXIT
					|| map->matrix[x / 64][(y - 2) / 64] == EXIT))
			return (true);
	}
	else
	{
		if (map->matrix[(x + 31) / 64][(y - 2) / 64] == WALL
				|| map->matrix[x / 64][(y - 2) / 64] == WALL)
			return (true);
	}
	return (false);
}

bool	is_wall_right(int x, int y, t_matrix *map, t_player *player)
{
	if (!player->can_exit)
	{
		if ((map->matrix[(x + 31) / 64][(y + 32) / 64] == WALL
			|| map->matrix[x / 64][(y + 32) / 64] == WALL)
				|| (map->matrix[(x + 31) / 64][(y + 32) / 64] == EXIT
					|| map->matrix[x / 64][(y + 32) / 64] == EXIT))
			return (true);
	}
	else
	{
		if (map->matrix[(x + 31) / 64][(y + 32) / 64] == WALL
				|| map->matrix[x / 64][(y + 32) / 64] == WALL)
			return (true);
	}
	return (false);
}

bool	is_wall_up(int x, int y, t_matrix *map, t_player *player)
{
	if (!player->can_exit)
	{
		if ((map->matrix[(x - 2) / 64][(y + 30) / 64] == WALL
			|| map->matrix[(x - 2) / 64][y / 64] == WALL)
				|| (map->matrix[(x - 2) / 64][(y + 30) / 64] == EXIT
					|| map->matrix[(x - 2) / 64][y / 64] == EXIT))
			return (true);
	}
	else
	{
		if (map->matrix[(x - 2) / 64][(y + 30) / 64] == WALL
				|| map->matrix[(x - 2) / 64][y / 64] == WALL)
			return (true);
	}
	return (false);
}

bool	is_wall_down(int x, int y, t_matrix *map, t_player *player)
{
	if (!player->can_exit)
	{
		if ((map->matrix[(x + 32) / 64][y / 64] == WALL
			|| map->matrix[(x + 32) / 64][(y + 30) / 64] == WALL)
				|| (map->matrix[(x + 32) / 64][y / 64] == EXIT
					|| map->matrix[(x + 32) / 64][(y + 30) / 64] == EXIT))
			return (true);
	}
	else
	{
		if (map->matrix[(x + 32) / 64][y / 64] == WALL
				|| map->matrix[(x + 32) / 64][(y + 30) / 64] == WALL)
			return (true);
	}
	return (false);
}
