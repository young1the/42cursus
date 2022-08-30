# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanhuil <chanhuil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 14:11:08 by chanhuil          #+#    #+#              #
#    Updated: 2022/08/30 15:34:59 by chanhuil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_irc
SRCS		= Client.cpp Channel.cpp Parser.cpp Server.cpp main.cpp 
OBJS		= ${SRCS:.cpp=.o}

CC			= c++
RM			= rm -f

CPPFLAGS	= -Wall -Wextra -Werror -std=c++98

.c.o:
	${CC} ${CPPFLAGS} -I ./incs -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
	${CC} ${CPPFLAGS} -I ./incs ${OBJS} -o ${NAME}

all:		${NAME}

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY: .c.o all clean fclean re