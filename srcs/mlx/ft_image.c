/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:28:07 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/19 17:14:22 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_create_image(t_data *l)
{
	(void)l;
}

int	ft_image(t_data *l)
{
	l->mlx->img_ptr = mlx_new_image(l->mlx->mlx_ptr, 
						l->mlx->win_w, l->mlx->win_h);
	l->mlx->img_adr = mlx_get_data_addr(l->mlx->img_ptr,
						&l->mlx->bpp, &l->mlx->line, &l->mlx->endian);
	ft_create_image(l);
	mlx_put_image_to_window(l->mlx->mlx_ptr, l->mlx->win_ptr,
							l->mlx->img_ptr, 0, 0);
	return (0);
}