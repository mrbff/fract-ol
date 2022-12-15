/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printargm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:07:44 by mabaffo           #+#    #+#             */
/*   Updated: 2022/12/08 21:21:16 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put37(size_t *pret)
{
	ft_putchar_fd('%', 1);
	(*pret)++;
}

static void	ft_put0x(size_t *pret)
{
	ft_putstr_fd("0x", 1);
	(*pret) += 2;
}

static void	ft_putnil(size_t *pret)
{
	ft_putstr_fd("(nil)", 1);
	*pret += 5;
}

static void	ft_putc(va_list *pargm, size_t *pret)
{
	ft_putchar_fd(va_arg(*pargm, int), 1);
	(*pret)++;
}

void	ft_printargm(char spec, va_list *pargm, size_t *pret)
{
	unsigned long int	lui;

	if (spec == 'c')
		ft_putc(pargm, pret);
	else if (spec == 's')
		ft_printstr(va_arg(*pargm, char *), pret);
	else if (spec == 'p')
	{
		lui = va_arg((*pargm), long unsigned int);
		if (lui != 0)
		{
			ft_put0x(pret);
			ft_printhex(lui, pret, 0);
		}
		else
			ft_putnil(pret);
	}
	else if (spec == 'd' || spec == 'i')
		ft_printnbr(va_arg(*pargm, int), pret);
	else if (spec == 'u')
		ft_printunbr(va_arg(*pargm, unsigned int), pret);
	else if (spec == 'x' || spec == 'X')
		ft_printhex(va_arg(*pargm, unsigned int), pret, (spec == 'X'));
	else if (spec == '%')
		ft_put37(pret);
}
