/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_main_loop.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:10:41 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/13 13:53:48 by qbanet           ###   ########.fr       */
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
	if (l->ray->side == 0)
		l->ray->wallx = l->ray->posy + l->ray->perpwalldist * l->ray->raydiry;
	else
		l->ray->wallx = l->ray->posx + l->ray->perpwalldist * l->ray->raydirx;
	l->ray->wallx -= floor((l->ray->wallx));
	l->ray->text_type = select_text(l);
	l->ray->text_x = (int)(l->ray->wallx * TEXTURE_SIZE);
	if (l->ray->side == 0 && l->ray->raydirx < 0)
		l->ray->text_x = TEXTURE_SIZE - l->ray->text_x - 1;
	if (l->ray->side == 1 && l->ray->raydiry > 0)
		l->ray->text_x = TEXTURE_SIZE - l->ray->text_x - 1;
}

void	ft_color(t_ray *r, t_data *l, int x)
{
	int	y;

	r += 0;
	x += 0;
	y = l->ray->draw_start;
	l->ray->step = 1.0 * TEXTURE_SIZE / l->ray->line_h;
	l->ray->texpos = (l->ray->draw_start - WIN_H / 2 + l->ray->line_h / 2)
			* l->ray->step;
	while (y < l->ray->draw_end)
	{
		l->ray->text_y = (int)l->ray->texpos & (TEXTURE_SIZE - 1);
		l->ray->texpos += l->ray->step;
		l->ray->color = l->textures[l->ray->text_type]->img_data[TEXTURE_SIZE
			* l->ray->text_y + l->ray->text_x];
		ft_put_pixel(l, l->ray->color, y, x);
		y++;
	}
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
		ft_color(r, l, x);
		x++;
	}
}
