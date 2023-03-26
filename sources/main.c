/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:07:13 by mabaffo           #+#    #+#             */
/*   Updated: 2022/12/07 17:11:24 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

int	main(int ac, char **av)
{
	t_fractol	ptr[NTHREADS];

	ptr->img = malloc(sizeof(t_img));
	if (!ptr->img)
		ft_error_message();
	if (ac < 2 || ac > 4 || ft_check_and_set(ptr, av, ac))
		ft_usage_message();
	else
		ft_init_hooks_and_loop(ptr);
	return (0);
}

int	ft_check_and_set(t_fractol *ptr, char **av, int ac)
{
	if (!ft_strncmp("mandelbrot", av[1], ft_strlen(av[1])))
		ft_set(ptr, 1);
	else if (!ft_strncmp("julia", av[1], ft_strlen(av[1])))
		ft_julia_param(ac, av, ptr);
	else if (!ft_strncmp("burning-ship", av[1], ft_strlen(av[1])))
		ft_set(ptr, 3);
	else
		return (1);
	return (0);
}
/* The function that generates all three fractals (with minor changes) is:
 *
 * 	f(z) = z² + c
 *
 * in which "c" is a complex number, so:
 *
 * 	f(z) = z² + c_real + c_im
 *
 * z is always replaced by the result of the previous run of the function, so
 * we can also look at it in the following way:
 *
 * 	f(z0) = 0 + c
 * 	f(z1) = (c)² + c
 * 	f(z1) = (c_real + c_im * i)(c_real + c_im * i) + c_real + c_im
 * 	f(z1) = c_real² - c_im² + 2 * c_im * c_real
 *
 */
