/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:08:27 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/20 08:14:47 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_mlx_values(t_data *l)
{
	int	i;
	int	j;

	l->mlx->win_w = 1080;
	l->mlx->win_h = 720;
	i = 0;
	while (l->map[i])
	{
		j = 0;
		while (l->map[i][j])
		{
			if (l->map[i][j] == l->pars->direction)
			{
				l->cam->py = i;
				l->cam->px = j;
				l->cam->view = l->pars->direction;
				break;
			}
			j++;
		}
		i++;
	}
}

int	ft_end_prog(t_data *l)
{
	ft_free(l);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_mlx_part(t_data *l)
{
	l->mlx = ft_calloc(sizeof(t_mlxdata), 1);
	l->cam = ft_calloc(sizeof(t_camera), 1);
	ft_init_mlx_values(l);
	l->mlx->mlx_ptr = mlx_init();
	l->mlx->win_ptr = mlx_new_window(l->mlx->mlx_ptr, l->mlx->win_w,
							l->mlx->win_h, "|-CUB3DMONGARRRRRRRS-|");
	ft_create_background(l);
	//ft_image(l);
	mlx_hook(l->mlx->win_ptr, KeyPress, KeyPressMask, ft_key_hook, l);
	mlx_hook(l->mlx->win_ptr, 17, 0L, ft_end_prog, l);
	mlx_loop(l->mlx->mlx_ptr);
	return (0);
}