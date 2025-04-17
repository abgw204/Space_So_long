/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_events.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:06:55 by gada-sil          #+#    #+#             */
/*   Updated: 2025/02/03 13:06:56 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int	handle_keypress(int keycode, t_game *game)
{
	close_window(keycode, game);
	if (keycode >= 0 && keycode <= 255)
		game->key_states[keycode] = 1;
	return (0);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	if (keycode >= 0 && keycode <= 255)
		game->key_states[keycode] = 0;
	return (0);
}
