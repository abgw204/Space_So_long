/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_enemies.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:14:52 by gada-sil          #+#    #+#             */
/*   Updated: 2025/02/03 13:51:00 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main_bonus.h"

t_enemies	*create_enemy_list(t_matrix *map)
{
	t_enemies				*enemy_list;
	int						i;
	int						j;

	enemy_list = create_enemy(0, 0);
	i = -1;
	j = -1;
	while (++j < map->x - 1)
	{
		while (++i < map->y - 1)
		{
			if (map->matrix[j][i] == ENEMY)
				append_enemies(&enemy_list, create_enemy(j, i));
		}
		i = -1;
	}
	return (enemy_list);
}

static void	destroy_enemy_if(t_enemies **enemies, t_game *game)
{
	t_enemies		*temp;
	t_projectile	*projectile;

	projectile = game->projectiles;
	if (!*enemies || !enemies)
		return ;
	temp = *enemies;
	if (got_killed(projectile, *enemies))
	{
		*enemies = temp->next;
		free(temp);
		destroy_enemy_if(enemies, game);
	}
	else
	{
		temp = *enemies;
		destroy_enemy_if(&temp->next, game);
	}
}

static void	move(t_enemies *temp, t_player *player, t_game *game, t_matrix *map)
{
	int	dx;
	int	dy;
	int	max_value;

	dx = 0;
	dy = 0;
	max_value = 0;
	while (temp)
	{
		if (game->enemy_delay % 2 == 0)
		{
			dx = player->x - temp->x;
			dy = player->y - temp->y;
			max_value = max(dx, dy);
			dx = dx / max_value;
			dy = dy / max_value;
			temp->x += dx;
			temp->y += dy;
		}
		mlx_put_image_to_window(game->mlx, game->win, map->enemy,
			temp->y, temp->x);
		temp = temp->next;
	}
}

static void	kill_player(t_game *game, t_player *player, t_enemies *enemy_list)
{
	while (enemy_list)
	{
		if (player->x + 10 >= enemy_list->x - 10
			&& player->x + 10 <= enemy_list->x + 28
			&& player->y + 10 >= enemy_list->y - 10
			&& player->y + 10 <= enemy_list->y + 53)
			close_window(65307, game);
		enemy_list = enemy_list->next;
	}
}

void	move_enemy(t_enemies **enemy_list, t_game *game, t_matrix *map)
{
	t_enemies		*temp;
	t_player		*player;

	player = game->player;
	if (!*enemy_list)
		return ;
	temp = (*enemy_list)->next;
	if (temp)
	{
		kill_player(game, player, temp);
		move(temp, player, game, map);
		destroy_enemy_if(enemy_list, game);
	}
}
