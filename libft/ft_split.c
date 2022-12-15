/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:14:39 by mabaffo           #+#    #+#             */
/*   Updated: 2022/12/11 16:31:52 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	countstr(char *s, char c)
{
	long long int	i;
	long long int	n;

	if (!s || !(*s))
		return (0);
	n = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && (i == 0 || s[i - 1] != c))
			n++;
		i++;
	}
	if ((ft_strlen(s) >= 2) && (i == 0 || s[i - 1] != c))
		n++;
	return (n);
}

static long long int	unc(char *s, char c)
{
	long long	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	long long	i;
	long long	scount;
	long long	ct;
	char		**matrix;

	i = 0;
	ct = 0;
	scount = countstr((char *)s, c);
	matrix = (char **)malloc((scount + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	if (!s || s[0] == '\0' || c == '\0')
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
