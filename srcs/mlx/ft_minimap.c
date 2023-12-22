/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:55:01 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/22 10:41:39 by mescobar         ###   ########.fr       */
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
	l->mini->mapS = 7;
	l->mini->mapX = l->mlx->win_w / 10;
	l->mini->mapY =	l->mlx->win_h / 10;
	l->mini->mapXo = l->mlx->win_w * 4 / 30;
	l->mini->mapYo = l->mlx->win_h / 30;
	l->mini->none = ft_calloc(1, sizeof(t_rgb));
	l->mini->none->r = 200;
	l->mini->none->g = 200;
	l->mini->none->b = 200;
	l->mini->wall = ft_calloc(1, sizeof(t_rgb));
}

void	ft_send(t_data *l, t_rgb *color)
{
	(void)l;
	(void)color;
}

void	ft_minimap_loop(t_data *l)
{
	(void)l;
}

void	ft_put_minimap(t_data *l)
{
	ft_init_minimap_values(l);
	ft_init_player_values(l);
	ft_place_player(l);
	ft_minimap_loop(l);
}