/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map_spaces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:30:51 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/15 12:00:33 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_proximity(char **str, int i, size_t *j)
{
	while (str[i][*j] && str[i][*j] == ' ')
	{
		if ((str[i][*j - 1]
			&& (str[i][*j - 1] != '1' && str[i][*j - 1] != ' '))
			|| (str[i][*j + 1]
			&& (str[i][*j + 1] != '1' && str[i][*j + 1] != ' '))
			|| (str[i - 1][*j]
			&& (str[i - 1][*j] != '1' && str[i - 1][*j] != ' '))
			|| (str[i + 1][*j]
			&& (str[i + 1][*j] != '1' && str[i + 1][*j] != ' ')))
			return (1);
		*j = *j + 1;
	}
	return (0);
}

int	ft_check_spaces_proximity(t_data *l, char **str, int i)
{
	size_t	j;

	(void)l;
	j = 0;
	while (str[i][j] && (str[i][j] == 32 || str[i][j] == '1'))
		j++;
	while (str[i][j] && str[i][j] != ' ')
		j++;
	if (j != ft_strlen(str[i]))
	{
		while (str[i][j])
		{
			if (str[i][j] == 32 && ft_check_proximity(str, i, &j))
				return (1);
			j++;
		}
	}
	return (0);
}
