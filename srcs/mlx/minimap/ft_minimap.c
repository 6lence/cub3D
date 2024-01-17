/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:55:01 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/17 14:17:42 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_map_colors(t_data *l)
{
	if (!l->mini->wall)
	l->mini->wall = ft_calloc(1, sizeof(t_rgb));
	l->mini->wall->r = 46;
	l->mini->wall->g = 134;
	l->mini->wall->b = 193;
	if (!l->mini->back)
	l->mini->back = ft_calloc(1, sizeof(t_rgb));
	l->mini->back->r = 28;
	l->mini->back->g = 40;
	l->mini->back->b = 51;
}

void	ft_map_coordinates(t_data *l)
{
	if (!l->mini)
		l->mini = ft_calloc(1, sizeof(t_minimap));
	l->mini->mapx = l->mlx->win_w / 30;
	l->mini->mapy = l->mlx->win_h / 30;
	l->mini->mapxo = l->mlx->win_w / 40 * 10;
	l->mini->mapyo = l->mlx->win_h / 40 * 10;
	l->mini->mapxb = l->mini->mapx;
	l->mini->mapyb = l->mini->mapy;
	l->mini->mapsx = 18;
	l->mini->mapsy = l->mini->mapsx - 1;
}

void	ft_init_minimap_values(t_data *l)
{
	ft_map_coordinates(l);
	ft_map_colors(l);
}

void	ft_put_minimap(t_data *l)
{
	ft_init_minimap_values(l);
	ft_init_player_values(l);
	ft_minimap_background(l);
	ft_minimap_walls(l);
	ft_place_player(l);
}
