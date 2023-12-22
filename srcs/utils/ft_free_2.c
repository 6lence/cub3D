/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:46:41 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/20 10:40:28 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_cam(t_data *l)
{
	free(l->cam->walls_p);
	free(l->cam->trans_p);
	mlx_destroy_image(l->mlx->mlx_ptr, l->cam->img_ptr);
	free(l->cam);
}