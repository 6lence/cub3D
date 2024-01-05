/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_main_loop.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:10:41 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/05 10:20:04 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_dda_init(t_data *l, t_ray *r)
{
	r->mapx = (int)l->cam->px;
	r->mapy = (int)l->cam->py;
	r->deltadistx = (r->raydirx == 0) ? 1e30 : fabs(1 / r->raydirx);
	r->deltadisty = (r->raydiry == 0) ? 1e30 : fabs(1 / r->raydiry);
	r->hit = 0;
}

void	ft_height(t_data *l)
{
	l->ray->line_h = (int)(l->mlx->win_h / l->ray->perpwalldist);
	l->ray->draw_start = -l->ray->line_h / 2 + l->mlx->win_h / 2;
	if (l->ray->draw_start < 0)
		l->ray->draw_start = 0;
	l->ray->draw_end = l->ray->line_h / 2 + l->mlx->win_h / 2;
	if (l->ray->draw_end >= l->mlx->win_h)
		l->ray->draw_end = l->mlx->win_h - 1;
}

void	ft_color(t_ray *r)
{
	r->color = ft_calloc(1, sizeof(t_rgb));
	r->color->b = 255 / 3;
	if (r->side == 1)
		r->color->g = 255 / 2;
}

void	ft_verline(t_data *l, t_ray *r, int x)
{
	int	tmp;

	tmp = r->draw_start;
	while (tmp <= r->draw_end)
	{
		if (tmp < l->mlx->win_h && tmp > 0
			&& x > 0 && x < l->mlx->win_w)
			ft_put_pixel(l, r->color, tmp, x);
		tmp++;
	}
}

void	ft_main_loop(t_data *l, t_ray *r)
{
	int	x;

	x = 0;
	while (x < l->mlx->win_h)
	{
		r->camerax = 2 * x / (double)l->mlx->win_w - 1;
		r->raydirx = r->dirx + r->planx * r->camerax;
		r->raydiry = r->diry + r->plany * r->camerax;
		ft_dda_init(l, r);
		ft_step_and_sidedist(r);
		ft_dda(l, r);
		ft_height(l);
		ft_color(r);
		ft_verline(l, r, x);
		x++;
	}
}