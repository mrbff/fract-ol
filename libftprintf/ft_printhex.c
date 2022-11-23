/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 22:25:25 by mabaffo           #+#    #+#             */
/*   Updated: 2022/10/27 18:27:31 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_toup(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isalpha(s[i]))
			(s[i]) -= 32;
		i++;
	}
}

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
		ft_toup(s);
	ft_putstr_fd(s, 1);
	free(s);
}
