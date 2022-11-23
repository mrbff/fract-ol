/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:51:07 by mabaffo           #+#    #+#             */
/*   Updated: 2022/10/08 23:37:08 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	issetchar(char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			len;
	size_t			s1len;
	unsigned int	n1;
	unsigned int	n2;

	n1 = 0;
	n2 = 0;
	s1len = ft_strlen((char *)s1) - 1;
	while (issetchar((char *)set, ((char *)s1)[n1]))
		n1++;
	while (issetchar((char *)set, ((char *)s1)[s1len]))
	{
		s1len--;
		n2++;
	}
	len = ft_strlen((char *)s1) - n1 - n2;
	return (ft_substr((char *)s1, n1, len));
}
