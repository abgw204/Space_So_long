/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_collectable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:21:27 by gada-sil          #+#    #+#             */
/*   Updated: 2025/02/03 13:03:18 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

bool	is_collectable(t_matrix *map, t_player *player)
{
	if (map->matrix[player->x / 64][player->y / 64] == COLLECTABLE)
		return (true);
	return (false);
}
