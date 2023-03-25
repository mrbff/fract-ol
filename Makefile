# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 18:05:37 by mabaffo           #+#    #+#              #
#    Updated: 2022/12/07 18:05:52 by mabaffo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fractol

SRCS_DIR		=	./sources/

AR				=	ar
ARFLAGS			=	rcs

SRCS_F			=	main.c \
					init_mlx.c \
					ft_put_image_to_window.c \
					ft_draw_pixels.c \
					hooks.c \
					ft_set.c \
					ft_init_fract.c \
					ft_destroy_fractol.c \
					ft_mandelbrot.c \
					ft_julia.c \
					ft_burning_ship.c \
					usage_and_errors.c

SRCS			= 	$(addprefix $(SRCS_DIR), $(SRCS_F))

OBJS			=	$(SRCS:.c=.o)

CC				=	gcc
CC_FLAGS		= 	-Wall -Wextra -Werror -g -O3

RM				=	rm -f

LIBFT			=	libft/libft.a

.c.o:			
				$(CC) $(C_FLAGS) -c $< -o $(<:.c=.o) -I includes/

$(NAME):		$(OBJS)
				make -sC minilibx-linux
				make -sC libft
				$(CC) $(CC_FLAGS) $(OBJS) $(LIBFT) -o $(NAME) -L minilibx-linux -lmlx -lXext -lX11 -lm -pthread

all:			$(NAME)

clean:
				make -sC ./minilibx-linux clean
				make -sC ./libft clean
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME) $(LIBFT)

re:				fclean all

.PHONY:			all clean fclean re
