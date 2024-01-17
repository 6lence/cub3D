/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 00:35:10 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/17 11:19:56 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_initiate(t_data *l)
{
	l->tex = ft_calloc(sizeof(t_tex), 1);
	l->tex->F = ft_calloc(sizeof(t_rgb), 1);
	l->tex->C = ft_calloc(sizeof(t_rgb), 1);
	l->tex->text_path = ft_calloc(NB_TEXTURES_MUR + 1, sizeof(char *));
	l->pars = ft_calloc(sizeof(t_pars), 1);
	l->dep = ft_calloc(sizeof(t_dep), 1);
}

int	main(int ac, char **ag)
{
	t_data	*l;

	l = ft_calloc(sizeof(t_data), 1);
	l->door = 1;
	if (ac != 2 || !ag[1]
		|| !ft_strcmp(ag[1] + (ft_strlen(ag[1]) - 4), ".cub\0"))
		return (free(l), printf("Only one argument accepted, format: *.cub\n"));
	ft_initiate(l);
	if (ft_verif_file(l, ag[1]))
		return (1);
	ft_mlx_part(l);
	return (0);
}
