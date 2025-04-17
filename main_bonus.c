/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:19:46 by gada-sil          #+#    #+#             */
/*   Updated: 2024/12/29 20:59:42 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

int	main(int argc, char *argv[])
{
	t_matrix		map;
	t_game			game;
	t_player		player;
	t_projectile	*projectiles;

	projectiles = NULL;
	map = create_map(argc, argv);
	is_map_valid(&map, argv[1], &player);
	game.player = &player;
	game.projectiles = projectiles;
	game.mlx = mlx_init();
	malloc_game_structures(&game);
	load_spaceship(&game.spaceship, &game);
	load_numbers(&game.numbers, &game);
	init_game(&game, &map);
}
