/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_background_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:23:23 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/22 10:26:01 by mescobar         ###   ########.fr       */
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
				ft_put_pixel(l, l->tex->C, i, j);
			else
				ft_put_pixel(l, l->tex->F, i, j);
			j++;
		}
		i++;
	}
}