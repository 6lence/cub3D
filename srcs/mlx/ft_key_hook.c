/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:14:02 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/22 09:09:55 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_hook(int	key, t_data *l)
{
	if (key == ESC)
	{
		ft_free(l);
		exit(EXIT_SUCCESS);
		return (1);
	}
	if (key == W)
		l->cam->py += 0.2;
	if (key == A)
		l->cam->px -= 0.2;
	if (key == S)
		l->cam->py -= 0.2;
	if (key == D)
		l->cam->px += 0.2;
	ft_image(l);
	return (0);
}
