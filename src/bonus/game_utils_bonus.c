/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:16:06 by gada-sil          #+#    #+#             */
/*   Updated: 2025/02/03 13:37:27 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main_bonus.h"

static void	destroy_even_more_images(t_game *game)
{
	t_numbers	*numbers;

	numbers = game->numbers;
	mlx_destroy_image(game->mlx, numbers->moves);
	mlx_destroy_image(game->mlx, numbers->n0);
	mlx_destroy_image(game->mlx, numbers->n1);
	mlx_destroy_image(game->mlx, numbers->n2);
	mlx_destroy_image(game->mlx, numbers->n3);
	mlx_destroy_image(game->mlx, numbers->n4);
	mlx_destroy_image(game->mlx, numbers->n5);
	mlx_destroy_image(game->mlx, numbers->n6);
	mlx_destroy_image(game->mlx, numbers->n7);
	mlx_destroy_image(game->mlx, numbers->n8);
	mlx_destroy_image(game->mlx, numbers->n9);
}

static void	destroy_more_images(t_game *game)
{
	t_spaceship	*spaceship;
	t_matrix	*map;

	spaceship = game->spaceship;
	map = game->map;
	mlx_destroy_image(game->mlx, map->enemy);
	mlx_destroy_image(game->mlx, spaceship->up);
	mlx_destroy_image(game->mlx, spaceship->left);
	mlx_destroy_image(game->mlx, spaceship->right);
	mlx_destroy_image(game->mlx, spaceship->down);
	mlx_destroy_image(game->mlx, spaceship->orb);
	mlx_destroy_image(game->mlx, spaceship->astronaut);
	destroy_even_more_images(game);
	free(game->spaceship);
	free(game->numbers);
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
	free_enemies(&game->enemies);
	free_projectiles(&game->projectiles);
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
		free_enemies(&game->enemies);
		free_projectiles(&game->projectiles);
		free_map(map);
		exit(0);
	}
	return (0);
}
