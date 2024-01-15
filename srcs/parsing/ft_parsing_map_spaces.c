/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map_spaces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:30:51 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/15 14:40:39 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_direction_space(char c)
{
	if (c != '1' && c != ' ')
		return (1);
	return (0);
}

int	ft_check_proximity(char **str, int i, size_t *j)
{
	if ((str[i][*j - 1]
		&& ft_direction_space(str[i][*j - 1]))
		|| (str[i][*j + 1]
		&& ft_direction_space(str[i][*j + 1]))
		|| (str[i - 1][*j]
		&& ft_direction_space(str[i - 1][*j]))
		|| (str[i + 1][*j]
		&& ft_direction_space(str[i + 1][*j])))
		return (1);
	return (0);
}

static int	ft_direction_floor(char c)
{
	if (c != ' ' && c != '1'
		&& c != '2' && c != '0'
		&& c != 'N' && c != 'W'
		&& c != 'E' && c != 'S')
		return (1);
	return (0);
}

int	ft_check_prox_floor(char **str, int i, size_t *j)
{
	if (!str[i][*j - 1] || !str[i][*j + 1]
		|| !str[i + 1][*j] || !str[i - 1][*j])
		return (1);
	if ((str[i][*j - 1]
		&& ft_direction_floor(str[i][*j - 1]))
		|| (str[i][*j + 1]
		&& ft_direction_floor(str[i][*j + 1]))
		|| (str[i - 1][*j]
		&& ft_direction_floor(str[i - 1][*j]))
		|| (str[i + 1][*j]
		&& ft_direction_floor(str[i + 1][*j])))
		return (1);
	return (0);	
}

int	ft_check_spaces_proximity(t_data *l, char **str, int i)
{
	size_t	j;

	(void)l;
	j = 0;
	while (str[i][j] && (str[i][j] == 32 || str[i][j] == '1'))
		j++;
	while (str[i][j])
	{
		if (str[i][j] == ' ')
			if (ft_check_proximity(str, i, &j))
				return (1);
		if (str[i][j] == '0' || str[i][j] == '2')
			if (ft_check_prox_floor(str, i, &j))
				return (1);
		j++;
	}
	return (0);
}
