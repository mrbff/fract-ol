/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:37:52 by mabaffo           #+#    #+#             */
/*   Updated: 2022/12/07 17:39:08 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_set(t_fractol *ptr, int type)
{
	ptr->fractal_name = type;
	ptr->x_min = -2.0;
	ptr->x_max = 2.0;
	ptr->y_min = -2.0;
	ptr->y_max = 2.0;
	ptr->zoom = IN_MAX_ITER;
	ptr->display_shift = 0.1;
	ptr->max_iter = IN_MAX_ITER;
	ptr->color = 0x10E;
	ptr->incr_iter = true;
}
