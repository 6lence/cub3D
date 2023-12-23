/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:55:01 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/23 21:40:27 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_player_values(t_data *l)
{
	l->player = ft_calloc(1, sizeof(t_player));
	l->player->x = l->mini->mapXo \
			- ((l->mini->mapXo - l->mini->mapX) / 2);
	l->player->y = l->mini->mapYo \
			- ((l->mini->mapYo - l->mini->mapY) / 2);
	l->player->radius = 4;
	l->player->color = ft_calloc(1, sizeof(t_rgb));
	l->player->color->r = 255;
	l->player->color->g = 255;
	l->player->color->b = 0;
}

void	ft_init_minimap_values(t_data *l)
{
	l->mini = ft_calloc(1, sizeof(t_minimap));
	l->mini->mapX = l->mlx->win_w / 30;
	l->mini->mapY =	l->mlx->win_h / 30;
	l->mini->mapXo = l->mlx->win_w / 40 * 10;
	l->mini->mapYo = l->mlx->win_h / 40 * 10;
	l->mini->mapXb = l->mini->mapX;
	l->mini->mapYb = l->mini->mapY;
	l->mini->mapS = 30;
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