/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_background.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:40:58 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/13 11:23:17 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_minimap_background(t_data *l)
{
	int	i;
	int	j;

	i = l->mini->mapy;
	while (i < l->mini->mapyo)
	{
		j = l->mini->mapx;
		while (j < l->mini->mapxo)
		{
			if (j % 2 == 0 && i % 2 == 0)
				ft_put_pixel(l, MINIMAP_BACKGROUND, i, j);
			j++;
		}
		i++;
	}
}
