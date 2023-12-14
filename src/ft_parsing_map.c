/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:45:18 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/14 17:00:55 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_direction(t_data *l, char *map)
{
	int		j;

	j = -1;
	while (map[++j])
	{
		if (map[j] == 'N' || map[j] == 'S'
			|| map[j] == 'E' || map[j] == 'W')
		{
			l->pars->direct_iterations++;
			l->pars->direction = map[j];
		}
	}
	if (l->pars->direct_iterations != 0
		&& l->pars->direct_iterations != 1)
		return (1);
	return (0);
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

	if (i == 0 || i == l->pars->map_len)
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

	i = 0;
	l->map = ft_calloc(sizeof(char *), l->pars->map_len);
	if (!l->map || !l->map[0])
		return (1);
	while (str[i])
		ft_alloc_map(l, str[i++]);
	return (0);
}