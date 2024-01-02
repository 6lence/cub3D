/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_walls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:03:31 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/26 08:28:31 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_square(t_data *l, t_rgb *color)
{
	int	i;
	int	j;

	i = l->mini->mapy;
	while (i < l->mini->mapy + l->mini->mapsy - 1)
	{
		j = l->mini->mapx;
		while (j < l->mini->mapx + l->mini->mapsx - 1)
		{
			if (i < l->mini->mapyo - 2 && j < l->mini->mapxo - 2
				&& i > l->mini->mapyb && j > l->mini->mapxb)
				ft_put_pixel(l, color, i, j);
			j++;
		}
		i++;
	}
}

void	ft_loop_conditions(t_data *l, int io, int jo)
{
	if (io < l->pars->map_len && io >= 0
		&& jo < (int)ft_strlen(l->map[io]) && jo >= 0)
	{
		if (l->map[io] && l->map[io][jo] && l->map[io][jo] == '1')
			ft_square(l, l->mini->wall);
		else if (l->map[io] && l->map[io][jo] && l->map[io][jo] != ' ')
			ft_square(l, l->mini->back);
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
			ft_loop_conditions(l, io, jo);
			j++;
			l->mini->mapx += l->mini->mapsx;
		}
		l->mini->mapx -= l->mini->mapsx * (7 - (-6));
		l->mini->mapy += l->mini->mapsy;
		i++;
	}
}
