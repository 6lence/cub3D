/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 00:38:23 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/16 15:35:57 by mescobar         ###   ########.fr       */
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
		return (close(l->file_fd), 1);
	line = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(1, 1024);
	if (!buffer || !line)
		return (1);
	r = 1;
	while (r)
	{
		r = read(l->file_fd, buffer, 1024);
		buffer[r] = '\0';
		line = ft_strjoin2(line, buffer);
	}
	l->file = ft_split(line, '\n');
	free(buffer);
	free(line);
	close(l->file_fd);
	return (0);
}

int	ft_verif_file(t_data *l, char *s)
{
	if (ft_open_file(l, s) || !l->file[0] || !l->file[0][0])
		return (perror("Error Opening File: "), 1);
	if (ft_parsing_file(l))
		return (1);
	return (0);
}
