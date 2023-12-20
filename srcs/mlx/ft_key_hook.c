/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:14:02 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/20 08:30:00 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_hook(int	key, t_data *l)
{
	if (key == XK_Escape)
	{
		ft_free(l);
		exit(EXIT_SUCCESS);
		return (1);
	}
	return (0);
}
