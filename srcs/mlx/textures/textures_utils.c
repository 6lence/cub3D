/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:44:14 by qbanet            #+#    #+#             */
/*   Updated: 2024/01/14 12:10:15 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	add_sprite(t_data *l, int i, char *path);

/*============================================================================*/

void	add_door_n_sprites(t_data *l, int i)
{
	l->textures[i] = ft_calloc(1, sizeof(t_mlximg));
	l->textures[i]->img_ptr = mlx_xpm_file_to_image(l->mlx->mlx_ptr,
			"textures/porte.xpm", &(l->textures[i]->width),
			&(l->textures[i]->height));
	l->textures[i]->img_data = (int *)mlx_get_data_addr(l->textures[i]->img_ptr,
			&(l->textures[i]->bpp), &(l->textures[i]->line_size),
			&(l->textures[i]->endian));
	add_sprite(l, ++i, "textures/explosion/1.xpm");
	add_sprite(l, ++i, "textures/explosion/2.xpm");
	add_sprite(l, ++i, "textures/explosion/3.xpm");
	add_sprite(l, ++i, "textures/explosion/4.xpm");
	add_sprite(l, ++i, "textures/explosion/5.xpm");
	add_sprite(l, ++i, "textures/explosion/6.xpm");
	add_sprite(l, ++i, "textures/explosion/7.xpm");
	add_sprite(l, ++i, "textures/explosion/8.xpm");
	add_sprite(l, ++i, "textures/explosion/9.xpm");
	add_sprite(l, ++i, "textures/explosion/10.xpm");
	add_sprite(l, ++i, "textures/explosion/11.xpm");
	add_sprite(l, ++i, "textures/explosion/12.xpm");
	add_sprite(l, ++i, "textures/explosion/13.xpm");
	add_sprite(l, ++i, "textures/explosion/14.xpm");
	add_sprite(l, ++i, "textures/explosion/15.xpm");
	add_sprite(l, ++i, "textures/explosion/16.xpm");
}

static void	add_sprite(t_data *l, int i, char *path)
{
	l->textures[i] = ft_calloc(1, sizeof(t_mlximg));
	l->textures[i]->img_ptr = mlx_xpm_file_to_image(l->mlx->mlx_ptr,
			path, &(l->textures[i]->width),
			&(l->textures[i]->height));
	l->textures[i]->img_data = (int *)mlx_get_data_addr(l->textures[i]->img_ptr,
			&(l->textures[i]->bpp), &(l->textures[i]->line_size),
			&(l->textures[i]->endian));
}

int	select_text(t_data *l)
{
	if (l->ray->side == 0)
	{
		if (l->ray->raydirx < 0)
			return (NO);
		else
			return (WE);
	}
	else
	{
		if (l->ray->raydiry > 0)
			return (EA);
		else
			return (SO);
	}
	return (0);
}
