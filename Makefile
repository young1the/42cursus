# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: young-ch <young-ch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/12 18:08:10 by young-ch          #+#    #+#              #
#    Updated: 2021/07/07 14:59:47 by young-ch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pushswap

SRC		=	bigsort.c\
			checkbeforesort.c\
			gameofa.c\
			gameofb.c\
			handleorder.c\
			handlestack.c\
			popandpush.c\
			smallsort.c\
			sortforsort.c\
			utilsofchecker.c\
			libft/ft_atoll.c\
			libft/ft_error.c\
			libft/ft_isdigit_plus.c\
			libft/ft_strdup.c\
			libft/ft_strjoin.c\
			libft/ft_strlcpy.c\
			libft/ft_strlen.c\
			libft/ft_split.c\
			gnl/get_next_line.c

OBJ  = $(SRC:.c=.o)

PS = push_swap
PSS = main_pushswap.c
PSO = $(PSS:.c=.o)

CK = checker
CKS = main_checker.c
CKO = $(CKS:.c=.o)

FLAGS = -Wall -Werror -Wextra

LIBNAME = pushswap.a

all: $(PS) $(CK)

$(LIBNAME) : $(OBJ)
	ar rcs $(LIBNAME) $(OBJ)

$(PS): $(LIBNAME) $(PSO)
	gcc $(FLAGS) $(LIBNAME) $(PSO) -o $(PS)

$(CK): $(LIBNAME) $(CKO)
	gcc $(FLAGS) $(LIBNAME) $(CKO) -o $(CK)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(OBJ)
	rm -rf $(PSO)
	rm -rf $(CKO)
	rm -rf $(PS)
	rm -rf $(CK)
	rm -rf $(LIBNAME)

re: fclean all
