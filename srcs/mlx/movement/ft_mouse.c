/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:50:19 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/11 10:10:38 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mouse(int x, int y, t_data *l)
{
	int	mid;

	(void)y;
	mid = l->mlx->win_w / 2;
	if (l->mlx->mouse == 1)
	{
		mlx_mouse_hide(l->mlx->mlx_ptr, l->mlx->win_ptr);
		if (x == mid)
			return (0);
		else if (x > mid)
			l->dep->r = 1;
		else if (x < mid)
			l->dep->l = 1;
		l->mlx->mmove = 1;
		mlx_mouse_move(l->mlx->mlx_ptr, l->mlx->win_ptr,
					l->mlx->win_w / 2, l->mlx->win_h / 2);
	}
	else
		mlx_mouse_show(l->mlx->mlx_ptr, l->mlx->win_ptr);
	return (0);
}