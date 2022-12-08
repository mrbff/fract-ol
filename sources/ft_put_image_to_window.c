/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image_to_window.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:39:35 by mabaffo           #+#    #+#             */
/*   Updated: 2022/12/07 17:49:24 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_launch_fractal(t_fractol *ptr);

int	ft_put_image_to_window(t_fractol *ptr)
{
	if (!(ptr->img->mlx_img))
	{	
		ptr->img->mlx_img = mlx_new_image(ptr->mlx_ptr,
				WIN_WIDTH, WIN_HEIGHT);
		if (!(ptr->img->mlx_img))
			ft_error_message();
		ptr->img->data = mlx_get_data_addr(ptr->img->mlx_img,
				&ptr->img->bits_per_pixel,
				&ptr->img->line_length,
				&ptr->img->endian);
		if (!(ptr->img->data))
			ft_error_message();
	}
	ft_launch_fractal(ptr);
	mlx_put_image_to_window(ptr->mlx_ptr,
		ptr->mlx_win, ptr->img->mlx_img, 0, 0);
	return (0);
}

void	ft_launch_fractal(t_fractol *ptr)
{
	if (ptr->fractal_name == 1)
		ft_mandelbrot(ptr);
	else if (ptr->fractal_name == 2)
		ft_julia(ptr);
	else if (ptr->fractal_name == 3)
		ft_burning_ship(ptr);
}
