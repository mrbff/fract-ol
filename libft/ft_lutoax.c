/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:26:47 by mabaffo           #+#    #+#             */
/*   Updated: 2022/12/08 21:01:21 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lutoax(long unsigned int n)
{
	char					*str;
	char					*sstr;
	unsigned long long		num;
	int						d;

	d = ft_lucountdig(n);
	num = n;
	str = ft_calloc(d + 1, 1);
	if (!str)
		return (str);
	if (n == 0)
		str[0] = 48;
	while (num > 0)
	{
		str[--d] = "0123456789abcdef"[num % 16];
		num /= 16;
	}
	sstr = ft_strdup(&str[d]);
	free(str);
	return (sstr);
}
