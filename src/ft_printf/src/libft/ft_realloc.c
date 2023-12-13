/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:41:44 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/12 16:03:08 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(char *pt, size_t size)
{
	char	*new_pt;
	size_t	big;

	if (!pt)
		return (malloc(size));
	if (size == 0)
		return (NULL);
	new_pt = malloc(size);
	if (!new_pt)
		return (NULL);
	big = ft_strlen(pt);
	if (size < big)
		big = size;
	ft_memcpy(new_pt, pt, big);
	free(pt);
	return (new_pt);
}
