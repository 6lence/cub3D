/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:38:04 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/09 16:14:45 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_down(t_data *l, t_ray *r)
{
	if (l->map[(int)(l->cam->py - r->dirx * MS)]
		[(int)l->cam->px] != '1')
		l->cam->py -= r->dirx * MS;
	if (l->map[(int)(l->cam->py)]
		[(int)(l->cam->px - r->diry * MS)] != '1')
		l->cam->px -= r->diry * MS;
}

void	ft_up(t_data *l, t_ray *r)
{
	if (l->map[(int)(l->cam->py + r->dirx * MS)]
		[(int)l->cam->px] != '1')
		l->cam->py += r->dirx * MS;
	if (l->map[(int)(l->cam->py)]
		[(int)(l->cam->px + r->diry * MS)] != '1')
		l->cam->px += r->diry * MS;
}

void	ft_right(t_data *l, t_ray *r)
{
	if (l->map[(int)(l->cam->py + r->dirx * MS)]
		[(int)l->cam->px] != '1')
		l->cam->py += r->diry * MS;
	if (l->map[(int)(l->cam->py)]
		[(int)(l->cam->px - r->dirx * MS)] != '1')
		l->cam->px -= r->dirx * MS;
}

void	ft_left(t_data *l, t_ray *r)
{
	if (l->map[(int)(l->cam->py - r->diry * MS)]
		[(int)l->cam->px] != '1')
		l->cam->py -= r->diry * MS;
	if (l->map[(int)(l->cam->py)]
		[(int)(l->cam->px + r->dirx * MS)] != '1')
		l->cam->px += r->dirx * MS;
}

void	ft_movement(int key, t_data *l)
{
	if (key == W || key == XK_Up)
		ft_up(l, l->ray);
	else if (key == S || key == XK_Down)
		ft_down(l, l->ray);
	else if (key == D)
		ft_right(l, l->ray);
	else if (key == A)
		ft_left(l, l->ray);
	else if (key == XK_Left || key == XK_Q || l->mlx->mleft == 1)
	{
		ft_turn_left(l->ray);
		l->mlx->mleft = 0;
	}
	else if (key == XK_Right || key == XK_E || l->mlx->mright == 1)
	{
		l->mlx->mright = 0;
		ft_turn_right(l->ray);
	}
}
