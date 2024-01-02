/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:23:10 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/02 08:32:40 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	ft_init_player_values(t_data *l)
{
	if (!l->player)
	{
		l->player = ft_calloc(1, sizeof(t_player));
		l->player->color = ft_calloc(1, sizeof(t_rgb));
	}
	l->player->x = l->mini->mapxo \
			- ((l->mini->mapxo - l->mini->mapx) / 2);
	l->player->y = l->mini->mapyo \
			- ((l->mini->mapyo - l->mini->mapy) / 2);
	l->player->radius = 4;
	l->player->color->r = 255;
	l->player->color->g = 255;
	l->player->color->b = 0;
	l->player->xd = cos(l->player->a) / 2;
	l->player->yd = sin(l->player->a) / 2;
}

void	ft_place_player(t_data *l)
{
	int	x;
	int	y;

	y = l->player->y - l->player->radius;
	while (y <= l->player->y + l->player->radius)
	{
		x = l->player->x - l->player->radius;
		while (x <= l->player->x + l->player->radius)
		{
			if (pow(x - l->player->x, 2) + pow(y - l->player->y, 2)
				<= pow(l->player->radius, 2))
				ft_put_pixel(l, l->player->color, y, x);
			x++;
		}
		y++;
	}
}
