/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:39:08 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/16 18:49:20 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_point	ft_point_st(int i, int j)
{
	t_point	k;

	k.x = j;
	k.y = i;
	return (k);
}

int	ft_verif_file_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		return (1);
	}
	return (0);
}
