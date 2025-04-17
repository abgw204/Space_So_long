/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:27:47 by gada-sil          #+#    #+#             */
/*   Updated: 2024/12/29 19:41:52 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

char	**create_matrix(int rows, int cols)
{
	char	**matrix;
	int		i;
	int		j;

	i = 0;
	j = 0;
	matrix = (char **)malloc(rows * sizeof(char *));
	if (!matrix)
	{
		free(matrix);
		map_error();
	}
	while (i < rows)
	{
		matrix[i] = (char *)malloc(cols * sizeof(char));
		if (!matrix[i])
		{
			while (j <= i)
				free(matrix[j++]);
			free(matrix);
			map_error();
		}
		i++;
	}
	return (matrix);
}

static	void	reading(int fd, char *line, t_matrix *matrix)
{
	int		columns;
	int		rows;
	int		c;

	rows = 0;
	columns = ft_strlen_no_nl(line);
	c = columns;
	while (line)
	{
		free(line);
		rows++;
		line = get_next_line(fd);
		columns = ft_strlen_no_nl(line);
		if (!line)
			break ;
		if (columns != c)
			map_error();
	}
	matrix->x = rows;
	matrix->y = c;
}

static void	read_to_count(char	*filename, t_matrix *matrix)
{
	char		*line;
	int			fd;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	reading(fd, line, matrix);
}

t_matrix	create_map(int argc, char *argv[])
{
	t_matrix	matrix;

	matrix.matrix = NULL;
	matrix.x = 1;
	matrix.y = 0;
	matrix.player_exits = 0;
	matrix.collectables = 0;
	if (argc == 2)
		read_to_count(argv[1], &matrix);
	else
		map_error();
	matrix.matrix = create_matrix(matrix.x, matrix.y);
	init_matrix(&matrix, argv[1]);
	return (matrix);
}
