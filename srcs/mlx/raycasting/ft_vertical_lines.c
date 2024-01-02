/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vertical_lines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:54:07 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/26 13:17:22 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ra_more_than_pi(t_data *l)
{
	l->ray->rx = ((int)l->cam->px >> 6) << 6 - 0.0001;
	l->ray->ry = (l->cam->px - l->ray->rx)
					* l->ray->ntan + l->cam->py;
	l->ray->xo -= 64;
	l->ray->yo = -l->ray->xo * l->ray->ntan;
}

void	ft_ra_less_than_pi(l)
{
	l->ray->rx = ((int)l->cam->px >> 6) << 6 + 64;
	l->ray->ry = (l->cam->px - l->ray->rx)
					* l->ray->ntan + l->cam->py;
	l->ray->xo = 64;
	l->ray->yo = -l->ray->xo * l->ray->ntan;
}

void	ft_second_loop(t_data *l, int ra, int *dof)
{
	while (dof < 8)
	{
		l->ray->mx = (int)(l->ray->rx) >> 6;
		l->ray->my = (int)(l->ray->ry) << 6;
		if (my > 0 && l->map[my] 
			mx < ft_strlen(l->map[my]) && l->map[my][mx]
			&& l->map[my][mx] == '1')
		{
			l->ray->vx = l->ray->rx;
			l->ray->vy = l->ray->ry;
			l->ray->distV = ft_dist(ft_point_st(px, py),
				ft_point_st(l->ray->vx, l->ray->vy), l->ray->ra);
		}
		else
		{
			l->ray->rx = l->ray->xo;
			l->ray->ry = l->ray->yo;
			*dof += 1;
		}

	}
}

void	ft_vertical_ray(t_data *l, int *dof)
{
	l->distV = 1000000;
	l->ray->vx = l->cam->px;
	l->ray->vy = l->cam->py;
	l->ray->ntan = -tan(l->ray->ra);
	if (l->ray->ra > P2 && l->ray->ra < P3)
		ft_ra_more_than_pi(l);
	if (l->ray->ra < P2 || l->ray->ra > P3)
		ft_ra_less_than_pi(l);
	if (l->ray->ra == 0 || l->ray->ra == M_PI)
	{
		l->ray->rx = l->cam->px;
		l->ray->ry = l->cam->py;
		*dof = 8;
	}
	ft_second_loop(l, ra, dof);
}