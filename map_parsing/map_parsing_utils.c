/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:27:47 by gada-sil          #+#    #+#             */
/*   Updated: 2025/02/03 12:56:26 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static void	recriate_map(t_matrix *map, char *argv)
{
	free_map(map);
	map->matrix = create_matrix(map->x, map->y);
	init_matrix(map, argv);
}

void	is_map_valid(t_matrix *map, char *argv, t_player *player)
{
	if (!is_chars_valid(map) || !num_validation(map) || !check_errors(map))
	{
		free_map(map);
		map_error();
	}
	player->x_map = map->x - 1;
	player->y_map = map->y - 1;
	get_player_start(map, player);
	get_exit_pos(map, player);
	count_collectables(map);
	if (count_exits(map) != 1)
		count_collectables(map);
	flood_fill(map, player->x, player->y);
	if (map->player_exits != 1 || map->collectables)
	{
		free_map(map);
		map_error();
	}
	recriate_map(map, argv);
	player->flag_x = 0;
	player->flag_y = 0;
	count_collectables(map);
}

bool	valid_chars(char c)
{
	int		i;
	char	charset[6];

	i = 0;
	ft_strlcpy(charset, "01EPC", 6);
	while (charset[i])
	{
		if (c == charset[i])
			return (true);
		i++;
	}
	return (false);
}

static void	transform(char *map, t_matrix *matrix, int j)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (i < matrix->y)
	{
		matrix->matrix[j][i] = map[pos++];
		i++;
	}
	i = 0;
}

void	init_matrix(t_matrix *matrix, char *filename)
{
	int		fd;
	int		j;
	char	*line;

	fd = open(filename, O_RDONLY);
	j = 0;
	line = get_next_line(fd);
	while (line)
	{
		transform(line, matrix, j);
		j++;
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	close(fd);
}
