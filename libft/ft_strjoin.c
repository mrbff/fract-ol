/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:11:45 by mabaffo           #+#    #+#             */
/*   Updated: 2022/10/08 18:36:29 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*joint;

	i = 0;
	j = 0;
	joint = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joint)
		return (NULL);
	while (s1[i])
	{
		joint[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		joint[i] = s2[j];
		i++;
		j++;
	}
	joint[i] = '\0';
	return (joint);
}
