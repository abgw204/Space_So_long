/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:33:44 by gada-sil          #+#    #+#             */
/*   Updated: 2025/02/03 13:33:47 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main_bonus.h"

void	load_enemy(t_game *game, t_matrix *map)
{
	int	w;
	int	h;

	map->enemy = mlx_xpm_file_to_image(game->mlx, "textures/ufo.xpm", &w, &h);
}
