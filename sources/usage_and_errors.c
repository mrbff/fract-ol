/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_and_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:51:45 by mabaffo           #+#    #+#             */
/*   Updated: 2022/12/07 17:56:51 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_putstr(char	*s)
{
	ft_putstr_fd(s, 1);
}

void	ft_usage_message(void)
{
	ft_putstr("To generate a fractal, you must choose one of the ");
	ft_putstr("following arguments:\n\n1. mandelbrot\n2. julia +");
	ft_putstr(" complex number between -2");
	ft_putstr(".000 and 2.000 (±x.xxx ±x.xxx)\n3. burning-ship\n\n");
	ft_putstr("Which means your input should look something like this:");
	ft_putstr("\n\n\t./fractol julia −0.823 0.156\n\nYou can also press");
	ft_putstr(" the arrow keys to go up and down and left");
	ft_putstr(" and right,\nuse the mouse scroll to zoom in and out");
	ft_putstr(" and press 'C' to change the color palette!\n");
	exit(0);
}

void	ft_julia_usage_message(void)
{
	ft_putstr("\nTo generate a julia fractal, you must type in one ");
	ft_putstr("complex number between -2.000 and 2.000 right after calling\n\t");
	ft_putstr("./fractol julia.\n\nComplex numbers are composed of one real par");
	ft_putstr("t and one imaginary part!\nSo, you actually need to type two ");
	ft_putstr("different values separated by a space (' ')\n\nSuch as:\n\n\t");
	ft_putstr(" 0.701 -0.382\n\t -0.726 0.189\n\t 0.000 -0.800\n");
	ft_putstr("\n(That actually means:\n");
	ft_putstr("\t 0.701 - 0.382i\n\t-0.726 + 0.189i\n\t 0.000 - 0.800i)\n\n");
	exit(0);
}

void	ft_error_message(void)
{
	ft_putstr("Sorry, an error occurred!\n");
	exit(0);
}
