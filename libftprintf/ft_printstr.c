/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 15:31:42 by mabaffo           #+#    #+#             */
/*   Updated: 2022/10/27 18:30:49 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printstr(char *s, size_t *pret)
{
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		*pret += 6;
	}
	else if (*s)
	{
		ft_putstr_fd(s, 1);
		(*pret) += ft_strlen(s);
	}
}
