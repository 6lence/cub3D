/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 00:35:10 by mescobar          #+#    #+#             */
/*   Updated: 2023/11/30 01:30:06 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **ag)
{
	t_data	*l;

	l = malloc(sizeof(t_data));
	if (ac != 2 || !ag[1]
		|| ft_strcmp(ag[1] + (ft_strlen(ag[1]) - 4), ".cub"))
		return (printf ("Only one argument accepted, in format *.cub\n"));
	ft_verif_file(l, ag[1]);
	return (0);
}
