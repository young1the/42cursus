NAME	=	minishell

SRC		=	builtin/ft_cd.c\
			builtin/ft_cd_utils.c\
			builtin/ft_echo.c\
			builtin/ft_env.c\
			builtin/ft_exit.c\
			builtin/ft_export.c\
			builtin/ft_export_utils.c\
			builtin/ft_pwd.c\
			builtin/ft_unset.c\
			builtin/ft_unset_utils.c\
			libft/ft_argsjoin.c\
			libft/ft_envcmp.c\
			libft/ft_isalnum.c\
			libft/ft_itoa.c\
			libft/ft_putstr_fd.c\
			libft/ft_split.c\
			libft/ft_strcmp.c\
			libft/ft_strdup.c\
			libft/ft_strjoin.c\
			libft/ft_strlcpy.c\
			libft/ft_strlen.c\
			libft/ft_strncmp.c\
			libft/ft_strndup.c\
			libft/ft_error.c\
			libft/ft_fatal.c\
			parse/list/add_list.c\
			parse/list/clear_list.c\
			parse/list/last_list.c\
			parse/list/new_list.c\
			parse/list/push_list.c\
			parse/list/size_list.c\
			parse/token/add_token.c\
			parse/token/clear_token.c\
			parse/token/last_token.c\
			parse/token/new_token.c\
			parse/token/pop_token.c\
			parse/token/push_token.c\
			parse/token/size_token.c\
			parse/token/token_to_string.c\
			parse/make_list.c\
			redirect/heredocument.c\
			redirect/redirect.c\
			redirect/redirecting.c\
			signal/signal.c\
			utils/exec_command.c\
			utils/get_filename.c\
			utils/find_dollar.c\
			utils/find_key.c\
			utils/find_pipe.c\
			utils/find_value.c\
			utils/free_argv.c\
			utils/get_command.c\
			utils/manage_dollar.c\
			utils/make_valid_datas.c\
			utils/minishell.c\
			utils/what_command.c\
			main.c

OBJ		=	$(SRC:.c=.o)
INC_DIR =	include

CFLAGS	=	-Wall -Werror -Wextra

LIB		=	$(LDFLAGS) -lreadline
INCLUDE	=	-I$(INC_DIR) $(CPPFLAGS)

all: $(NAME)

$(NAME) :	$(OBJ)
			gcc  $(CFLAGS) $(OBJ) $(INCLUDE) $(LIB) -o $(NAME)

clean :
		rm -rf $(OBJ)

fclean : clean
		rm -rf $(NAME)

re : fclean all
