# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 22:45:01 by mabaffo           #+#    #+#              #
#    Updated: 2022/10/24 18:18:02 by mabaffo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Library		= libftprintf

files 	   = ft_printf \
			ft_print_till_arg \
			ft_printargm \
			ft_printstr \
			ft_printnbr \
			ft_printunbr \
			ft_utoa \
			ft_lutoax \
			ft_printhex
CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

Libftmake	= @make -C libft/

Libft		= libft.a

Rename		= mv libft/$(Libft) ./ && mv $(Libft) $(OUTN)

OUTN	= $(Library).a

OFILES	= $(files:%=%.o)

NAME	= $(OUTN)

$(NAME): $(OFILES) 
	$(Libftmake)
	$(Rename)
	ar -rsv $(OUTN) $(OFILES)

all: $(NAME)

clean:
	rm -f $(NAME)
	rm -f $(OFILES)
	@make clean -C libft/

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
