/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:51:07 by mabaffo           #+#    #+#             */
/*   Updated: 2022/12/11 02:22:00 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	long int	len;
	long int	s1len;
	long int	n1;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	n1 = 0;
	s1len = ft_strlen((char *)s1);
	while (ft_ischarofset((char *)set, ((char *)s1)[n1]))
		n1++;
	while (s1len && ft_ischarofset((char *)set, ((char *)s1)[s1len - 1]))
		s1len--;
	len = s1len - n1;
	if (len <= 0)
		return (ft_memset(malloc(1), '\0', 1));
	else
		return (ft_substr((char *)s1, n1, len));
}
