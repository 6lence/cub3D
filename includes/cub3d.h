/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 00:34:43 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/16 13:08:04 by mescobar         ###   ########.fr       */
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

# include "ft_printf.h"
# include "mlx.h"
# include "cub3d_struct.h"
# include "cub3d_define.h"

		/*	main	*/
int		main(int ac, char **ag);
void	ft_initiate(t_data *l);

		/*  ft_verif_file  */
int		ft_verif_file(t_data *l, char *s);
int		ft_open_file(t_data *l, char *s);

		/* 	ft_parsing_file */
int		ft_parsing_file(t_data *l);
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
void	ft_check_direction(t_data *l, char *map);

		/*	ft_parsing_map_spaces */
int		ft_check_spaces_proximity(t_data *l, char **str, int i);
int		ft_check_proximity(char **str, int i, size_t *j);

		/*  ft_key_hook	*/
int		ft_refresh(t_data *l);
int		ft_release(int key, t_data *l);
int		ft_press(int key, t_data *l);
int		ft_key_hook(t_data *l);

		/*	ft_key_movement	*/
void	ft_movement(t_data *l);

		/*	ft_mouse  */
int		ft_mouse(int x, int y, t_data *l);

		/*	ft_turn	*/
void	ft_look_door(t_data *l);
int		ft_door(t_data *l, int i, int j);
void	ft_turn_left(t_data *l, t_ray *r);
void	ft_turn_right(t_data *l, t_ray *r);

		/*	ft_image  */
int		ft_image(t_data *l);

		/*	ft_free  */
void	ft_free(t_data *l);
		/*  ft_free_2*/
void	ft_free_cam(t_data *l);
void	ft_free_minimap(t_minimap *l);
void	ft_free_player(t_player *l);
void	ft_free_ray(t_ray *r);
void	ft_free_text_tab(t_data *l);

		/*	ft_mlx_main	*/
int		ft_mlx_part(t_data *l);
int		ft_end_prog(t_data *l);
void	ft_init_mlx_values(t_data *l);

		/*	ft_backgroud_image*/
void	ft_create_background(t_data *l);
void	ft_put_backgroud_pixel(t_data *l);

		/*	ft_put_pixel  */
void	ft_put_pixel(t_data *l, int color, int i, int j);

		/*	ft_minimap	*/
void	ft_init_minimap_values(t_data *l);
void	ft_put_minimap(t_data *l);

		/*	ft_minimap_player  */
void	ft_init_player_values(t_data *l);
void	ft_place_player(t_data *l);

		/*	ft_minimap_background  */
void	ft_minimap_background(t_data *l);

		/*	ft_minimap_walls  */
void	ft_square(t_data *l, int color);
void	ft_loop_conditions(t_data *l, int io, int jo);
void	ft_minimap_walls(t_data *l);

		/*	ft_raycasting	*/
void	ft_raycasting(t_data *l);
void	ft_init_ray(t_data *l);
void	ft_determine_direction(t_data *l);

		/*	ft_raycasting_calc	*/
void	ft_step_and_sidedist(t_ray *r);
void	ft_dda(t_data *l, t_ray *r);

		/*	ft_raycasting_main_loop	 */
void	ft_dda_init(t_ray *r);
void	ft_height(t_data *l);
void	ft_color(t_ray *r, t_data *l, int x);
void	ft_verline(t_data *l, t_ray *r, int x);
void	ft_main_loop(t_data *l, t_ray *r);

		/*	textures	*/
void	add_door_n_sprites(t_data *l, int i);
int		select_text(t_data *l);

		/*	sprites	*/
void	display_sprite(t_data *l);

		/*	ft_create_struct	*/
t_point	ft_point_st(int i, int j);
int		ft_verif_file_path(char *path);

#endif