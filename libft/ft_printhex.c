/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:25:25 by mabaffo           #+#    #+#             */
/*   Updated: 2022/12/08 23:27:30 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printhex(long unsigned int n, size_t *pret, int upc)
{
	char	*s;	

	s = ft_lutoax(n);
	if (!s)
	{
		ft_putchar_fd('0', 1);
		(*pret)++;
		return ;
	}
	(*pret) += ft_strlen(s);
	if (upc)
		ft_strtoupper(s);
	ft_putstr_fd(s, 1);
	free(s);
}
