/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_file_rgb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:54:06 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/16 15:21:11 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_c_f_values(t_data *l)
{
	l->tex->C->r = 119;
	l->tex->C->g = 181;
	l->tex->C->b = 254;
	l->tex->C->couleur = SKY_COLOR;
	l->tex->F->r = 244;
	l->tex->F->g = 230;
	l->tex->F->b = 125;
	l->tex->F->couleur = GROUND_COLOR;
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
		l->tex->F->couleur = (l->tex->F->r << 16) | (l->tex->F->g << 8)
			| l->tex->F->b;
	}
	else if (letter == 'C')
	{
		l->tex->C->r = ft_atoi(str + i);
		while (str[i] && str[i] != ',')
			i++;
		i++;
		l->tex->C->g = ft_atoi(str + i);
		while (str[i] && str[i] != ',')
			i++;
		i++;
		l->tex->C->b = ft_atoi(str + i);
		l->tex->C->couleur = (l->tex->C->r << 16) | (l->tex->C->g << 8)
			| l->tex->C->b;
	}
}

int	ft_get_rgb(char *str, t_data *l, char letter)
{
	int	i;

	i = 0;
	while (str[i] && !(str[i] <= '9' && str[i] >= '0'))
		i++;
	ft_affect(l, str, i, letter);
	return (0);
}
