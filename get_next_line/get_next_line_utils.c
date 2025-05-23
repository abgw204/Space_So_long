/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:53:17 by gada-sil          #+#    #+#             */
/*   Updated: 2024/10/28 18:53:19 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t num, size_t size)
{
	void			*ptr;
	size_t			total_size;
	size_t			i;
	unsigned char	*str;

	i = 0;
	if (num != 0 && (num * size) / num != size)
		return (NULL);
	total_size = num * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	str = (unsigned char *)ptr;
	while (i < total_size)
		str[i++] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s1, int c)
{
	while (*s1)
	{
		if ((unsigned char)*s1 == (unsigned char)c)
			return ((char *)s1);
		s1++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;
	size_t	i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	ptr = (char *)malloc(s1_len + s2_len + 1);
	if (!ptr)
		return (NULL);
	while (*s1)
		ptr[i++] = *s1++;
	while (*s2)
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strlen_no_nl(const char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}
