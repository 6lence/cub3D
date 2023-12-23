/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_background.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:40:58 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/23 12:17:47 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_minimap_background(t_data *l)
{
	int	i;
	int	j;

	i = l->mini->mapY;
	while (i < l->mini->mapYo)
	{
		j = l->mini->mapX;
		while (j < l->mini->mapXo)
		{
			if (j % 2 == 0 && i % 2 == 0)
				ft_put_pixel(l, l->mini->back, i, j);
			j++;
		}
		i++;
	}
}