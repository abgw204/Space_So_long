/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_collectable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:42:03 by gada-sil          #+#    #+#             */
/*   Updated: 2025/02/03 16:42:05 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main_bonus.h"

static void	if_collectable(t_game *game, t_matrix *map, int gap_y, int gap_x)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++j < map->x - 1)
	{
		while (++i < map->y)
		{
			if (map->matrix[j][i] == COLLECTABLE)
			{
				mlx_put_image_to_window(game->mlx,
					game->win, game->spaceship->astronaut, gap_y, gap_x);
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

void	draw_collectable(t_game *game, t_matrix *map)
{
	int	gap_y;
	int	gap_x;

	gap_y = 64;
	gap_x = 0;
	if_collectable(game, map, gap_y, gap_x);
}
