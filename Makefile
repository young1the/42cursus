NAME		=	philosopher

LIBFT_SRC	=	libft/ft_atoi.c\
				libft/ft_isdigit.c\
				libft/ft_itoa.c\
				libft/ft_strlen.c
LIBFT_OBJ	=	$(LIBFT_SRC:.c=.o)

SRC	=	srcs/main.c\
		srcs/error_handling.c\
		srcs/main.c\
		srcs/moniter.c\
		srcs/philo_doing.c\
		srcs/philosopher.c\
		srcs/utils.c
OBJ	=	$(SRC:.c=.o)
INC =	inc

FLAGS		=	-Wall -Werror -Wextra -lpthread

all: $(NAME)

$(NAME) :	$(OBJ) $(LIBFT_OBJ)
			gcc -I $(INC) $(FLAGS) $(OBJ) $(LIBFT_OBJ) -o $(NAME)

clean :
		rm -rf srcs/*.o
		rm -rf libft/*.o

fclean : clean
		rm -rf $(NAME)

re : fclean all
