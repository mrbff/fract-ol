/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:33:26 by mabaffo           #+#    #+#             */
/*   Updated: 2022/12/07 19:13:53 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdlib.h>

# define WIN_WIDTH 600
# define WIN_HEIGHT 600
# define MAX_ITER 2

# define KEY_C 99
# define KEY_Z 122
# define KEY_R 114
# define ESC 65307
# define ARROW_LEFT 65361
# define ARROW_UP 65362
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define ZOOM_OUT 5
# define ZOOM_IN 4

typedef struct s_img
{
	void	*mlx_img;
	char	*data;
	int		line_length;
	int		bits_per_pixel;
	int		endian;
}t_img;

typedef struct s_fractol
{
	void	*mlx_win;
	void	*mlx_ptr;
	int		color;
	int		fractal_name;
	int		x;
	double	x_min;
	double	x_max;
	int		y;
	double	y_min;
	double	y_max;
	double	zoom;
	double	z_real;
	double	z_im;
	double	c_real;
	double	c_im;
	double	iteration;
	double	temp;
	float	display_shift;
	t_img	*img;
}				t_fractol;

void			ft_error_message(void);
void			ft_usage_message(void);
void			ft_julia_usage_message(void);

int				ft_check_and_set(t_fractol *ptr, char **av, int ac);
void			ft_set(t_fractol *ptr, int type);

int				ft_init_mlx(t_fractol *ptr);
void			ft_draw_pixels(int x, int y, int color, t_fractol *ptr);
int				ft_put_image_to_window(t_fractol *ptr);

int				ft_destroy_fractol(t_fractol *ptr);

void			ft_init_fract(t_fractol *ptr);

void			ft_mandelbrot(t_fractol *ptr);

void			ft_julia_param(int argc,
					char *argv[], t_fractol *ptr);
void			ft_julia(t_fractol *ptr);

void			ft_burning_ship(t_fractol *ptr);

int				ft_key_hook(int keycode, t_fractol *ptr);
int				ft_zoom_hook(int keycode, int x, int y, t_fractol *ptr);
int				ft_init_hooks_and_loop(t_fractol *ptr);

#		endif
