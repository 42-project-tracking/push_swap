# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 14:35:18 by codespace         #+#    #+#              #
#    Updated: 2023/09/29 16:37:30 by abied-ch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =  errors.c \
		list_utils.c \
		main.c \
		push.c \
		radix_sort.c \
		reverse_rotate.c \
		rotate.c \
		simplify.c \
		swap.c \
		utils.c \
		simple_sort.c \

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror -Iincludes

RM = rm -rf

all: ${NAME} ${CHECK}
${NAME}: ${OBJS}
	@${MAKE} -C ./libft --no-print-directory
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

clean: 
	@${MAKE} -C ./libft --no-print-directory fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all
	
.PHONY: all clean fclean re

