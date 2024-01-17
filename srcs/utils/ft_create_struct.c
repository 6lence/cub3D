/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:39:08 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/17 15:36:56 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_bool	is_map_char(char c);

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
		return (TRUE);
	}
	return (FALSE);
}

t_bool	is_empty_line(char *line)
{
	while (*line)
	{
		if (!ft_is_whithspace(*line))
			return (FALSE);
		line ++;
	}
	return (TRUE);
}

t_bool	is_map_line(char *line)
{
	while (*line)
	{
		if (!is_map_char(*line) && *line != ' ')
			return (FALSE);
		line ++;
	}
	return (TRUE);
}

static t_bool	is_map_char(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W')
		return (TRUE);
	return (FALSE);
}
