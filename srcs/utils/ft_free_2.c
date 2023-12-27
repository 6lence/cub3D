/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:46:41 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/24 00:21:01 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_player(t_player *l)
{
	free(l->color);
	free(l);
}

void	ft_free_minimap(t_minimap *l)
{
	free(l->wall);
	free(l->back);
	free(l);
}

void	ft_free_cam(t_data *l)
{
	free(l->cam->walls_p);
	free(l->cam->trans_p);
	mlx_destroy_image(l->mlx->mlx_ptr, l->cam->img_ptr);
	free(l->cam);
}
