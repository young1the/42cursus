NAME		=	philosopher

UTILS_SRC	=	utils/ft_atoi.c\
				utils/ft_isdigit.c\
				utils/ft_putchar_fd.c\
				utils/ft_strlen.c\
				utils/ft_error.c\
				utils/ft_itoa.c\
				utils/ft_putstr_fd.c
UTILS_OBJ	=	$(UTILS_SRC:.c=.o)

SRC	=	main.c
OBJ	=	$(SRC:.c=.o)

FLAGS		=	-Wall -Werror -Wextra -lpthread

all: $(NAME)

$(NAME) :	$(OBJ) $(UTILS_OBJ)
			gcc $(FLAGS) $(OBJ) $(UTILS_OBJ) -o $(NAME)

clean :
		rm -rf *.o
		rm -rf utils/*.o

fclean : clean
		rm -rf $(NAME)

re : fclean all
