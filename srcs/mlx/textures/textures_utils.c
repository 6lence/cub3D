/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:44:14 by qbanet            #+#    #+#             */
/*   Updated: 2024/01/16 15:29:40 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	add_all_sprites(t_data *l, int i);
static void	add_sprite(t_data *l, int i, char *path);

/*============================================================================*/

void	display_img(t_data *l, int scale, int i)
{
	t_disp_img	o;

	o.pos = 0;
	o.start_x = (l->mlx->win_h - (SPRITE_SIZE * scale)) / 2;
	o.start_y = (l->mlx->win_w - (SPRITE_SIZE * scale)) / 2;
	o.x = o.start_x;
	while (o.x++ < o.start_x + (SPRITE_SIZE * scale))
	{
		o.y = o.start_y;
		while (o.y++ < o.start_y + SPRITE_SIZE * scale)
		{
			o.k = o.x;
			while (o.k < o.x + 12)
				ft_put_pixel(l, l->textures[i]->img_data[o.pos], o.k++, o.y);
			if (o.x % scale == 0 && o.y % scale == 0)
				o.pos ++;
		}
	}
}

void	add_door_n_sprites(t_data *l, int i)
{
	if (!ft_verif_file_path(DOOR_PATH))
		return (ft_free_text_tab(l), ft_free(l),
			printf("ERROR: Texture loading fail\n"), (void) exit(EXIT_SUCCESS));
	l->textures[i] = ft_calloc(1, sizeof(t_mlximg));
	l->textures[i]->ptr = mlx_xpm_file_to_image(l->mlx->mlx_ptr,
			DOOR_PATH, &(l->textures[i]->width),
			&(l->textures[i]->height));
	l->textures[i]->img_data = (int *)mlx_get_data_addr(l->textures[i]->ptr,
			&(l->textures[i]->bpp), &(l->textures[i]->line_size),
			&(l->textures[i]->endian));
	add_all_sprites(l, i);
}

static void	add_all_sprites(t_data *l, int i)
{
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
	if (!ft_verif_file_path(path))
		return (ft_free_text_tab(l), ft_free(l),
			printf("ERROR: Texture loading fail\n"), (void) exit(EXIT_SUCCESS));
	l->textures[i] = ft_calloc(1, sizeof(t_mlximg));
	l->textures[i]->ptr = mlx_xpm_file_to_image(l->mlx->mlx_ptr,
			path, &(l->textures[i]->width),
			&(l->textures[i]->height));
	l->textures[i]->img_data = (int *)mlx_get_data_addr(l->textures[i]->ptr,
			&(l->textures[i]->bpp), &(l->textures[i]->line_size),
			&(l->textures[i]->endian));
}

int	select_text(t_data *l)
{
	if (l->ray->hit == 2)
		return (4);
	if (l->ray->side == 0)
	{
		if (l->ray->raydirx < 0 && l->ray->hit == 1)
			return (NO);
		else
			return (WE);
	}
	else if (l->ray->hit == 1)
	{
		if (l->ray->raydiry > 0)
			return (EA);
		else
			return (SO);
	}
	return (0);
}
