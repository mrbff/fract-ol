/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:26:47 by mabaffo           #+#    #+#             */
/*   Updated: 2022/12/08 21:17:51 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*str;
	long int	num;
	int			d;

	d = ft_countdig(n);
	num = n;
	if (n < 0)
		num = -num;
	d += (n < 0);
	str = ft_calloc(d + 1, 1);
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = 48;
	while (num > 0)
	{
		str[--d] = num % 10 + 48;
		num /= 10;
	}
	return (str);
}
