/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lucountdig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:58:49 by mabaffo           #+#    #+#             */
/*   Updated: 2022/12/11 00:34:27 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lucountdig(long long unsigned int n)
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
