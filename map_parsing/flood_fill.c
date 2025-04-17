/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:19:46 by gada-sil          #+#    #+#             */
/*   Updated: 2024/12/29 19:24:31 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	count_exits(t_matrix *map)
{
	int	i;
	int	j;
	int	exits;

	i = -1;
	j = -1;
	exits = 0;
	while (++i < map->x)
	{
		while (++j < map->y)
		{
			if (map->matrix[i][j] == EXIT)
				exits++;
		}
		j = -1;
	}
	return (exits);
}

void	flood_fill(t_matrix *map, int x, int y)
{
	if (x < 0 || x >= map->x || y < 0 || y >= map->y
		|| map->matrix[x][y] == WALL
			|| map->matrix[x][y] == VISITED)
		return ;
	else if (map->matrix[x][y] == EXIT)
	{
		map->player_exits++;
		map->matrix[x][y] = VISITED;
		return ;
	}
	else if (map->matrix[x][y] == COLLECTABLE)
		map->collectables--;
	map->matrix[x][y] = VISITED;
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}
