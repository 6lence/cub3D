/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:07:55 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/08 21:32:48 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_turn_left(t_ray *r)
{
	double	olddirx;
	double	old_planex;

	olddirx = r->dirx;
	r->dirx = r->dirx * cos(ROT_SPEED) - r->diry * sin(ROT_SPEED);
	r->diry = olddirx * sin(ROT_SPEED) + r->diry * cos(ROT_SPEED);
	old_planex = r->planx;
	r->planx = r->planx * cos(ROT_SPEED) - r->plany * sin(ROT_SPEED);
	r->plany = old_planex * sin(ROT_SPEED) + r->plany * cos(ROT_SPEED);
}

void	ft_turn_right(t_ray *r)
{
	double	olddirx;
	double	old_planex;

	olddirx = r->dirx;
	r->dirx = r->dirx * cos(-ROT_SPEED) - r->diry * sin(-ROT_SPEED);
	r->diry = olddirx * sin(-ROT_SPEED) + r->diry * cos(-ROT_SPEED);
	old_planex = r->planx;
	r->planx = r->planx * cos(-ROT_SPEED) - r->plany * sin(-ROT_SPEED);
	r->plany = old_planex * sin(-ROT_SPEED) + r->plany * cos(-ROT_SPEED);
}
