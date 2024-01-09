/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:14:02 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/08 22:16:05 by mescobar         ###   ########.fr       */
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
		if (l->map[(int)(l->cam->py - 0.2)][(int)l->cam->px] != '1')
			l->cam->py -= 0.1;
	if (key == S || key == XK_Down)
		if (l->map[(int)(l->cam->py + 0.2)][(int)l->cam->px] != '1')
			l->cam->py += 0.1;
	if (key == A)
		if (l->map[(int)l->cam->py][(int)(l->cam->px - 0.2)] != '1')
			l->cam->px -= 0.1;
	if (key == D)
		if (l->map[(int)l->cam->py][(int)(l->cam->px + 0.2)] != '1')
			l->cam->px += 0.1;
	if (key == XK_Left)
		ft_turn_right(l->ray);
	if (key == XK_Right)
		ft_turn_left(l->ray);
	return (ft_refresh(l));
}
