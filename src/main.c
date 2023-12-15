/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 00:35:10 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/15 12:25:38 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_initiate(t_data *l)
{
	
	l->tex = ft_calloc(sizeof(t_tex), 1);
	l->tex->F = ft_calloc(sizeof(t_rgb), 1);
	l->tex->C = ft_calloc(sizeof(t_rgb), 1);
	l->pars = ft_calloc(sizeof(t_pars), 1);
}

void	ft_init_mlx_values(t_data *l)
{
	l->mlx->win_w = 1920;
	l->mlx->win_h = 1080;
}

int	ft_mlx_part(t_data *l)
{
	l->mlx = ft_calloc(sizeof(t_mlxdata), 1);
	l->cam = ft_calloc(sizeof(t_camera), 1);
	ft_init_mlx_values(l);
	l->mlx->mlx_ptr = mlx_init();
	l->mlx->win_ptr = mlx_new_window(l->mlx->mlx_ptr, l->mlx->win_w,
							l->mlx->win_h, "|-CUB3DMONGARRRRRRRS-|");
}

int	main(int ac, char **ag)
{
	t_data	*l;

	l = malloc(sizeof(t_data));
	if (ac != 2 || !ag[1]
		|| !ft_strcmp(ag[1] + (ft_strlen(ag[1]) - 4), ".cub\0"))
			return (free(l), printf ("Only one argument accepted, format: *.cub\n"));
	ft_initiate(l);
	if (ft_verif_file(l, ag[1]))
		return (1);
	if (ft_mlx_part(l))
		return (1);
	return (0);
}
