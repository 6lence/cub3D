/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:50:36 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/10 14:06:43 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_direction2(t_data *l, t_ray *r)
{
	if (l->pars->direction == 'N')
	{
		r->dirx = -1;
		r->diry = 0;
		r->planx = 0;
		r->plany = 0.66;
	}
	if (l->pars->direction == 'S')
	{
		r->dirx = 	1;
		r->diry = 0;
		r->planx = 0;
		r->plany = -0.66;
	}
}

void	ft_direction(t_data *l, t_ray *r)
{
	if (l->pars->direction == 'W')
	{
		r->dirx = 0;
		r->diry = -1;
		r->planx = -0.66;
		r->plany = 0;
	}
	if (l->pars->direction == 'E')
	{
		r->dirx = 0;
		r->diry = 1;
		r->planx = 0.66;
		r->plany = 0;
	}
	ft_direction2(l, r);
}

void	ft_init_ray(t_data *l)
{
	if (!l->ray)
	{
		l->ray = ft_calloc(sizeof(t_ray), 1);
		ft_direction(l, l->ray);
	}
	l->ray->posx = l->cam->py;
	l->ray->posy = l->cam->px;
}

void	ft_raycasting(t_data *l)
{
	ft_init_ray(l);
	ft_main_loop(l, l->ray);
}
