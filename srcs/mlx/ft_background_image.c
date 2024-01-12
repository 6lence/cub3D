/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_background_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:23:23 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/12 11:52:34 by qbanet           ###   ########.fr       */
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
		while (j < l->mlx->win_w)
		{
			if (i < l->mlx->win_h / 2)
				ft_put_pixel(l, 000000255, i, j);
			else
				ft_put_pixel(l, 255255000, i, j);
			j++;
		}
		i++;
	}
}