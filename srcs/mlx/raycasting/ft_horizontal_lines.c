/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_horizontal_lines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 09:49:20 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/26 13:17:14 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ra_more_than_pi(t_data *l)
{
	l->ray->ry = ((int)l->cam->py >> 6) << 6 - 0.0001;
	l->ray->rx = (l->cam->py - l->ray->ry)
					* l->ray->atan + l->cam->px;
	l->ray->yo -= 64;
	l->ray->xo = -l->ray->yo * l->ray->atan;
}

void	ft_ra_less_than_pi(l)
{
	l->ray->ry = ((int)l->cam->py >> 6) << 6 + 64;
	l->ray->rx = (l->cam->py - l->ray->ry)
					* l->ray->atan + l->cam->px;
	l->ray->yo = 64;
	l->ray->xo = -l->ray->yo * l->ray->atan;
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
			l->ray->hx = l->ray->rx;
			l->ray->hy = l->ray->ry;
			l->ray->distH = ft_dist(ft_point_st(px, py),
				ft_point_st(l->ray->hx, l->ray->hy), l->ray->ra);
			*dof = 8;
		}
		else
		{
			l->ray->rx = l->ray->xo;
			l->ray->ry = l->ray->yo;
			*dof += 1;
		}

	}
}

void	ft_horizontal_ray(t_data *l, int *dof)
{
	l->ray->distH = 10000000;
	l->ray->hx = l->cam->px;
	l->ray->hy = l->cam->py;
	l->ray->atan = -1 / tan(l->ray->ra);
	if (l->ray->ra > M_PI)
		ft_ra_more_than_pi(l);
	if (l->ray->ra < M_PI)
		ft_ra_less_than_pi(l);
	if (l->ray->ra == 0 || l->ray->ra == M_PI)
	{
		l->ray->rx = l->cam->px;
		l->ray->ry = l->cam->py;
		*dof = 8;
	}
	ft_second_loop(l, ra, dof);
}