/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:32:13 by gada-sil          #+#    #+#             */
/*   Updated: 2025/02/03 13:32:14 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main_bonus.h"

void	free_enemies(t_enemies **enemy_list)
{
	t_enemies	*aux;

	if (!*enemy_list)
		return ;
	while (*enemy_list)
	{
		aux = (*enemy_list)->next;
		free(*enemy_list);
		*enemy_list = aux;
	}
	*enemy_list = NULL;
}

void	free_projectiles(t_projectile **projectile_list)
{
	t_projectile	*aux;

	if (!*projectile_list)
		return ;
	while (*projectile_list)
	{
		aux = (*projectile_list)->next;
		free(*projectile_list);
		*projectile_list = aux;
	}
	*projectile_list = NULL;
}
