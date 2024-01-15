/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:35:31 by qbanet            #+#    #+#             */
/*   Updated: 2024/01/14 12:19:04 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
	int	couleur;
}	t_rgb;


typedef struct s_tex
{
	char			**text_path;
	t_rgb			*F;
	t_rgb			*C;
}	t_tex;

typedef struct s_pars
{
	int			map_len;
	int			pos;
	int			direct_iterations;
	char		direction;
}	t_pars;

typedef struct s_mlxdata
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_h;
	int		win_w;
	int		mouse;
	int		mmove;
}	t_mlxdata;

typedef struct s_mlximg
{
	void			*img_ptr;
	int				*img_data;
	int				bpp;
	int				endian;
	int				line_size;
	int				width;
	int				height;
}	t_mlximg;

typedef struct s_camera
{
	void			*img_ptr;
	char			*img_adr;
	t_rgb			*walls_p;
	t_rgb			*trans_p;
	int				bpp;
	int				line;
	int				endian;
	double			px;
	double			py;
	int				view;
}	t_camera;

typedef struct s_minimap
{
	int				mapx;
	int				mapy;
	int				mapxb;
	int				mapyb;
	int				mapxo;
	int				mapyo;
	int				mapsx;
	int				mapsy;
	int				wall_x;
	int				wall_y;
	struct s_rgb	*wall;
	struct s_rgb	*back;
}	t_minimap;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_player
{
	float			x;
	float			y;
	float			xd;
	float			yd;
	float			a;
	int				radius;
	t_rgb			*color;
}	t_player;

typedef struct s_ray
{
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				line_h;
	int				draw_start;
	int				draw_end;
	int				text_type;
	int				text_x;
	int				text_y;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			raydirx;
	double			raydiry;
	double			planx;
	double			plany;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			fov;
	double			camerax;
	double			perpwalldist;
	double			wallx;
	double			step;
	double			texpos;
	int				color;
}	t_ray;

typedef struct s_dep
{
	int w;
	int a;
	int s;
	int d;
	int l;
	int r;
	int f;
	int	b;
}	t_dep;
typedef struct s_data
{
	int						file_fd;
	int						ft_err;
	char					**file;
	char					**map;
	int						esc;
	t_mlximg				**textures;
	struct s_mlxdata		*mlx;
	struct s_camera			*cam;
	struct s_pars			*pars;
	struct s_tex			*tex;
	struct s_minimap		*mini;
	struct s_player			*player;
	struct s_ray			*ray;
	struct s_dep			*dep;
}	t_data;

#endif