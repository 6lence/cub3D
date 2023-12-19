/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_background_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:23:23 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/19 18:34:34 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_backgroud_pixel(t_data *l)
{
	int	i;
	int	j;

	i = 0;
	while (i < l->mlx->win_h)
	{
		j = 0;
		while (j < l->mlx->win_w * 4)
		{
			if (i < l->mlx->win_h / 2)
				ft_put_pixel(l, l->tex->C, i, j);
			else
				ft_put_pixel(l, l->tex->F, i, j);
			j++;
		}
		i++;
	}
}

void	ft_create_background(t_data *l)
{
	l->back = ft_calloc(1, sizeof(t_mlxbackground));
	l->back->img_ptr = mlx_new_image(l->mlx->mlx_ptr,
					l->mlx->win_w, l->mlx->win_h);
	l->back->img_adr = mlx_get_data_addr(l->back->img_ptr,
					&l->back->bpp, &l->back->line, &l->back->endian);
	ft_put_backgroud_pixel(l);
	mlx_put_image_to_window(l->mlx->mlx_ptr, l->mlx->win_ptr,
					l->back->img_ptr, 0, 0);
}