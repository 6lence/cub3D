/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:14:02 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/09 16:23:27 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_refresh(t_data *l)
{
	if (l->cam->img_ptr)
		mlx_destroy_image(l->mlx->mlx_ptr, l->cam->img_ptr);
	ft_image(l);
	return (0);
}

void	ft_add_angle(int key, t_data *l)
{
	if (key == XK_Left)
	{
		l->player->a -= 0.1;
		if (l->player->a < 0)
			l->player->a += 2 * M_PI;
	}
	if (key == XK_Right)
	{
		l->player->a += 0.1;
		if (l->player->a > 2 * M_PI)
			l->player->a -= 2 * M_PI;
	}
}

int	ft_key_hook(int key, t_data *l)
{
	if (key == ESC)
	{
		ft_free(l);
		exit(EXIT_SUCCESS);
		return (1);
	}
	if (key == XK_M)
		l->mlx->mouse = l->mlx->mouse * (-1);
	ft_movement(key, l);
	return (ft_refresh(l));
}
