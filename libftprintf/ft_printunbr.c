/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:05:57 by mabaffo           #+#    #+#             */
/*   Updated: 2022/10/24 01:59:14 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printunbr(unsigned int n, size_t *pret)
{
	char	*s;

	s = ft_utoa(n);
	(*pret) += ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
}
