/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:50:36 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/26 13:20:28 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ft_dist(t_point a, t_point b, float angl)
{
	return (sqrt((b.x - a.x) * (b.x - a.x)
			+ (b.y - a.y) * (b.y - a.y)));
}

void	ft_raycasting(t_data *l)
{
	int	r;
	int	dof;

	l->ray->ra = l->player->a;
	r = 0;
	while (r < 1)
	{
		dof = 0;
		ft_vertical_ray(l);
		ft_horizontal_ray(l);
		if (l->ray->distV > l->ray->distH)
		{
			l->ray->rx = l->ray->hx;
			l->ray->ry = l->ray->hy;
		}
		else if (l->ray->distV < l->ray->distH)
		{
			l->ray->rx = l->ray->vx;
			l->ray->ry = l->ray->vy;
		}
	}
}