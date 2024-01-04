/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:50:36 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/03 21:36:41 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_determine_direction(t_data *l)
{
	// if (l->pars->direction == 'N')
	// {
	// 	l->ray->dirx = 0;
	// 	l->ray->diry = -1;
	// }
	// else if (l->pars->direction == 'S')
	// {
	// 	l->ray->dirx = 0;
	// 	l->ray->diry = 1;
	// }
	// else if (l->pars->direction == 'E')
	// {
	// 	l->ray->dirx = 1;
	// 	l->ray->diry = 0;
	// }
	// else
	// {
	// 	l->ray->dirx = -1;
	// 	l->ray->diry = 0;
	// }
	l->ray->dirx = -1;
	l->ray->diry = 0;
}fffffq
\




void	ft_init_ray(t_data *l)
{
	if (!l->ray)
	{
		l->ray = ft_calloc(sizeof(t_ray), 1);
		ft_determine_direction(l);
		l->ray->planx = 0;
		l->ray->plany = 0.66;
		l->ray->fov = 2 * atan(l->ray->plany / 1.0);
	}
	l->ray->posx = l->cam->py;
	l->ray->posy = l->cam->px;
}

void	ft_raycasting(t_data *l)
{
	ft_init_ray(l);
	ft_main_loop(l, l->ray);
}