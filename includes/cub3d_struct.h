/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:35:31 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/19 18:10:30 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

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
}				t_pars;

typedef struct s_mlxbackground
{
	void	*img_ptr;
	char	*img_adr;
	int		bpp;
	int		line;
	int		endian;
}			t_mlxbackground;

typedef struct s_mlxdata
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_h;
	int		win_w;
	void	*img_ptr;
	char	*img_adr;
	int		bpp;
	int		line;
	int		endian;
}			t_mlxdata;

typedef struct s_camera
{
	int		px;
	int		py;
	int		view;
}			t_camera;

typedef struct s_data
{
	int						file_fd;
	int						ft_err;
	char					**file;
	char					**map;
	struct s_mlxdata		*mlx;
	struct s_mlxbackground	*back;
	struct s_camera			*cam;
	struct s_pars			*pars;
	struct s_tex			*tex;
}							t_data;

#endif