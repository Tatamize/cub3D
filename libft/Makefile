# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kito <kito@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/01 17:08:43 by kito          #+#    #+#                  #
#    Updated: 2023/01/22 12:15:57 by kito          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
SRC			=	ft_atoi.c		\
				ft_memset.c		\
				ft_strlen.c		\
				ft_substr.c		\
				ft_putstr_fd.c

CFLAGS		=	-Wall -Wextra -Werror

REGUL_OBJ	=	$(SRC:%.c=%.o)

HEADER_FILE	=	libft.h

OBJ			=	$(REGUL_OBJ)

all: $(NAME)

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)

%.o: %.c libft.h
		@gcc -c $(CFLAGS) -o $@ $<

clean:
	rm -rf $(REGUL_OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
