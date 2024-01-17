/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:45:18 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/17 13:46:25 by mescobar         ###   ########.fr       */
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

void	ft_alloc_map(t_data *l)
{
	int	i;

	i = l->map_beg + 1;
	while (l->file[i])
		l->map[l->pars->pos++] = ft_strdup(l->file[i++]);
}

int	ft_get_map(t_data *l)
{
	int		i;
	size_t	j;

	ft_get_map_len(l);
	l->map = ft_calloc(sizeof(char *), l->pars->map_len + 1);
	ft_alloc_map(l);
	l->map[l->pars->pos] = NULL;
	i = 0;
	while (l->map[i])
	{
		if (!is_map_line(l->map[i]))
			return (perror("Error: map not valid "), 1);
		ft_check_direction(l, l->map[i], i);
		i++;
	}
	j = l->pars->dir_y;
	if (l->pars->direct_iterations != 1
		|| ft_check_prox_floor(l->map, l->pars->dir_x, &j))
		return (perror("Error: map not valid "), 1);
	return (0);
}
