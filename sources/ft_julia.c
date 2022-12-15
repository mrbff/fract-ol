/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:16:38 by mabaffo           #+#    #+#             */
/*   Updated: 2022/12/07 17:02:48 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_julia_param(int argc, char *argv[], t_fractol *ptr)
{
	if (argc == 4)
	{
		ptr->c_real = ft_atof(argv[2]);
		ptr->c_im = ft_atof(argv[3]);
		if (ptr->c_real < -2 || ptr->c_real > 2
			|| ptr->c_im < -2 || ptr->c_im > 2)
			ft_julia_usage_message();
		ft_set(ptr, 2);
	}
	else
		ft_julia_usage_message();
}

void	ft_julia(t_fractol *ptr)
{
	ptr->x = 0;
	while (ptr->x < WIN_WIDTH)
	{
		ptr->y = 0;
		while (ptr->y < WIN_HEIGHT)
		{
			ft_init_fract(ptr);
			while (ptr->z_real * ptr->z_real + ptr->z_im * ptr->z_im < 4
				&& ptr->iteration < ptr->max_iter)
			{
				ptr->temp = ptr->z_real;
				ptr->z_real = ptr->z_real * ptr->z_real - ptr->z_im * ptr->z_im
					+ ptr->c_real;
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
/*
 * printf("c = %f + (%fi)\n", ptr->c_real, ptr->c_im);
 * In the Julia Set, c is a constant, that's why we don't initiate it
 * at the function ft_init_fract and instead set the value for c_im and c_real
 * using ft_atof in the function ft_julia_param.
 */
