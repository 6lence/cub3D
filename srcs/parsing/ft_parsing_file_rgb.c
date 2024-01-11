/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_file_rgb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:54:06 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/11 17:40:40 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_verify_rgb_values(t_data *l)
{
	l->tex->C->r = 128;
	l->tex->C->g = 128;
	l->tex->C->b = 128;
	l->tex->F->r = 200;
	l->tex->F->g = 200;
	l->tex->F->b = 200;
}

void	ft_affect(t_data *l, char *str, int i, char letter)
{
	if (letter == 'F')
	{
		l->tex->F->r = ft_atoi(str + i);
		while (str[i] && str[i] != ',')
			i++;
		i++;
		l->tex->F->g = ft_atoi(str + i);
		while (str[i] && str[i] != ',')
			i++;
		i++;
		l->tex->F->b = ft_atoi(str + i);
	}
	else if (letter == 'C')
	{
		l->tex->C->r = ft_atoi(str + i);
		while (str[i] && str[i] != ',')
			i++;
		i++;
		l->tex->C->g = ft_atoi(str + i + 1);
		while (str[i] && str[i] != ',')
			i++;
		i++;
		l->tex->C->b = ft_atoi(str + i + 1);
	}
}

int	ft_get_rgb(char *str, t_data *l, char letter)
{
	int	i;

	i = 0;
	while (str[i] && !(str[i] < '9' && str[i] > '0'))
		i++;
	ft_affect(l, str, i, letter);
	return (0);
}
