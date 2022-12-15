/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 22:11:18 by mabaffo           #+#    #+#             */
/*   Updated: 2022/12/07 18:27:45 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"
#include <stdio.h>//
int	ft_zoom_hook(int keycode, int x, int y, t_fractol *ptr)
{
	double		tmp_x;
	double		tmp_y;

	tmp_x = x / ptr->zoom + ptr->x_min;
	tmp_y = y / ptr->zoom + ptr->y_min;
	if (keycode == ZOOM_IN)
	{
		ptr->zoom *= 1.1;
		ptr->display_shift /= 1.1;
		if (ptr->zoom > IN_MAX_ITER)
			ptr->max_iter += 1;
	}
	if (keycode == ZOOM_OUT)
	{
		ptr->zoom /= 1.1;
		ptr->display_shift *= 1.1;
		if (ptr->max_iter > IN_MAX_ITER)
			ptr->max_iter -= 1;
	}
	printf("zoom = %f\n", ptr->zoom);//
	ft_printf("max_iter = %d\n", ptr->max_iter);
	ptr->x_min = tmp_x - (x / ptr->zoom);
	ptr->y_min = tmp_y - (y / ptr->zoom);
	ft_put_image_to_window(ptr);
	return (0);
}

int	ft_chc(int keycode, int i)
{
	if (keycode == KEY_C)
	{
		if (i < 31)
			i++;
		else
			i = 0;
	}
	if (keycode == KEY_Z)
	{
		if (i > 0)
			i--;
		else
			i = 30;
	}
	return (i);
}

void	ft_color(int keycode, t_fractol *ptr)
{
	static int		i;
	long unsigned	*col_arr;

	col_arr = (unsigned long [31])
	{
		0xFF686A9E, 0xFFFFFFFF, 0xFF683F60, 0xFF671780, 0x950FB0,
		0x994A90, 0xF88888888, 0xFF6D8FC0, 0x89B660, 0xFFFE898F,
		0xFF6D8FC0, 0xFFC10F00, 0xFF66B0F0, 0x66180, 0x286D0,
		0x10E, 0xFFC3AC60, 0x99D2A0, 0x23C20, 0xDFD440, 0x94DC60,
		0xFF5D8FC0, 0xFF4E7830, 0x950FB0, 0xFF676670, 0xE34C10,
		0x34910, 0xFF671780, 0xFFA90CC, 0x9AFC80, 0xFF6888E0
	};
	if (keycode == KEY_R)
		ft_set(ptr, ptr->fractal_name);
	else if (keycode == KEY_C || keycode == KEY_Z)
		i = ft_chc(keycode, i);
	ptr->color = col_arr[i];
	ft_printf("color = %X\n", ptr->color);
}

int	ft_key_hook(int keycode, t_fractol *ptr)
{
	ft_printf("keycode = %d\n", keycode);
	if (keycode == ESC)
		ft_destroy_fractol(ptr);
	else if (keycode == KEY_C || keycode == KEY_Z || keycode == KEY_R)
		ft_color(keycode, ptr);
	else if (keycode == ARROW_UP)
		ptr->y_min = ptr->y_min - ptr->display_shift;
	else if (keycode == ARROW_DOWN)
		ptr->y_min = ptr->y_min + ptr->display_shift;
	else if (keycode == ARROW_LEFT)
		ptr->x_min = ptr->x_min - ptr->display_shift;
	else if (keycode == ARROW_RIGHT)
		ptr->x_min = ptr->x_min + ptr->display_shift;
	ft_put_image_to_window(ptr);
	return (0);
}
/*
 * printf("keycode: %i\n", keycode);
 * ptr->color = ptr->color + 0xF0A0F0;0x10E;
 * printf("%#X\n", ptr->color);
 */
