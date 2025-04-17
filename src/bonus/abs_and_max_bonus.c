/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs_and_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:31:37 by gada-sil          #+#    #+#             */
/*   Updated: 2025/02/03 13:31:53 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main_bonus.h"

int	absv(int v)
{
	if (v >= 0)
		return (v);
	return (-v);
}

int	max(int dx, int dy)
{
	if (absv(dx) > absv(dy))
		return (absv(dx));
	return (absv(dy));
}
