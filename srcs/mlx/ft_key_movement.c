/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:38:04 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/03 20:43:20 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_up(t_data *l, t_ray *r)
{
	if ((int)(r->posx - r->dirx) < l->pars->map_len
		&& )
}

void	ft_movement(int key, t_data *l)
{
	if (key == W)
		ft_up(l, l->ray);
	else if (key == S)
		ft_down(l, l->ray);
	else if (key == E)
		ft_right(l, l->ray);
	else if (key == O)
		ft_left(l, l->ray);
}
