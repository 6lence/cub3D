/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:50:19 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/09 16:19:49 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mouse(int x, int y, t_data *l)
{
	(void)y;
	printf("%d\n", l->mlx->mouse);
	if (l->mlx->mouse == 1)
	{
		mlx_mouse_hide(l->mlx->mlx_ptr, l->mlx->win_ptr);
		if (x == 0)
			return (0);
		if (x > l->mlx->win_w / 2)
			l->mlx->mleft = 1;
		if (x < l->mlx->win_w / 2)
			l->mlx->mright = 1;
		mlx_mouse_move(l->mlx->mlx_ptr, l->mlx->win_ptr,
					l->mlx->win_w / 2, l->mlx->win_h / 2);
	}
	else
		mlx_mouse_show(l->mlx->mlx_ptr, l->mlx->win_ptr);
	return (0);
}