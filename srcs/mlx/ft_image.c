/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:28:07 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/16 14:43:33 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_image(t_data *l)
{
	l->cam->img_ptr = mlx_new_image(l->mlx->mlx_ptr,
			l->mlx->win_w, l->mlx->win_h);
	l->cam->img_adr = mlx_get_data_addr(l->cam->img_ptr,
			&l->cam->bpp, &l->cam->line, &l->cam->endian);
	ft_put_backgroud_pixel(l);
	ft_raycasting(l);
	ft_put_minimap(l);
	mlx_put_image_to_window(l->mlx->mlx_ptr, l->mlx->win_ptr,
		l->cam->img_ptr, 0, 0);
	return (0);
}
