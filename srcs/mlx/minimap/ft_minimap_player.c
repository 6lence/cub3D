/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:23:10 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/23 23:48:56 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

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
