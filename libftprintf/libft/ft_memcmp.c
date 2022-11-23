/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:39:54 by mabaffo           #+#    #+#             */
/*   Updated: 2022/10/07 18:41:45 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sc1;
	unsigned char	*sc2;

	i = 0;
	sc1 = ((unsigned char *)s1);
	sc2 = ((unsigned char *)s2);
	while ((sc1[i] || sc2[i]) && i < n)
	{
		if (sc1[i] > sc2[i])
			return (1);
		else if (sc1[i] < sc2[i])
			return (-1);
		i++;
	}
	return (0);
}
