/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:29:39 by mabaffo           #+#    #+#             */
/*   Updated: 2022/12/07 17:33:46 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	ft_init_hooks_and_loop(t_fractol *ptr)
{
	ft_init_mlx(ptr);
	mlx_hook(ptr->mlx_win, 2, 1L << 0, ft_key_hook, ptr);
	mlx_hook(ptr->mlx_win, 17, 0, ft_destroy_fractol, ptr);
	mlx_mouse_hook(ptr->mlx_win, ft_zoom_hook, ptr);
	mlx_loop(ptr->mlx_ptr);
	return (0);
}

int	ft_init_mlx(t_fractol *ptr)
{
	ptr->mlx_ptr = mlx_init();
	if (!(ptr->mlx_ptr))
		ft_error_message();
	ptr->mlx_win = mlx_new_window(ptr->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "fract-ol");
	if (!(ptr->mlx_win))
		ft_error_message();
	ft_put_image_to_window(ptr);
	return (0);
}
