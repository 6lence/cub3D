/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 00:38:23 by mescobar          #+#    #+#             */
/*   Updated: 2023/11/30 01:35:36 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_open_file(t_data *l, char *s)
{
	char	*line;
	char	*buffer;
	int		r;

	l->file_fd = open(s, O_RDONLY);
	if (l->file_fd < 0 || read(l->file_fd, 0, 0))
		return (1);
	line = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(1, 1024);
	if (!buffer || !line)
		return (1);
	r = 1;
	while (r)
	{
		r = read(l->file_fd, buffer, 1024);
		buffer[r] = '\0';
		line = ft_strjoin(line, buffer);
	}
	l->map = ft_split(line, '\n');
	free(buffer);
	free(line);
	close(l->file_fd);
	return (0);
}

int	ft_parsing_map(t_data *l)
{
	int	i;

	i = 0;
	while (l->map[i])
		printf("%s\n", l->map[i++]);
	return (0);
}

int	ft_verif_file(t_data *l, char *s)
{
	if (ft_open_file(l, s) || ft_parsing_map(l))
		return (perror("fatal: "), 1);
	return (0);
}
