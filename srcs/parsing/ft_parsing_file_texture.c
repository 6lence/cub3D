/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_file_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:06:34 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/11 17:36:04 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_get_file(char *str, char *var)
{
	int		i;
	int		j;
	char	*res;

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
	res = ft_strdup(ft_substr(str, i, i + j));
	return (res);
}

int	ft_get_path(char *str, t_data *l, char *var)
{
	if (ft_strcmp("NO", var))
		l->tex->text_path[NO] = ft_get_file(str, var);
	else if (ft_strcmp("SO", var))
		l->tex->text_path[SO] = ft_get_file(str, var);
	else if (ft_strcmp("WE", var))
		l->tex->text_path[WE] = ft_get_file(str, var);
	else if (ft_strcmp("EA", var))
		l->tex->text_path[EA] = ft_get_file(str, var);
	else
		return (1);
	return (0);
}
