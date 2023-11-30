/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 00:34:43 by mescobar          #+#    #+#             */
/*   Updated: 2023/11/30 01:30:01 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

		// libraries //
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

		//  libft.h //
# include "ft_printf/ft_printf.h"
		// mlx.h //
# include "../minilibx-linux/mlx.h"

typedef struct s_data
{
	int			file_fd;
	char		**map;
}				t_data;

		/*  ft_verif_file  */
int	ft_verif_file(t_data *l, char *s);

#endif