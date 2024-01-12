/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:28:19 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/12 11:49:11 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_pixel(t_data *l, int color, int i, int j)
{
	int				pixel;

	pixel = (i * l->cam->line) + (j * 4);
	l->cam->img_adr[pixel + 3] = 0 >> 24;
	l->cam->img_adr[pixel + 2] = color >> 16;
	l->cam->img_adr[pixel + 1] = color >> 8;
	l->cam->img_adr[pixel + 0] = color >> 0;
}
