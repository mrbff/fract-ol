/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:23:26 by mabaffo           #+#    #+#             */
/*   Updated: 2022/12/07 17:28:32 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_mandelbrot(t_fractol *ptr)
{
	ptr->x = ptr->xt;
	while (ptr->x < ptr->xt + (WIN_WIDTH / NTHREADS))
	{
		ptr->y = 0;
		while (ptr->y < WIN_HEIGHT)
		{
			ft_init_fract(ptr);
			while (ptr->z_real * ptr->z_real + ptr->z_im * ptr->z_im < 4
				&& ptr->iteration < ptr->max_iter)
			{
				ptr->temp = ptr->z_real;
				ptr->z_real = ptr->z_real * ptr->z_real - ptr->z_im
					* ptr->z_im + ptr->c_real;
				ptr->z_im = 2 * ptr->z_im * ptr->temp + ptr->c_im;
				ptr->iteration++;
			}
			ft_draw_pixels(ptr->x, ptr->y,
				ptr->iteration * ptr->color / IN_MAX_ITER, ptr);
			ptr->y++;
		}
		ptr->x++;
	}
}
/* The mandelbrot set is colorized taking in account the amount of
 * iterations necessary for a complex number to diverge and escape 
 * into infinity. Every number outside the -2.0 and +2.0 range in 
 * both axis will diverge, which means that for our calculation we
 * must take it into account. 
 * That is why our calculation for mandelbrot range looks like this:
 *
 * 	ptr->z_real * ptr->z_real + ptr->z_im * ptr->z_im < 4
 *
 * deriving from:
 *
 * 	f(z) = (z_real + z_im)² + c_real + c_im
 * 	|z| > 2
 * 	(z_real + z_im)² < 4
 */
