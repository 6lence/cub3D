/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 00:34:43 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/13 13:32:24 by mescobar         ###   ########.fr       */
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
# include "./ft_printf/ft_printf.h"
		// mlx.h //
# include "../minilibx-linux/mlx.h"

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}		t_rgb;


typedef struct s_tex
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	struct s_rgb	*F;
	struct s_rgb	*C;
}					t_tex;


typedef struct s_pars
{
	int			map_len;
	int			pos;
	int			direct_iterations;
	char		direction;
}		t_pars;

typedef struct s_data
{
	int					file_fd;
	int					ft_err;
	char				**file;
	char				**map;
	struct s_pars		*pars;
	struct s_tex		*tex;
}						t_data;

		/*	main	*/
void	ft_print_values(t_data *l);

		/*  ft_verif_file  */
int		ft_verif_file(t_data *l, char *s);

		/* 	ft_parsing_file */
int 	ft_parsing_file(t_data *l);

		/*  ft_parsing_rgb	*/
int		ft_get_rgb(char *str, t_data *l, char letter);
void	ft_verify_rgb_values(t_data *l);

		/*  ft_parsing_texture	*/
int		ft_get_path(char *str, t_data *l, char *var);

		/*	ft_parsing_map	*/
int		ft_get_map(t_data *l, char **str);

		/*	ft_parsing_map_spaces */
int		ft_check_spaces_proximity(t_data *l, char *str);

#endif