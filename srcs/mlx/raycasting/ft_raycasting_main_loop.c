/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_main_loop.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:10:41 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/10 14:16:05 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_dda_init(t_ray *r)
{
	r->mapx = (int)(r->posx);
	r->mapy = (int)(r->posy);
	r->deltadistx = fabs(1 / r->raydirx);
	r->deltadisty = fabs(1 / r->raydiry);
	r->hit = 0;
}

void	ft_height(t_data *l)
{
	l->ray->line_h = (int)(l->mlx->win_h / l->ray->perpwalldist);
	l->ray->draw_start = (int)(-(l->ray->line_h) / 2 + l->mlx->win_h / 2);
	if (l->ray->draw_start < 0)
		l->ray->draw_start = 0;
	l->ray->draw_end = (int)(l->ray->line_h / 2 + l->mlx->win_h / 2);
	if (l->ray->draw_end >= l->mlx->win_h)
		l->ray->draw_end = l->mlx->win_h - 1;
}

void	ft_color(t_ray *r)
{
	if (!r->color)
		r->color = ft_calloc(1, sizeof(t_rgb));
	r->color->r = 0;
	r->color->g = 0;
	r->color->b = 0;
	if (r->side == 1 && r->raydiry < 0)
		r->color->g = 255;
	else if (r->side == 1 && r->raydiry >= 0)
		r->color->b = 255;
	if (r->side == 0 && r->raydirx < 0)
		r->color->r = 255;
	else if (r->side == 0 && r->raydirx >= 0)
	{
		r->color->r = 255;
		r->color->g = 255;
		r->color->b = 255;
	}
}

void	ft_verline(t_data *l, t_ray *r, int x)
{
	int	tmp;

	tmp = r->draw_start;
	while (tmp <= r->draw_end)
		ft_put_pixel(l, r->color, tmp++, x);
}

void	ft_main_loop(t_data *l, t_ray *r)
{
	int	x;

	x = 0;
	while (x < l->mlx->win_w)
	{
		r->camerax = 2 * x / (double)l->mlx->win_w - 1;
		r->raydirx = r->dirx + (r->planx * r->camerax);
		r->raydiry = r->diry + (r->plany * r->camerax);
		ft_dda_init(r);
		ft_step_and_sidedist(r);
		ft_dda(l, r);
		if (r->side == 0)
			r->perpwalldist = (r->sidedistx - r->deltadistx);
		else
			r->perpwalldist = (r->sidedisty - r->deltadisty);
		ft_height(l);
		ft_color(r);
		printf("%f, %f\n", r->dirx, r->diry);
		ft_verline(l, r, x);
		x++;
	}
}
