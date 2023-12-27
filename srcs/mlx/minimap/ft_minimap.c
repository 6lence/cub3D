/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:55:01 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/24 00:20:17 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_player_values(t_data *l)
{
	l->player = ft_calloc(1, sizeof(t_player));
	l->player->x = l->mini->mapxo \
			- ((l->mini->mapxo - l->mini->mapx) / 2);
	l->player->y = l->mini->mapyo \
			- ((l->mini->mapyo - l->mini->mapy) / 2);
	l->player->radius = 4;
	l->player->color = ft_calloc(1, sizeof(t_rgb));
	l->player->color->r = 255;
	l->player->color->g = 255;
	l->player->color->b = 0;
}

void	ft_init_minimap_values(t_data *l)
{
	l->mini = ft_calloc(1, sizeof(t_minimap));
	l->mini->mapx = l->mlx->win_w / 30;
	l->mini->mapy = l->mlx->win_h / 30;
	l->mini->mapxo = l->mlx->win_w / 40 * 10;
	l->mini->mapyo = l->mlx->win_h / 40 * 10;
	l->mini->mapxb = l->mini->mapx;
	l->mini->mapyb = l->mini->mapy;
	l->mini->mapsy = 17;
	l->mini->mapsx = 18;
	l->mini->wall = ft_calloc(1, sizeof(t_rgb));
	l->mini->wall->r = 46;
	l->mini->wall->g = 134;
	l->mini->wall->b = 193;
	l->mini->back = ft_calloc(1, sizeof(t_rgb));
	l->mini->back->r = 28;
	l->mini->back->g = 40;
	l->mini->back->b = 51;
}

void	ft_put_minimap(t_data *l)
{
	ft_init_minimap_values(l);
	ft_init_player_values(l);
	ft_minimap_background(l);
	ft_minimap_walls(l);
	ft_place_player(l);
}
