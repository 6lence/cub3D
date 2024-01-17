/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:39:08 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/17 10:45:13 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_map_char(char c);

/*============================================================================*/

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

int	is_map_line(char *line)
{
	while (*line)
	{
		if (!is_map_char(*line) && *line != ' ')
			return (0);
		line ++;
	}
	return (1);
}

static int	is_map_char(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W')
		return (1);
	return (0);
}