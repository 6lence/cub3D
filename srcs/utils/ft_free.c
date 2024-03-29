/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:30:08 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/17 15:39:03 by mescobar         ###   ########.fr       */
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
	int	i;

	i = -1;
	while (l->text_path[++i])
		free(l->text_path[i]);
	free(l->text_path);
	if (l->f)
		free(l->f);
	if (l->c)
		free(l->c);
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
		if (l->dep)
			free(l->dep);
		if (l->mini)
			ft_free_minimap(l->mini);
		if (l->player)
			ft_free_player(l->player);
		if (l->ray)
			free(l->ray);
		if (l->mlx)
			ft_free_mlx(l->mlx);
		free(l);
	}
}
