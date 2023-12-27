/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:30:08 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/24 00:21:05 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_map(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	ft_free_textures(t_tex *l)
{
	if (l->no)
		free(l->no);
	if (l->so)
		free(l->so);
	if (l->we)
		free(l->we);
	if (l->ea)
		free(l->ea);
	if (l->F)
		free(l->F);
	if (l->C)
		free(l->C);
	free(l);
}

void	ft_free_mlx(t_mlxdata *l)
{
	mlx_destroy_window(l->mlx_ptr, l->win_ptr);
	mlx_destroy_display(l->mlx_ptr);
	free(l->mlx_ptr);
	free(l);
}

void	ft_free(t_data *l)
{
	if (l)
	{
		if (l->file && l->file[0])
			ft_free_map(l->file);
		if (l->map && l->map[0])
			ft_free_map(l->map);
		if (l->cam)
			ft_free_cam(l);
		if (l->pars)
			free(l->pars);
		if (l->tex)
			ft_free_textures(l->tex);
		if (l->mini)
			ft_free_minimap(l->mini);
		if (l->player)
			ft_free_player(l->player);
		if (l->mlx)
			ft_free_mlx(l->mlx);
		free(l);
	}
}
