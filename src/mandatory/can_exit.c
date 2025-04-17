/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:08:15 by gada-sil          #+#    #+#             */
/*   Updated: 2025/02/03 13:08:20 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	can_exit(t_game *game, t_matrix *map, t_player *player)
{
	if (is_collectable(map, player))
	{
		map->collectables--;
		map->matrix[player->x / 64][player->y / 64] = PATH;
	}
	if (map->collectables == 0)
		player->can_exit = true;
	if (map->matrix[(player->x + 10) / 64][(player->y) / 64] == EXIT
		&& player->can_exit == true)
		close_window(65307, game);
}
