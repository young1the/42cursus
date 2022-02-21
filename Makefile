NAME	=	cub3d

MLX_PATH = ./mlx/
MLX		= $(MLX_PATH)libmlx.a
MLX		+= -lm -Imlx -framework OpenGL -framework AppKit

LIBFT_SRC		=	libft/ft_atoi.c\
					libft/ft_memset.c\
					libft/ft_split.c\
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
					parsing/lexer/config/fill_config.c\
					parsing/lexer/map/init_map.c\
					parsing/lexer/map/fill_map.c\
					parsing/lexer/map/check_ud.c\
					parsing/lexer/map/check_lr.c
PARSING_OBJ		=	$(PARSING_SRC:.c=.o)

MAIN			=	main.c\
					rgb_to_hex.c
MAIN_OBJ		=	$(MAIN:.c=.o)

INC				=	include
OBJ				=	$(LIBFT_OBJ) $(PARSING_OBJ) $(MAIN_OBJ)

CFLAGS	=	-Wall -Werror -Wextra


all: $(NAME)

$(NAME) :	$(OBJ)
			make -C ./mlx
			gcc $(CFLAGS) $(MLX) $(OBJ) -I$(INC) -o $(NAME)

clean :
		make clean -C ./mlx
		rm -rf $(OBJ)

fclean : clean
		rm -rf $(NAME)

re : fclean all
