NAME	=	cub3d

LIBFT_SRC		=	libft/ft_memset.c\
					libft/ft_strcmp.c\
					libft/ft_strdup.c\
					libft/ft_strjoin.c\
					libft/ft_strlcpy.c\
					libft/ft_strlen.c\
					libft/ft_strndup.c
LIBFT_OBJ		=	$(LIBFT_SRC:.c=.o)


PARSING_SRC		=	parsing/parsing.c\
					parsing/get_next_line.c\
					parsing/list/add_list.c\
					parsing/list/clear_list.c\
					parsing/list/last_list.c\
					parsing/list/new_list.c\
					parsing/list/size_list.c\
					parsing/lexer/lexer_list.c\
					parsing/lexer/map/init_map.c\
					parsing/lexer/map/fill_map.c\
					parsing/lexer/map/check_ud.c\
					parsing/lexer/map/check_lr.c

PARSING_OBJ		=	$(PARSING_SRC:.c=.o)

MAIN			=	main.c
MAIN_OBJ		=	$(MAIN:.c=.o)

INC				=	include
OBJ				=	$(LIBFT_OBJ) $(PARSING_OBJ) $(MAIN_OBJ)

CFLAGS	=	-Wall -Werror -Wextra


all: $(NAME)

$(NAME) :	$(OBJ)
			gcc $(CFLAGS) $(OBJ) -I$(INC) -o $(NAME)

clean :
		rm -rf $(OBJ)

fclean : clean
		rm -rf $(NAME)

re : fclean all
