/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_chars_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:27:47 by gada-sil          #+#    #+#             */
/*   Updated: 2024/12/29 19:44:29 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_bonus.h"

void	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return ;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

bool	valid_chars_bonus(char c)
{
	int		i;
	char	charset[7];

	i = 0;
	ft_strlcpy(charset, "01EPCX", 7);
	while (charset[i])
	{
		if (c == charset[i])
			return (true);
		i++;
	}
	return (false);
}
