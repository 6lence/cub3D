/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:45:18 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/16 19:09:44 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_direction(t_data *l, char *map, int i)
{
	int		j;

	j = -1;
	while (map[++j])
	{
		if ((map[j] == 'N' || map[j] == 'S'
				|| map[j] == 'E' || map[j] == 'W'))
		{
			l->pars->direct_iterations++;
			l->pars->direction = map[j];
			l->pars->dir_x = i;
			l->pars->dir_y = j;
		}
	}
}

int	ft_check_walls(t_data *l, char **map, int c, int b)
{
	int	i;

	if (b > 0 && b < l->pars->map_len)
	{
		i = 0;
		while ((map[c][i] && map[c][i] == 32)
			|| (map[c][i] < 14 && map[c][i] > 6))
			i++;
		if (map[c][i] && map[c][i] != '1')
			return (1);
		i = ft_strlen(map[c]);
		while ((map[c][i] && map[c][i] == 32)
			|| (map[c][i] < 14 && map[c][i] > 6))
			i++;
		if (map[c][i - 1] && map[c][i - 1] != '1')
			return (1);
		if (ft_check_spaces_proximity(l, map, c))
			return (1);
	}
	return (0);
}

int	ft_check_ceiling(t_data *l, char *map, int i)
{
	size_t	j;

	if (i == 0 || i == l->pars->map_len - 1)
	{
		j = 0;
		while (map[j] && (map[j] == ' ' || map[j] == '1'))
			j++;
		if (j != ft_strlen(map))
			return (1);
	}
	return (0);
}

void	ft_alloc_map(t_data *l, char *str)
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
			|| (str[i] < 14 && str[i] > 6)))
		i++;
	l->map[l->pars->pos++] = ft_strdup(str);
}

int	ft_get_map(t_data *l, char **str)
{
	int	i;
	int	b;

	i = l->map_beg;
	ft_get_map_len(l);
	l->map = ft_calloc(sizeof(char *), l->pars->map_len + 1);
	while (i < l->file_end + 1)
		ft_alloc_map(l, str[i++]);
	l->map[l->pars->pos] = NULL;
	i = 0;
	b = 0;
	while (l->map[i])
	{
		if (ft_check_map_validity(l, l->map, i, &b))
			return (perror("Error: map not valid "), 1);
		i++;
	}
	if (l->pars->direct_iterations != 1)
		return (perror("Error: map not valid "), 1);
	return (0);
}
