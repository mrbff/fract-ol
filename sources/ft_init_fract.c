/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:20:35 by mabaffo           #+#    #+#             */
/*   Updated: 2022/12/07 17:51:24 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_init_fract(t_fractol *ptr)
{
	ptr->iteration = 0;
	if (ptr->fractal_name == 2)
	{
		ptr->z_real = ptr->x / ptr->zoom + ptr->x_min;
		ptr->z_im = ptr->y / ptr->zoom + ptr->y_min;
	}
	else
	{
		ptr->c_real = ptr->x / ptr->zoom + ptr->x_min;
		ptr->c_im = ptr->y / ptr->zoom + ptr->y_min;
		ptr->z_real = 0;
		ptr->z_im = 0;
	}
}
