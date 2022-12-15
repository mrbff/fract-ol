/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:37:53 by mabaffo           #+#    #+#             */
/*   Updated: 2022/12/08 21:22:13 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	size_t	ret;
	size_t	i;
	va_list	argm;

	i = 0;
	ret = 0;
	va_start(argm, format);
	while (format[i])
	{
		i += ft_print_till_arg(&((char *)format)[i], &ret);
		if (format[i] == '%')
			i++;
		if (format[i])
		{
			ft_printargm(format[i], &argm, &ret);
			i++;
		}
	}
	va_end(argm);
	return (ret);
}
