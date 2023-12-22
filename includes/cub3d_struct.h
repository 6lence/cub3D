/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:35:31 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/22 09:55:38 by mescobar         ###   ########.fr       */
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

typedef struct s_mlxdata
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_h;
	int		win_w;
}			t_mlxdata;

typedef struct s_camera
{
	void			*img_ptr;
	char			*img_adr;
	struct s_rgb	*walls_p;
	struct s_rgb	*trans_p;
	int				bpp;
	int				line;
	int				endian;
	float			px;
	float			py;
	int				view;
}					t_camera;

typedef struct s_minimap
{
	int				mapX;
	int				mapY;
	int				mapXo;
	int				mapYo;
	int				mapS;
	struct s_rgb	*wall;
	struct s_rgb	*none;
}					t_minimap;

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_player
{
	float			x;
	float			y;
	int				radius;
	struct s_rgb	*color;
}					t_player;

typedef struct s_data
{
	int						file_fd;
	int						ft_err;
	char					**file;
	char					**map;
	struct s_mlxdata		*mlx;
	struct s_camera			*cam;
	struct s_pars			*pars;
	struct s_tex			*tex;
	struct s_minimap		*mini;
	struct s_player			*player;
}							t_data;

#endif