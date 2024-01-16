/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:08:27 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/16 18:23:44 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_text_init(t_data *l)
{
	int	i;

	i = -1;
	l->textures = ft_calloc(NB_TEXTURES, sizeof(t_mlximg *));
	while (++i < NB_TEXTURES_MUR)
	{
		if (!ft_verif_file_path(l->tex->text_path[i]))
			return (ft_free_text_tab(l), ft_free(l),
				printf("ERROR: Texture loading fail\n"),
				(void) exit(EXIT_SUCCESS));
		l->textures[i] = ft_calloc(1, sizeof(t_mlximg));
		l->textures[i]->ptr = mlx_xpm_file_to_image(l->mlx->mlx_ptr,
				l->tex->text_path[i], &(l->textures[i]->width),
				&(l->textures[i]->height));
		l->textures[i]->img_data = (int *)mlx_get_data_addr(l->textures[i]->ptr,
				&(l->textures[i]->bpp), &(l->textures[i]->line_size),
				&(l->textures[i]->endian));
	}
	add_door_n_sprites(l, i);
}

void	ft_init_mlx_values(t_data *l)
{
	int	i;
	int	j;

	l->mlx->win_w = WIN_W;
	l->mlx->win_h = WIN_H;
	i = 0;
	while (l->map[i])
	{
		j = 0;
		while (l->map[i][j])
		{
			if (l->map[i][j] == l->pars->direction)
			{
				l->cam->py = i + 0.5;
				l->cam->px = j + 0.5;
				l->cam->view = l->pars->direction;
				break ;
			}
			j++;
		}
		i++;
	}
	l->mlx->mouse = -1;
}

int	ft_end_prog(t_data *l)
{
	ft_free_text_tab(l);
	ft_free(l);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_init_image_rgb(t_data *l)
{
	l->cam->walls_p = ft_calloc(1, sizeof(t_rgb));
	l->cam->trans_p = ft_calloc(1, sizeof(t_rgb));
	l->cam->walls_p->r = 255;
	l->cam->walls_p->g = 0;
	l->cam->walls_p->b = 0;
	l->cam->walls_p->couleur = (l->cam->walls_p->r << 16)
		| (l->cam->walls_p->g << 8) | l->cam->walls_p->b;
}

int	ft_mlx_part(t_data *l)
{
	l->mlx = ft_calloc(sizeof(t_mlxdata), 1);
	l->cam = ft_calloc(sizeof(t_camera), 1);
	ft_init_mlx_values(l);
	l->mlx->mlx_ptr = mlx_init();
	l->mlx->win_ptr = mlx_new_window(l->mlx->mlx_ptr, l->mlx->win_w,
			l->mlx->win_h, WIN_NAME);
	ft_init_image_rgb(l);
	ft_text_init(l);
	ft_image(l);
	mlx_hook(l->mlx->win_ptr, 2, KeyPressMask, ft_press, l);
	mlx_hook(l->mlx->win_ptr, 3, KeyReleaseMask, ft_release, l);
	mlx_hook(l->mlx->win_ptr, 6, (1L << 6), ft_mouse, l);
	mlx_hook(l->mlx->win_ptr, 17, 0L, ft_end_prog, l);
	mlx_loop_hook(l->mlx->mlx_ptr, ft_key_hook, l);
	mlx_loop(l->mlx->mlx_ptr);
	return (0);
}
