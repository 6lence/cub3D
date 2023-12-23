/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_walls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:03:31 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/24 00:04:45 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_square(t_data *l, t_rgb *color)
{
	int	i;
	int	j;

	i = l->mini->mapY;
	while (i < l->mini->mapY + l->mini->mapS)
	{
		j = l->mini->mapX;
		while (j < l->mini->mapX + l->mini->mapS)
		{
			if (i < l->mini->mapYo - 2 && j < l->mini->mapXo - 2
				&& i > l->mini->mapYb && j > l->mini->mapXb)
				ft_put_pixel(l, color, i, j);
			j++;
		}
		i++;
	}
}

void	ft_minimap_walls(t_data *l)
{
	int	i;
	int	j;
	int	io;
	int	jo;

	i = -4;
	while (i < 5)
	{
		j = -6;
		io = (int)l->cam->py + i;
		while (j < 7)
		{
			jo = (int)l->cam->px + j;
			if (io < l->pars->map_len && io >= 0
				&& jo < (int)ft_strlen(l->map[io]) && jo >= 0)
			{
				if (l->map[io] && l->map[io][jo] && l->map[io][jo] == '1')
					ft_square(l, l->mini->wall);
				else if (l->map[io] && l->map[io][jo] && l->map[io][jo] != ' ')
					ft_square(l, l->mini->back);
			}
			j++;
			l->mini->mapX += l->mini->mapS;
		}
		l->mini->mapX -= l->mini->mapS * (7 - (-6));
		l->mini->mapY += l->mini->mapS;
		i++;
	}
}
