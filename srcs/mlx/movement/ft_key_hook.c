/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:14:02 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/10 15:28:44 by mescobar         ###   ########.fr       */
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

int	ft_key_hook(t_data *l)
{
	if (l->esc == 1)
	{
		ft_free(l);
		exit(EXIT_SUCCESS);
		return (1);
	}
	ft_movement(l);
	return (ft_refresh(l));
}

int	ft_release(int key, t_data *l)
{
	if (key == W || key == XK_Up)
		l->dep->w = 0;
	if (key == S || key == XK_Down)
		l->dep->s = 0;
	if (key == A)
		l->dep->a = 0;
	if (key == D)
		l->dep->d = 0;
	if (key == XK_Left || key == XK_q)
		l->dep->l = 0;
	if (key == XK_Right || key == XK_e)
		l->dep->r = 0;
	return (0);
}

int	ft_press(int key, t_data *l)
{
	if (key == W || key == XK_Up)
		l->dep->w = 1;
	if (key == S || key == XK_Down)
		l->dep->s = 1;
	if (key == A)
		l->dep->a = 1;
	if (key == D)
		l->dep->d = 1;
	if (key == XK_Left || key == XK_q)
		l->dep->l = 1;
	if (key == XK_Right || key == XK_e)
		l->dep->r = 1;
	if (key == ESC)
		l->esc = 1;
	ft_key_hook(l);
	return (0);
}