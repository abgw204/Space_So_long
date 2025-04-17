/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:16:21 by gada-sil          #+#    #+#             */
/*   Updated: 2025/02/03 13:33:21 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main_bonus.h"

static void	which_number(t_numbers *numbers, char n, int *pos, t_game *game)
{
	if (n == '0')
		mlx_put_image_to_window(game->mlx, game->win, numbers->n0, *pos, 30);
	else if (n == '1')
		mlx_put_image_to_window(game->mlx, game->win, numbers->n1, *pos, 30);
	else if (n == '2')
		mlx_put_image_to_window(game->mlx, game->win, numbers->n2, *pos, 30);
	else if (n == '3')
		mlx_put_image_to_window(game->mlx, game->win, numbers->n3, *pos, 30);
	else if (n == '4')
		mlx_put_image_to_window(game->mlx, game->win, numbers->n4, *pos, 30);
	else if (n == '5')
		mlx_put_image_to_window(game->mlx, game->win, numbers->n5, *pos, 30);
	else if (n == '6')
		mlx_put_image_to_window(game->mlx, game->win, numbers->n6, *pos, 30);
	else if (n == '7')
		mlx_put_image_to_window(game->mlx, game->win, numbers->n7, *pos, 30);
	else if (n == '8')
		mlx_put_image_to_window(game->mlx, game->win, numbers->n8, *pos, 30);
	else if (n == '9')
		mlx_put_image_to_window(game->mlx, game->win, numbers->n9, *pos, 30);
	*pos += 9;
}

void	draw_movements(t_game *game)
{
	t_numbers		*numbers;
	t_player		*player;
	char			*str;
	int				position;
	int				i;

	numbers = game->numbers;
	player = game->player;
	str = ft_itoa(player->num_of_movements);
	position = 6;
	i = 0;
	while (str[i])
	{
		which_number(numbers, str[i], &position, game);
		i++;
	}
	free(str);
}
