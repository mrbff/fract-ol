NAME	= libft

FILES 	   = ft_isalpha \
	     		ft_isdigit \
			ft_isalnum \
			ft_isascii \
			ft_isprint \
			ft_strlen \
			ft_memset \
			ft_bzero \
			ft_memcpy \
			ft_memmove \
			ft_strlcpy \
			ft_strlcat \
			ft_toupper \
			ft_tolower \
			ft_strchr \
			ft_strrchr \
			ft_strncmp \
			ft_memchr \
			ft_memcmp \
			ft_strnstr \
			ft_atoi \
			ft_calloc \
			ft_strdup \
			ft_substr \
			ft_strjoin \
			ft_strtrim \
			ft_split \
			ft_itoa \
			ft_strmapi \
			ft_striteri \
			ft_putchar_fd \
			ft_putstr_fd \
			ft_putendl_fd \
			ft_putnbr_fd \
			ft_ischarofset \
			ft_memdel \
			ft_strcmp \
			ft_strtoupper \
			ft_strtolower \
			ft_atof \
			ft_countdig \
			ft_lucountdig \
			ft_lutoax \
			ft_utoa \
			ft_printf \
			ft_printhex \
			ft_print_till_arg \
			ft_printargm \
			ft_printstr \
			ft_printnbr \
			ft_printunbr \

BFILES	= ft_lstnew \
		ft_lstadd_front \
		ft_lstsize \
		ft_lstlast \
		ft_lstadd_back \
		ft_lstclear \
		ft_lstdelone \
		ft_lstiter \
		ft_lstmap \

CC	= gcc

CFLAGS	= -Wall -Wextra -Werror

OUTN	= $(NAME).a

CFILES	= $(FILES:%=%.c)

CBFILES  = $(BFILES:%=%.c)

OFILES	= $(FILES:%=%.o)

OBFILES  = $(BFILES:%=%.o)

$(NAME):
	$(CC) $(CFLAGS) -c $(CFILES) -I./
	ar -rsv $(OUTN) $(OFILES)

all: $(NAME)

clean:
	rm -rf $(OBFILES) $(OFILES)

fclean: clean
	rm -rf $(OUTN)

re: fclean all

bonus:
	$(CC) $(CFLAGS) -c $(CBFILES) -I./
	ar -rsv $(OUTN) $(OBFILES)

.PHONY: all, clean, fclean, re, bonus
