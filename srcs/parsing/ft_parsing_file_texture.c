/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_file_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:06:34 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/12 12:02:27 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_get_file(char *str, char *var)
{
	int		i;
	int		j;

	i = 0;
	while (str + i && ft_strncmp(str + i, var, ft_strlen(var)))
		i++;
	i += ft_strlen(var);
	while (str[i] && (str[i] > 6
		&& (str[i] < 14 || str[i] == 32)))
		i++;
	j = 0;
	while (str[i + j])
		j++;
	return (ft_substr(str, i, i + j));
}

int	ft_get_path(char *str, t_data *l, char *var)
{
	if (ft_strcmp("NO", var))
		l->tex->no = ft_get_file(str, var);
	else if (ft_strcmp("SO", var))
		l->tex->so = ft_get_file(str, var);
	else if (ft_strcmp("WE", var))
		l->tex->we = ft_get_file(str, var);
	else if (ft_strcmp("EA", var))
		l->tex->ea = ft_get_file(str, var);
	else
		return (1);
	return (0);
}