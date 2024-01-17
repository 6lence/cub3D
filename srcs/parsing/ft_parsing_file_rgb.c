/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_file_rgb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:54:06 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/17 15:39:03 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_c_f_values(t_data *l)
{
	l->tex->c->r = 119;
	l->tex->c->g = 181;
	l->tex->c->b = 254;
	l->tex->c->couleur = SKY_COLOR;
	l->tex->f->r = 244;
	l->tex->f->g = 230;
	l->tex->f->b = 125;
	l->tex->f->couleur = GROUND_COLOR;
}

static void	ft_affect_f(t_data *l, char *str, int i)
{
	l->tex->f->r = ft_atoi(str + i);
	while (str[i] && str[i] != ',')
		i++;
	i++;
	l->tex->f->g = ft_atoi(str + i);
	while (str[i] && str[i] != ',')
		i++;
	i++;
	l->tex->f->b = ft_atoi(str + i);
	l->tex->f->couleur = (l->tex->f->r << 16) | (l->tex->f->g << 8)
		| l->tex->f->b;
}

void	ft_affect(t_data *l, char *str, int i, char letter)
{
	if (letter == 'F')
		ft_affect_f(l, str, i);
	else if (letter == 'C')
	{
		l->tex->c->r = ft_atoi(str + i);
		while (str[i] && str[i] != ',')
			i++;
		i++;
		l->tex->c->g = ft_atoi(str + i);
		while (str[i] && str[i] != ',')
			i++;
		i++;
		l->tex->c->b = ft_atoi(str + i);
		l->tex->c->couleur = (l->tex->c->r << 16) | (l->tex->c->g << 8)
			| l->tex->c->b;
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
