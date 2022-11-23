/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:26:47 by mabaffo           #+#    #+#             */
/*   Updated: 2022/10/27 18:02:40 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ucountdig(long unsigned int n)
{
	size_t	dig;

	if (n == 0)
		return (1);
	dig = 0;
	while (n > 0)
	{
		n /= 10;
		dig++;
	}
	return (dig);
}

char	*ft_utoa(unsigned int n)
{
	char			*str;
	unsigned long	num;
	int				d;

	d = ucountdig(n);
	num = n;
	str = ft_calloc(d + 1, 1);
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = 48;
	while (num > 0)
	{
		str[--d] = num % 10 + 48;
		num /= 10;
	}
	return (str);
}
