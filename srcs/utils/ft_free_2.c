/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:46:41 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/15 14:23:29 by qbanet           ###   ########.fr       */
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
	if (l->mlx && l->mlx->mlx_ptr && l->cam->img_ptr)
		mlx_destroy_image(l->mlx->mlx_ptr, l->cam->img_ptr);
	free(l->cam);
}

void	ft_free_text_tab(t_data *l)
{
	int	i;

	i = -1;
	while (++i < NB_TEXTURES)
	{
		if (l->mlx->mlx_ptr && l->textures[i] && l->textures[i]->img_ptr)
			mlx_destroy_image(l->mlx->mlx_ptr, l->textures[i]->img_ptr);
		free(l->textures[i]);
	}
	free(l->textures);
}
