/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:14:02 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/05 10:58:23 by qbanet           ###   ########.fr       */
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
	if (key == W || key == XK_Up)
		l->cam->py -= l->player->xd;
	if (key == S || key == XK_Down)
		l->cam->py += l->player->xd;
	if (key == A)
		l->cam->px -= l->player->xd;
	if (key == D)
		l->cam->px += l->player->xd;
	ft_add_angle(key, l);
	return (ft_refresh(l));
}
