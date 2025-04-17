/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:00:40 by gada-sil          #+#    #+#             */
/*   Updated: 2025/02/03 13:06:36 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

static void	destroy_more_images(t_game *game)
{
	t_spaceship	*spaceship;

	spaceship = game->spaceship;
	mlx_destroy_image(game->mlx, spaceship->up);
	mlx_destroy_image(game->mlx, spaceship->left);
	mlx_destroy_image(game->mlx, spaceship->right);
	mlx_destroy_image(game->mlx, spaceship->down);
	mlx_destroy_image(game->mlx, spaceship->orb);
	mlx_destroy_image(game->mlx, spaceship->astronaut);
	free(game->spaceship);
}

static void	destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->ground);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->up);
	mlx_destroy_image(game->mlx, game->left_up);
	mlx_destroy_image(game->mlx, game->left);
	mlx_destroy_image(game->mlx, game->left_down);
	mlx_destroy_image(game->mlx, game->down);
	mlx_destroy_image(game->mlx, game->right_down);
	mlx_destroy_image(game->mlx, game->right);
	mlx_destroy_image(game->mlx, game->right_up);
	destroy_more_images(game);
}

int	close_window_x(t_game *game)
{
	t_matrix	*map;

	map = game->map;
	destroy_images(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(map);
	exit(0);
	return (0);
}

int	close_window(int key, t_game *game)
{
	t_matrix	*map;

	map = game->map;
	if (key == 65307)
	{
		destroy_images(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free_map(map);
		exit(0);
	}
	return (0);
}
