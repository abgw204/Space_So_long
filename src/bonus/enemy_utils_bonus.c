/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:32:01 by gada-sil          #+#    #+#             */
/*   Updated: 2025/02/03 13:51:44 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main_bonus.h"

t_enemies	*create_enemy(int x, int y)
{
	t_enemies	*new_enemy;

	new_enemy = (t_enemies *)malloc(sizeof(t_enemies));
	if (!new_enemy)
		return (NULL);
	new_enemy->next = NULL;
	new_enemy->x = x * 64 + 18;
	new_enemy->y = y * 64 + 5;
	return (new_enemy);
}

void	append_enemies(t_enemies **enemy_list, t_enemies *new)
{
	t_enemies	*current;

	if (enemy_list == NULL || new == NULL)
		return ;
	if (*enemy_list == NULL)
	{
		*enemy_list = new;
		return ;
	}
	current = *enemy_list;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new;
}

bool	got_killed(t_projectile *projectile, t_enemies *enemies)
{
	if (!projectile)
		return (false);
	while (projectile)
	{
		if (projectile->x >= enemies->x - 5 && projectile->x <= enemies->x + 28
			&& projectile->y >= enemies->y && projectile->y <= enemies->y + 53)
			return (true);
		projectile = projectile->next;
	}
	return (false);
}
