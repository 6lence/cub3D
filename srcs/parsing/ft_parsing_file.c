/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:22:58 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/15 09:32:02 by mescobar         ###   ########.fr       */
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
	if (map[i][c] && (map[i][c] <= 'Z' && map[i][c] >= 'A'))
		return (0);
	if (ft_check_direction(l, map[i]))
		return (1);
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
		if ((ft_strncmp(l->file[i] + j, "F", 1)
				|| ft_strncmp(l->file[i] + j, "C", 1))
			&& l->file[i][j + 1] && l->file[i][j + 2]
			&& l->file[i][j + 1] && l->file[i][j + 1] == ' '
			&& l->file[i][j + 2] < '9' && l->file[i][j + 2] > '0')
			err = ft_get_rgb(l->file[i], l, l->file[i][j]);
		j++;
	}
	l->ft_err = err;
}

void	ft_get_map_len(t_data *l, char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] > 6 && str[i] < 14))
		i++;
	if (str[i] && (str[i] <= 'Z' && str[i] >= 'A'))
		return ;
	i = 0;
	while (str[i] && (str[i] == '1'
			|| str[i] == '0' || str[i] == 'N'
			|| str[i] == 'S' || str[i] == 'W'
			|| str[i] == 'E' || str[i] == 32
			|| str[i] == '2'
			|| (str[i] < 14 && str[i] > 6)))
		i++;
	l->pars->map_len++;
}

int	ft_parsing_file(t_data *l)
{
	int	i;
	int	b;

	l->ft_err = 0;
	l->pars->pos = 0;
	ft_verify_rgb_values(l);
	l->tex->text_path = ft_calloc(NB_TEXTURES_MUR + 1, sizeof(char *));
	i = -1;
	// while (++i < NB_TEXTURES_MUR)
	// 	l->tex->text_path[i] = ft_calloc(255, sizeof(char));
	i = 0;
	while (l->file[i])
		ft_get_map_len(l, l->file[i++]);
	i = 0;
	l->pars->direct_iterations = 0;
	b = 0;
	while (l->file[i] && !l->ft_err)
	{
		ft_verif_f_c(l, i);
		ft_get_texture_variable(l, l->file[i]);
		if (ft_check_map_validity(l, l->file, i, &b))
			return (perror("Error: map not valid "), 1);
		i++;
	}
	if (ft_get_map(l, l->file))
		return (perror("Error: malloc: map "), 1);
	return (0);
}
