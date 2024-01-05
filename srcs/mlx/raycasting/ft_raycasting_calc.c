/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_calc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:40:23 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/05 10:22:22 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_step_and_sidedist(t_ray *r)
{
	if (r->raydirx < 0)
	{
		r->stepx = -1;
		r->sidedistx = (r->posx - r->mapx) * r->deltadistx;
	}
	else
	{
		r->stepx = 1;
		r->sidedistx = (r->mapx + 1.0 - r->posx) * r->deltadistx;
	}
	if (r->raydiry < 0)
	{
		r->stepy = -1;
		r->sidedisty = (r->posy - r->mapy) * r->deltadisty;
	}
	else
	{
		r->stepx = 1;
		r->sidedisty = (r->mapy + 1.0 - r->posy) * r->deltadisty;
	}
}

/*
	Digital Difference Analyzer
	algorithm used to draw lines.
*/

void	ft_dda(t_data *l, t_ray *r)
{
	while (!r->hit)
	{
		if (r->sidedistx < r->sidedisty)
		{
			r->sidedistx += r->deltadistx;
			r->mapx += r->stepx;
			r->side = 0;
		}
		else
		{
			r->sidedisty += r->deltadisty;
			r->mapy += r->stepy;
			r->side = 1;
		}
		if (l->map[(int)r->mapy] && l->map[(int)r->mapy][(int)r->mapx]
			&& l->map[(int)r->mapy][(int)r->mapx] != '0')
			r->hit = 1;
		else if (!ft_isalnum(l->map[(int)r->mapy][(int)r->mapx]))
			break ;
	}
	if (r->side == 0)
		r->perpwalldist = (r->sidedistx - r->deltadistx);
	else
		r->perpwalldist = (r->sidedisty - r->deltadisty);
}
