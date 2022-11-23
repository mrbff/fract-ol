/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:14:39 by mabaffo           #+#    #+#             */
/*   Updated: 2022/10/09 23:11:10 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	countstr(char *s, char c)
{
	size_t	i;
	size_t	n;

	n = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			n++;
		i++;
	}
	if (ft_strlen(s) >= 2 && s[i - 1] != c)
		n++;
	return (n);
}

size_t	unc(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	scount;
	size_t	ct;
	char	**matrix;

	i = 0;
	ct = 0;
	scount = countstr((char *)s, c);
	matrix = (char **)malloc((scount + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	if (s[0] == '\0')
		matrix[0] = NULL;
	while (ct < scount)
	{
		while (s[i] == c)
			i++;
		matrix[ct] = ft_substr((char *)s, i, unc(&((char *)s)[i], c));
		if (!matrix[ct])
			return (NULL);
		i += unc(&((char *)s)[i], c);
		ct++;
	}
	matrix[ct] = NULL;
	return (matrix);
}
