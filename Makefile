# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: young-ch <young-ch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/12 18:08:10 by young-ch          #+#    #+#              #
#    Updated: 2021/06/12 18:27:07 by young-ch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	fractol

SRC		=	complex.c\
			fractals.c\
			ft_strcmp.c\
			main.c\
			mlx_control.c

OBJ  = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

LIBFLAGS = -framework OpenGL -framework AppKit -lm -lmlx

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) $(LIBFLAGS) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: fclean all
