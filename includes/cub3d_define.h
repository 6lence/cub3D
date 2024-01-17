/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_define.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:15:50 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/17 14:12:51 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DEFINE_H
# define CUB3D_DEFINE_H

# define TRUE				1
# define FALSE				0

# define WIN_NAME			"|-CUB3DMONGARRRRRRRS-|"
# define WIN_W				1080
# define WIN_H				720
# define ESC				XK_Escape
# define W					XK_w
# define A					XK_a
# define S					XK_s
# define D					XK_d
# define M_PI				3.14159265358979323846
# define MINI_P				10
# define R					4
# define ROT_SPEED 			0.02
# define MS					0.025
# define MOV				0.1
# define TEXTURE_SIZE		128
# define SPRITE_SIZE		64
# define MINIMAP_RADIUS		4.5

# define NB_TEXTURES		21
# define NB_TEXTURES_SPRITE	16
# define NB_TEXTURES_MUR	4

# define SKY_COLOR			0x9B0032
# define GROUND_COLOR		0xb68a2e

# define MINIMAP_BACKGROUND	0x555B61
# define MINIMAP_PLAYER		0x5C2B00
# define MINIMAP_WALL		0xC2B44B
# define MINIMAP_FLOOR		0x808080
# define MINIMAP_DOOR		0x8B702C
# define MINIMAP_START		0x555555

# define NO					0
# define SO					1
# define WE					2
# define EA					3

# define WALL				1
# define DOOR				2
# define DOOR_PATH			"textures/porte_3.xpm"

# define TEST				printf("___________TEST_____________\n")

#endif