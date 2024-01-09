/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:28:19 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/08 22:08:17 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_line(t_data *l, t_rgb *color, t_point pt1, t_point pt2)
{
	int	dx;
	int	dy;

	dy = pt2.y - pt1.y;
	dx = pt2.x - pt1.x;
	while ((pt2.x - pt1.x) || (pt2.y - pt1.y))
	{
		if (pt1.x > 0 && pt1.y > 0 && pt1.x < l->mlx->win_w
			&& pt1.y < l->mlx->win_h)
			ft_put_pixel(l, color, pt1.y, pt1.x);
		pt1.x += dx;
		pt1.y += dy;
	}
}

void	ft_put_pixel(t_data *l, t_rgb *Color, int i, int j)
{
	int				pixel;
	int				color;

	pixel = (i * l->cam->line) + (j * 4);
	color = (Color->r << 16) | (Color->g << 8) | Color->b;
	l->cam->img_adr[pixel + 3] = 0 >> 24;
	l->cam->img_adr[pixel + 2] = color >> 16;
	l->cam->img_adr[pixel + 1] = color >> 8;
	l->cam->img_adr[pixel + 0] = color >> 0;
}
