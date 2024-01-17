/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:22:58 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/17 10:49:13 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_map_validity(t_data *l, char **map, int i, int *b)
{
	int	c;

	c = 0;
	while ((map[i][c] && map[i][c] == 32)
		|| (map[i][c] > 6 && map[i][c] < 14))
		c++;
	ft_check_direction(l, map[i], i);
	if (map[i][c] && (map[i][c] <= 'Z' && map[i][c] >= 'A'))
		return (0);
	if (ft_check_ceiling(l, map[i], *b))
		return (1);
	*b = *b + 1;
	if (ft_check_walls(l, map, i, *b))
		return (1);
	return (0);
}

void	ft_get_texture_variable(t_data *l, char *str)
{
	int	j;

	j = 0;
	while (str[j] && !l->ft_err)
	{
		if (!str + j - 1 && str + j && str + j + 1)
		{
			if (!ft_strncmp(str + j, "N", 1)
				&& (!ft_strncmp(str + j + 1, "O", 1)
					|| *str + j == ' '))
				l->ft_err = ft_get_path(str, l, "NO");
			else if (!ft_strncmp(str + j, "S", 1)
				&& (!ft_strncmp(str + j + 1, "O", 1)
					|| *str + j == ' '))
				l->ft_err = ft_get_path(str, l, "SO");
			else if (!ft_strncmp(str + j, "W", 1)
				&& (!ft_strncmp(str + j + 1, "E", 1)
					|| *str + j == ' '))
				l->ft_err = ft_get_path(str, l, "WE");
			else if (!ft_strncmp(str + j, "E", 1)
				&& (!ft_strncmp(str + j + 1, "A", 1)
					|| *str + j == ' '))
				l->ft_err = ft_get_path(str, l, "EA");
		}
		j++;
	}
}

void	ft_verif_f_c(t_data *l, int i)
{
	int	j;
	int	err;

	j = 0;
	err = 0;
	while (l->file[i][j] && !err)
	{
		if (l->file[i][j] && (l->file[i][j] == 'F'
			|| l->file[i][j] == 'C')
			&& l->file[i][j + 1] && l->file[i][j + 2]
			&& l->file[i][j + 1] && l->file[i][j + 1] == ' '
			&& l->file[i][j + 2] <= '9' && l->file[i][j + 2] >= '0')
			err = ft_get_rgb(l->file[i], l, l->file[i][j]);
		j++;
	}
	l->ft_err = err;
}

void	ft_get_map_len(t_data *l)
{
	int	j;
	int	i;

	i = l->file_end;
	while (l->file[i])
	{
		j = 0;
		while (l->file[i][j] == 32)
			j++;
		if (l->file[i][j] != '1' && !is_map_line(&(l->file[i][j + 1])))
			break ;
		i--;
	}
	l->map_beg = i;
	l->pars->map_len = l->file_end - l->map_beg;
}

int	ft_parsing_file(t_data *l)
{
	int	i;

	ft_init_c_f_values(l);
	i = 0;
	while (l->file[i] && !l->ft_err)
	{
		ft_get_texture_variable(l, l->file[i]);
		ft_verif_f_c(l, i);
		i++;
	}
	l->file_end = i - 1;
	if (l->ea > 1 || l->we > 1 || l->so > 1 || l->no > 1)
		return (perror("Too many textures"), ft_free(l), 1);
	if (ft_get_map(l, l->file))
		return (ft_free(l), 1);
	return (0);
}
