/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 00:34:43 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/14 17:00:53 by mescobar         ###   ########.fr       */
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
int		ft_open_file(t_data *l, char *s);

		/* 	ft_parsing_file */
int 	ft_parsing_file(t_data *l);
void	ft_get_map_len(t_data *l, char *str);
void	ft_verif_f_c(t_data *l, int i);
void	ft_get_texture_variable(t_data *l, char *str);
int		ft_check_map_validity(t_data *l, char **map, int i, int *b);

		/*  ft_parsing_rgb	*/
int		ft_get_rgb(char *str, t_data *l, char letter);
void	ft_affect(t_data *l, char *str, int i, char letter);
void	ft_verify_rgb_values(t_data *l);

		/*  ft_parsing_texture	*/
int		ft_get_path(char *str, t_data *l, char *var);
char	*ft_get_file(char *str, char *var);

		/*	ft_parsing_map	*/
int		ft_get_map(t_data *l, char **str);
void	ft_alloc_map(t_data *l, char *str);
int		ft_check_ceiling(t_data *l, char *map, int i);
int		ft_check_walls(t_data *l, char **map, int c, int b);
int		ft_check_direction(t_data *l, char *map);

		/*	ft_parsing_map_spaces */
int		ft_check_spaces_proximity(t_data *l, char **str, int i);
int		ft_check_proximity(char **str, int i, size_t *j);

#endif