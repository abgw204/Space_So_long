/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_structure.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:00:53 by gada-sil          #+#    #+#             */
/*   Updated: 2025/02/03 13:00:54 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	movement_structure(t_game *game, t_player *player, t_matrix *map)
{
	if (game->key_states[97] && !is_wall_left(player->x,
			player->y, map, player))
	{
		player->y -= 1;
		player->direction = 'a';
	}
	else if (game->key_states[100] && !is_wall_right(player->x,
			player->y, map, player))
	{
		player->y += 1;
		player->direction = 'd';
	}
	else if (game->key_states[119] && !is_wall_up(player->x,
			player->y, map, player))
	{
		player->x -= 1;
		player->direction = 'w';
	}
	else if (game->key_states[115] && !is_wall_down(player->x,
			player->y, map, player))
	{
		player->x += 1;
		player->direction = 's';
	}
}
