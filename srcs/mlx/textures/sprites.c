/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:55:31 by qbanet            #+#    #+#             */
/*   Updated: 2024/01/15 11:35:39 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_sprites	compute_img(t_data	*l);
static void	display_img(t_data *l, t_sprites *sp);

/*============================================================================*/

void	display_sprite(t_data *l)
{
	int			i;
	t_sprites	sp;

	i = 4;
	while (++i < NB_TEXTURES)
	{
		sp = compute_img(l);
		display_img(l, sp);
		usleep(50000);
	}
}

static t_sprites	compute_img(t_data	*l)
{
	t_sprites	sp;

	sp.text_x = 5 * TEXTURE_SIZE;
	sp.draw_start = 250;
	sp.step = 1.0 * TEXTURE_SIZE / 550;
	sp.texpos = sp.draw_start - WIN_H / 2 + 550 / 2;
	return (sp);
}

static void	display_img(t_data *l, t_sprites *sp)
{
	
}