/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:19:46 by gada-sil          #+#    #+#             */
/*   Updated: 2025/02/03 13:47:11 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main_bonus.h"

void	malloc_game_structures(t_game *game)
{
	game->spaceship = (t_spaceship *)malloc(sizeof(t_numbers));
	game->numbers = (t_numbers *)malloc(sizeof(t_numbers));
}

void	load_numbers(t_numbers **numbers, t_game *game)
{
	int	w;
	int	h;

	(*numbers)->moves = mlx_xpm_file_to_image(game->mlx,
			"textures/moves.xpm", &w, &h);
	(*numbers)->n0 = mlx_xpm_file_to_image(game->mlx, "textures/0.xpm", &w, &h);
	(*numbers)->n1 = mlx_xpm_file_to_image(game->mlx, "textures/1.xpm", &w, &h);
	(*numbers)->n2 = mlx_xpm_file_to_image(game->mlx, "textures/2.xpm", &w, &h);
	(*numbers)->n3 = mlx_xpm_file_to_image(game->mlx, "textures/3.xpm", &w, &h);
	(*numbers)->n4 = mlx_xpm_file_to_image(game->mlx, "textures/4.xpm", &w, &h);
	(*numbers)->n5 = mlx_xpm_file_to_image(game->mlx, "textures/5.xpm", &w, &h);
	(*numbers)->n6 = mlx_xpm_file_to_image(game->mlx, "textures/6.xpm", &w, &h);
	(*numbers)->n7 = mlx_xpm_file_to_image(game->mlx, "textures/7.xpm", &w, &h);
	(*numbers)->n8 = mlx_xpm_file_to_image(game->mlx, "textures/8.xpm", &w, &h);
	(*numbers)->n9 = mlx_xpm_file_to_image(game->mlx, "textures/9.xpm", &w, &h);
}

void	load_spaceship(t_spaceship **spaceship, t_game *game)
{
	int	width;
	int	height;

	(*spaceship)->up = mlx_xpm_file_to_image(game->mlx,
			"textures/spaceship_up.xpm", &width, &height);
	(*spaceship)->down = mlx_xpm_file_to_image(game->mlx,
			"textures/spaceship_down.xpm", &width, &height);
	(*spaceship)->left = mlx_xpm_file_to_image(game->mlx,
			"textures/spaceship_left.xpm", &width, &height);
	(*spaceship)->right = mlx_xpm_file_to_image(game->mlx,
			"textures/spaceship_right.xpm", &width, &height);
	(*spaceship)->orb = mlx_xpm_file_to_image(game->mlx,
			"textures/orb.xpm", &width, &height);
	(*spaceship)->astronaut = mlx_xpm_file_to_image(game->mlx,
			"textures/astronaut.xpm", &width, &height);
}

void	load_images(t_game *game)
{
	int	width;
	int	height;

	game->ground = mlx_xpm_file_to_image(game->mlx,
			"textures/background.xpm", &width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &width, &height);
	game->up = mlx_xpm_file_to_image(game->mlx,
			"textures/up.xpm", &width, &height);
	game->left_up = mlx_xpm_file_to_image(game->mlx,
			"textures/left_up.xpm", &width, &height);
	game->left = mlx_xpm_file_to_image(game->mlx,
			"textures/left.xpm", &width, &height);
	game->left_down = mlx_xpm_file_to_image(game->mlx,
			"textures/left_down.xpm", &width, &height);
	game->down = mlx_xpm_file_to_image(game->mlx,
			"textures/down.xpm", &width, &height);
	game->right_down = mlx_xpm_file_to_image(game->mlx,
			"textures/right_down.xpm", &width, &height);
	game->right = mlx_xpm_file_to_image(game->mlx,
			"textures/right.xpm", &width, &height);
	game->right_up = mlx_xpm_file_to_image(game->mlx,
			"textures/right_up.xpm", &width, &height);
}
