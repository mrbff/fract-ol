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

static void	ft_replicant(t_fractol *ptr)
{
	int i;

	i = 0;
	while (++i < NTHREADS)
	{
		ptr[i].mlx_win = ptr[0].mlx_win;
		ptr[i].mlx_ptr = ptr[0].mlx_ptr;
		ptr[i].color = ptr[0].color;
		ptr[i].fractal_name = ptr[0].fractal_name;
		ptr[i].x = ptr[0].x;
		ptr[i].x_min = ptr[0].x_min;
		ptr[i].x_max = ptr[0].x_max;
		ptr[i].y = ptr[0].y;
		ptr[i].y_min = ptr[0].y_min;
		ptr[i].y_max = ptr[0].y_max;
		ptr[i].zoom = ptr[0].zoom;
		ptr[i].z_real = ptr[0].z_real;
		ptr[i].z_im = ptr[0].z_im;
		ptr[i].c_real = ptr[0].c_real;
		ptr[i].c_im = ptr[0].c_im;
		ptr[i].iteration = ptr[0].iteration;
		ptr[i].temp = ptr[0].temp;
		ptr[i].display_shift = ptr[0].display_shift;
		ptr[i].max_iter = ptr[0].max_iter;
		ptr[i].incr_iter = ptr[0].incr_iter;
		ptr[i].img = ptr[0].img;
		ptr[i].xt = ptr[i - 1].xt + (WIN_WIDTH / NTHREADS);
	}
}

void	ft_launch_fractal(t_fractol *ptr)
{
	int	i;
	pthread_t *th;
	
	i = -1;
	th = malloc(sizeof(pthread_t) * NTHREADS);
	if (!th)
		return ;
	ptr->xt = 0;
	ft_replicant(ptr);
	if (ptr->fractal_name == 1)
	{
		while (++i < NTHREADS)
			pthread_create(&th[i], NULL, ft_mandelbrot, (void *)(&(ptr[i])));
	}
	else if (ptr->fractal_name == 2)
	{
		while (++i < NTHREADS)
			pthread_create(&th[i], NULL, ft_julia, (void *)(&(ptr[i])));
	}
	else if (ptr->fractal_name == 3)
	{
		while (++i < NTHREADS)
			pthread_create(&th[i], NULL, ft_burning_ship, (void *)(&(ptr[i])));
	}
	i = -1;
	while (++i < NTHREADS)
		pthread_join(th[i], NULL);
}
