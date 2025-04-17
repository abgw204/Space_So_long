/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:15:08 by gada-sil          #+#    #+#             */
/*   Updated: 2025/02/03 13:15:09 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main_bonus.h"

int	handle_keypress(int keycode, t_game *game)
{
	t_player	*player;

	player = game->player;
	close_window(keycode, game);
	if (keycode >= 0 && keycode <= 255)
		game->key_states[keycode] = 1;
	if (game->projectile_delay >= 30 && keycode == 32)
	{
		game->projectile_delay = 0;
		if (!game->projectiles)
			game->projectiles = create_projectile(player);
		else
			append_projectile(&game->projectiles,
				create_projectile(player));
	}
	return (0);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	if (keycode >= 0 && keycode <= 255)
		game->key_states[keycode] = 0;
	return (0);
}
