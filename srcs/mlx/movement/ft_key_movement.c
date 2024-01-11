/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:38:04 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/11 10:05:57 by mescobar         ###   ########.fr       */
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
	if (l->map[(int)(l->cam->py + r->diry * MS)]
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

void	ft_movement(t_data *l)
{
	if (l->dep->w)
		ft_up(l, l->ray);
	if (l->dep->s)
		ft_down(l, l->ray);
	if (l->dep->d)
		ft_right(l, l->ray);
	if (l->dep->a)
		ft_left(l, l->ray);
	if (l->dep->l)
		ft_turn_left(l, l->ray);
	if (l->dep->r)
		ft_turn_right(l, l->ray);
}
