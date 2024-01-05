/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_calc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:40:23 by mescobar          #+#    #+#             */
/*   Updated: 2024/01/05 13:34:06 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_step_and_sidedist(t_ray *r)
{
	if (r->raydirx < 0)
	{
		r->stepx = -1;
		r->sidedistx = (r->posx - r->mapx) * r->deltadistx;
	}
	else
	{
		r->stepx = 1;
		r->sidedistx = (r->mapx + 1.0 - r->posx) * r->deltadistx;
	}
	if (r->raydiry < 0)
	{
		r->stepy = -1;
		r->sidedisty = (r->posy - r->mapy) * r->deltadisty;
	}
	else
	{
		r->stepx = 1;
		r->sidedisty = (r->mapy + 1.0 - r->posy) * r->deltadisty;
	}
}

/*
	Digital Difference Analyzer
	algorithm used to draw lines.
*/

int	ft_not_wall(t_data *l, t_ray *r)
{
	if (l->map[(int)r->mapy][(int)r->mapx] != '0'
		&& l->map[(int)r->mapy][(int)r->mapx] != 'N'
		&& l->map[(int)r->mapy][(int)r->mapx] != 'S'
		&& l->map[(int)r->mapy][(int)r->mapx] != 'E'
		&& l->map[(int)r->mapy][(int)r->mapx] != 'O')
		return (1);
	return (0);
}

int	ft_in_map(t_data *l, t_ray *r)
{
	if ((int)r->mapy > 0 && (int)r->mapy < l->pars->map_len
		&& (int)r->mapx > 0
		&& (size_t)r->mapx < ft_strlen(l->map[(int)r->mapy])
		&& !ft_isalnum(l->map[(int)r->mapy][(int)r->mapx]))
		return (1);
	return (0);
}

int	ft_not_map(t_data *l, t_ray *r)
{
	if (!((int)r->mapy > 0 && (int)r->mapy < l->pars->map_len
		&& (int)r->mapx > 0
		&& (size_t)r->mapx < ft_strlen(l->map[(int)r->mapy])))
		return (1);
	return (0);
}

void	ft_dda(t_data *l, t_ray *r)
{
	while (!r->hit)
	{
		if (r->sidedistx < r->sidedisty)
		{
			r->sidedistx += r->deltadistx;
			r->mapx += r->stepx;
			r->side = 0;
		}
		else
		{
			r->sidedisty += r->deltadisty;
			r->mapy += r->stepy;
			r->side = 1;
		}
		if ((int)r->mapy > 0 && (int)r->mapy < l->pars->map_len
			&& (int)r->mapx > 0
			&& (size_t)r->mapx < ft_strlen(l->map[(int)r->mapy])
			&& ft_not_wall(l, r))
			r->hit = 1;
		else if (ft_in_map(l, r) || ft_not_map(l, r))
			break ;
	}
}
