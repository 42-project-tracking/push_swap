# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 14:35:18 by codespace         #+#    #+#              #
#    Updated: 2023/09/29 20:47:27 by abied-ch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =	src/main.c \
		src/radix_sort.c \
		src/simplify.c \
		src/simple_sort.c \
		utils/errors.c \
		utils/list_utils.c \
		operations/push.c \
		operations/reverse_rotate.c \
		operations/rotate.c \
		operations/swap.c \
		utils/utils.c \

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror -I ./include

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

