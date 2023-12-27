/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_background.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:40:58 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/24 00:15:57 by mescobar         ###   ########.fr       */
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
				ft_put_pixel(l, l->mini->back, i, j);
			j++;
		}
		i++;
	}
}
