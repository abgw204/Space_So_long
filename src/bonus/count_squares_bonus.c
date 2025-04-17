/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_squares.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:15:51 by gada-sil          #+#    #+#             */
/*   Updated: 2025/02/03 13:15:52 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main_bonus.h"

int	count_squares(t_player *player)
{
	int	move;

	move = player->num_of_movements;
	if ((player->x + 15) % 64 == 0 && player->flag_x == 0)
	{
		player->num_of_movements++;
		player->flag_x = 1;
	}
	if (!((player->x + 15) % 64 == 0) && player->flag_x == 1)
		player->flag_x = 0;
	if ((player->y + 15) % 64 == 0 && player->flag_y == 0)
	{
		player->num_of_movements++;
		player->flag_y = 1;
	}
	if (!((player->y + 15) % 64 == 0) && player->flag_y == 1)
		player->flag_y = 0;
	if (move != player->num_of_movements)
		return (1);
	return (0);
}
