/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:35:49 by mabaffo           #+#    #+#             */
/*   Updated: 2022/10/24 17:25:13 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
size_t	ft_print_till_arg(char *s, size_t *pret);
void	ft_printargm(char specifier, va_list *pargm, size_t *pret);
void	ft_printstr(char *s, size_t *pret);
void	ft_printnbr(int n, size_t *pret);
void	ft_printunbr(unsigned int n, size_t *pret);
char	*ft_utoa(unsigned int n);
char	*ft_lutoax(long unsigned int n);
void	ft_printhex(long unsigned int n, size_t *pret, int upc);

#endif
