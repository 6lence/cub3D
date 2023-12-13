/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map_spaces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:30:51 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/13 14:28:32 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_proximity(char **str, int i, int *j)
{
	while (str[i][*j] == ' ')
	{
		if (str[i][*j - 1] && str[i][*j + 1]
			&& str[i - 1][*j] && str[i + 1][*j])
		{
			if (str[i][*j - 1] != '1' || str[i][*j - 1] != ' '
				|| str[i][*j + 1] != '1' || str[i][*j + 1] != ' '
			 	|| str[i - 1][*j] != '1' || str[i - 1][*j] != ' '
				|| str[i + 1][*j] != '1' || str[i + 1][*j] != ' ')
				return (1);
		}
		*j = *j + 1;
	}
	return (0);
}

int	ft_check_spaces_proximity(t_data *l, char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (i != 0 && i != l->pars->map_len)
		{
			j = 0;
			while (str[i][j] && str[i][j] == 32 || str[i][j] == '1')
				j++;
			while (str[i][j] && str[i][j] != ' ')
				j++;
			if (j == ft_strlen(str[i]))
				continue;
			while (str[i][j])
			{
				if (str[i][j] == 32 && ft_check_proximity(str, i, &j))
					return (1);
				j++;
			}
		}
		i++;
	}
	return (0);
}