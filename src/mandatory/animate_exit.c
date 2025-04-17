/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:00:20 by gada-sil          #+#    #+#             */
/*   Updated: 2025/02/03 13:00:21 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

void	animate_exit(t_game *game, int j, int i)
{
	if (game->anim_counter < 40)
		mlx_put_image_to_window(game->mlx, game->win, game->up, j, i);
	else if (game->anim_counter < 80)
		mlx_put_image_to_window(game->mlx, game->win, game->left_up, j, i);
	else if (game->anim_counter < 120)
		mlx_put_image_to_window(game->mlx, game->win, game->left, j, i);
	else if (game->anim_counter < 160)
		mlx_put_image_to_window(game->mlx, game->win, game->left_down, j, i);
	else if (game->anim_counter < 200)
		mlx_put_image_to_window(game->mlx, game->win, game->down, j, i);
	else if (game->anim_counter < 240)
		mlx_put_image_to_window(game->mlx, game->win, game->right_down, j, i);
	else if (game->anim_counter < 280)
		mlx_put_image_to_window(game->mlx, game->win, game->right, j, i);
	else if (game->anim_counter < 320)
		mlx_put_image_to_window(game->mlx, game->win, game->right_up, j, i);
	else if (game->anim_counter >= 320)
		game->anim_counter = 0;
}
