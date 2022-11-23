/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:07:03 by mabaffo           #+#    #+#             */
/*   Updated: 2022/10/10 18:16:54 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	countdig(long int n);

void	ft_putnbr_fd(int n, int fd)
{
	int		dig;
	long	num;
	char	str[11];

	if (!n)
		ft_putchar_fd(48, fd);
	else
	{
		dig = countdig(n);
		num = n;
		str[dig] = '\0';
		if (num < 0)
		{
			write(fd, "-", 1);
			num = -num;
		}
		while (num > 0)
		{
			str[--dig] = num % 10 + 48;
			num = num / 10;
		}
		ft_putstr_fd(str, fd);
	}
}
