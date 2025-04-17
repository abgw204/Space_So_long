/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_projectile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:15:28 by gada-sil          #+#    #+#             */
/*   Updated: 2025/02/03 13:46:00 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main_bonus.h"

static void	set_directions(t_projectile *new_projectile, t_player *player)
{
	if (player->direction == 'w')
	{
		new_projectile->x = player->x - 10;
		new_projectile->y = player->y + 12;
	}
	else if (player->direction == 'a')
	{
		new_projectile->x = player->x + 11;
		new_projectile->y = player->y - 10;
	}
	else if (player->direction == 's')
	{
		new_projectile->x = player->x + 33;
		new_projectile->y = player->y + 11;
	}
	else if (player->direction == 'd')
	{
		new_projectile->x = player->x + 11;
		new_projectile->y = player->y + 30;
	}
}

t_projectile	*create_projectile(t_player *player)
{
	t_projectile	*new_projectile;

	new_projectile = (t_projectile *)malloc(sizeof(t_projectile));
	if (!new_projectile)
		return (NULL);
	set_directions(new_projectile, player);
	new_projectile->direction = player->direction;
	new_projectile->next = NULL;
	return (new_projectile);
}

void	append_projectile(t_projectile **list, t_projectile *new)
{
	t_projectile	*current;

	if (list == NULL || new == NULL)
		return ;
	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	current = *list;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

void	destroy_projectile_if(t_projectile **projectile, t_game *game)
{
	t_matrix		*map;
	t_projectile	*temp;

	map = game->map;
	if (!*projectile || !projectile)
		return ;
	temp = *projectile;
	if (map->matrix[temp->x / 64][temp->y / 64] == WALL)
	{
		*projectile = temp->next;
		free(temp);
		destroy_projectile_if(projectile, game);
	}
	else
	{
		temp = *projectile;
		destroy_projectile_if(&temp->next, game);
	}
}

void	move_projectiles(t_projectile **projectile, t_game *game)
{
	t_projectile	*temp;
	t_spaceship		*spaceship;

	spaceship = game->spaceship;
	if (!*projectile)
		return ;
	temp = *projectile;
	while (temp)
	{
		if (temp->direction == 'w')
			mlx_put_image_to_window(game->mlx, game->win, spaceship->orb,
				temp->y, temp->x -= 2);
		else if (temp->direction == 'a')
			mlx_put_image_to_window(game->mlx, game->win, spaceship->orb,
				temp->y -= 2, temp->x);
		else if (temp->direction == 's')
			mlx_put_image_to_window(game->mlx, game->win, spaceship->orb,
				temp->y, temp->x += 2);
		else if (temp->direction == 'd')
			mlx_put_image_to_window(game->mlx, game->win, spaceship->orb,
				temp->y += 2, temp->x);
		temp = temp->next;
	}
	destroy_projectile_if(projectile, game);
}
