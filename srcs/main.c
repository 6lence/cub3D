/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 00:35:10 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/19 17:11:51 by mescobar         ###   ########.fr       */
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
	ft_mlx_part(l);
	return (0);
}
