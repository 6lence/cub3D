/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:50:36 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/05 10:57:28 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_determine_direction(t_data *l)
{
	if (l->pars->direction == 'N')
	{
		l->ray->dirx = 0;
		l->ray->diry = -1;
		l->ray->planx = 0.66;
		l->ray->plany = 0;
	}
	else if (l->pars->direction == 'S')
	{
		l->ray->dirx = 0;
		l->ray->diry = 1;
		l->ray->planx = -0.66;
		l->ray->plany = 0;
	}
	else if (l->pars->direction == 'E')
	{
		l->ray->dirx = -1;
		l->ray->diry = 0;
		l->ray->planx = 0;
		l->ray->plany = -0.66;
	}
	else if (l->pars->direction == 'W')
	{
		l->ray->dirx = -1;
		l->ray->diry = 0;
		l->ray->planx = 0;
		l->ray->plany = 0.66;
	}
}

void	ft_init_ray(t_data *l)
{
	if (!l->ray)
	{
		l->ray = ft_calloc(sizeof(t_ray), 1);
		ft_determine_direction(l);
		l->ray->fov = 2 * atan(l->ray->plany / 1.0);
	}
	l->ray->posx = l->cam->px;
	l->ray->posy = l->cam->py;
	printf("posX = %f | posY = %f\n", l->ray->posx, l->ray->posy);
}

void	ft_raycasting(t_data *l)
{
	ft_init_ray(l);
	ft_main_loop(l, l->ray);
}
