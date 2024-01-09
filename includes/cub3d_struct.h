/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:35:31 by qbanet            #+#    #+#             */
/*   Updated: 2024/01/09 16:13:51 by mescobar         ###   ########.fr       */
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
	int		mouse;
	int		mright;
	int		mleft;
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
	double			px;
	double			py;
	int				view;
}					t_camera;

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
	float			xd;
	float			yd;
	float			a;
	int				radius;
	struct s_rgb	*color;
}					t_player;

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
	t_rgb			*color;
}			t_ray;
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
	struct s_ray			*ray;
}							t_data;

#endif