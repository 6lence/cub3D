/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 01:18:02 by mescobar          #+#    #+#             */
/*   Updated: 2023/12/18 13:39:42 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*chain;
	size_t	len;
	size_t	i;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	chain = ft_calloc(len, sizeof(char));
	if (!chain)
		return (NULL);
	i = 0;
	tmp = s1;
	while (*s1)
		chain[i++] = *s1++;
	while (*s2)
		chain[i++] = *s2++;
	return (free(tmp), chain);
}
