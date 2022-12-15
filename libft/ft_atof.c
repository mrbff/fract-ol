/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:07:21 by mabaffo           #+#    #+#             */
/*   Updated: 2022/12/07 18:13:28 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(char *s)
{
	double	nb;
	double	power;
	int		sign;
	int		i;

	sign = 1;
	nb = 0.0;
	power = 1.0;
	i = 0;
	if (s[i] == '-')
		sign = -1;
	i += (s[i] == '-' || s[i] == '+');
	while (ft_isdigit(s[i]))
	{
		nb = 10.0 * nb + (s[i] - '0');
		i++;
	}
	i += (s[i] == '.');
	while (ft_isdigit(s[i]))
	{
		nb = 10.0 * nb + (s[i] - '0');
		power *= 10.0;
		i++;
	}
	return (sign * nb / power);
}
/*
double	ft_atof(const char *str)
{
	double	result;
	double	power;
	int		sign;

	result = 0.0;
	power = 1.0;
	sign = 1;
	while (*str != 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str) != 0)
		result = (result * 10) + (*str++ - '0');
	if (*str == '.')
		str++;
	while (ft_isdigit(*str) != 0)
	{
		result = (result * 10) + (*str++ - '0');
		power *= 10.0;
	}
	return (sign * result / power);
}*/
