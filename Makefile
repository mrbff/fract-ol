# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 22:45:01 by mabaffo           #+#    #+#              #
#    Updated: 2022/11/17 15:50:07 by mabaffo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Program		= fract-ol

files 	   = 
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
