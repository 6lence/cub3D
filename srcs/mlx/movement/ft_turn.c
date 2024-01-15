/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:07:55 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/15 10:53:42 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_look_door(t_data *l)
{
	size_t	i;
	size_t	j;

	i = (size_t)l->cam->py - 1;
	while (i < (size_t)l->cam->py + 2)
	{
		j = (size_t)l->cam->px - 1;
		while (j < (size_t)l->cam->px + 2)
		{
			if (i < (size_t)l->pars->map_len
				&& j < ft_strlen(l->map[i])
				&& (i != (size_t)l->cam->py
				|| j != (size_t)l->cam->px)
				&& l->map[i][j] == '2')
				l->map[i][j] = '3';
			else if (i < (size_t)l->pars->map_len
				&& j < ft_strlen(l->map[i])
				&& (i != (size_t)l->cam->py
				|| j != (size_t)l->cam->px)
				&& l->map[i][j] == '3')
				l->map[i][j] = '2';
			j++;
		}
		i++;
	}
}

int	ft_door(t_data *l, int i, int j)
{
	if (l->map[i][j] == '2' && l->door == 1)
		return (1);
	return (0);
}

void	ft_turn_left(t_data *l, t_ray *r)
{
	double	olddirx;
	double	old_planex;

	olddirx = r->dirx;
	r->dirx = r->dirx * cos(ROT_SPEED) - r->diry * sin(ROT_SPEED);
	r->diry = olddirx * sin(ROT_SPEED) + r->diry * cos(ROT_SPEED);
	old_planex = r->planx;
	r->planx = r->planx * cos(ROT_SPEED) - r->plany * sin(ROT_SPEED);
	r->plany = old_planex * sin(ROT_SPEED) + r->plany * cos(ROT_SPEED);
	if (l->mlx->mmove)
	{
		l->mlx->mmove = 0;
		l->dep->l = 0;
	}
}

void	ft_turn_right(t_data *l, t_ray *r)
{
	double	olddirx;
	double	old_planex;

	olddirx = r->dirx;
	r->dirx = r->dirx * cos(-ROT_SPEED) - r->diry * sin(-ROT_SPEED);
	r->diry = olddirx * sin(-ROT_SPEED) + r->diry * cos(-ROT_SPEED);
	old_planex = r->planx;
	r->planx = r->planx * cos(-ROT_SPEED) - r->plany * sin(-ROT_SPEED);
	r->plany = old_planex * sin(-ROT_SPEED) + r->plany * cos(-ROT_SPEED);
	if (l->mlx->mmove)
	{
		l->mlx->mmove = 0;
		l->dep->r = 0;
	}
}
