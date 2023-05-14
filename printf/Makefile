# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduraes- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 20:32:32 by jduraes-          #+#    #+#              #
#    Updated: 2023/05/11 20:47:48 by jduraes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a
FTS =
SRC =	${FTS}
OBJS =	$(SRC:.c=.o)
HEADER =	libftprintf.h
INCLUDE =	-I .
CFLAGS =	-Wall -Wextra -Werror
RM =	rm -f
CC =	cc -g
%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)
${NAME}:	${OBJS}
	ar rcs ${NAME} ${OBJS} ${HEADER}
all:	${NAME}
clean:
	${RM} ${OBJS}
fclean:	clean
	${RM} ${NAME}
re:	fclean all
