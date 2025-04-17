/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:15:42 by gada-sil          #+#    #+#             */
/*   Updated: 2025/02/03 13:15:43 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main_bonus.h"

static char	*fix_0(void)
{
	char	*str;

	str = (char *)malloc(2);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

int	int_len(int n)
{
	int	l;

	l = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}

static char	*ft_reverse(char *str, int len)
{
	int		i;
	char	temp;

	i = 0;
	len -= 1;
	while (i < len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		i++;
		len--;
	}
	return (str);
}

static void	ft_transform(char *str, int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	str[i] = '\0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	str = NULL;
	len = int_len(n);
	if (n == 0)
		return (fix_0());
	else if (n != 0)
	{
		str = (char *)malloc(len + 1);
		if (!str)
			return (NULL);
	}
	ft_transform(str, n);
	ft_reverse(str, len);
	return (str);
}
