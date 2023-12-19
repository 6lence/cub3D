/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:28:19 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/19 18:17:50 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_pixel(t_data *l, t_rgb *Color, int i, int j)
{
	int 			pixel;
	unsigned int	color;

	pixel = (i * l->back->line) + (j + (l->back->bpp / 8));
	color = (Color->r << 16) | (Color->g << 8) | Color->b;
	l->back->img_adr[pixel] = color;
}
