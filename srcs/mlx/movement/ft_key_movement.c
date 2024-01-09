/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:38:04 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/08 21:57:46 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_down(t_data *l, t_ray *r)
{
	if (l->map[(int)(l->cam->py - r->diry * MS)]
		[(int)l->cam->px] == '0')
		l->cam->py -= r->diry * MS;
	if (l->map[(int)(l->cam->py)]
		[(int)(l->cam->px - r->dirx * MS)] == '0')
		l->cam->px -= r->dirx * MS;
}

void	ft_up(t_data *l)
{
	(void)l;
}

void	ft_right(t_data *l)
{
	(void)l;
}

void	ft_left(t_data *l)
{
	(void)l;
}

void	ft_movement(int key, t_data *l)
{
	if (key == W || key == XK_Up)
		ft_up(l);
	else if (key == S || key == XK_Down)
		ft_down(l, l->ray);
	else if (key == D)
		ft_right(l);
	else if (key == A)
		ft_left(l);
	else if (key == XK_Left || key == XK_Q)
		ft_turn_left(l->ray);
	else if (key == XK_Right || key == XK_E)
		ft_turn_right(l->ray);
}
