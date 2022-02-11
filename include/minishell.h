#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

# define TRUE 1
# define FALSE 0

# define NO_FILE 1
# define COMMAND_NOT_FOUND 127
# define SYNTAX_ERROR 258

typedef struct s_mini
{
	char		**envs;
	int			exit;
	int			signal;
	int			stdin_fd;
	int			stdout_fd;
}				t_mini;
extern t_mini	g_mini;

typedef struct s_list
{
	char			*str;
	int				type;
	struct s_list	*next;
}					t_list;

typedef struct s_token
{
	char			c;
	struct s_token	*next;
}					t_token;

typedef struct s_heads
{
	t_list	*list_head;
	t_token	*token_head;
}			t_heads;

// libft
char	**ft_argsjoin(char **args1, char **args2);
int		ft_envcmp(const char *str, const char *env_str);
int		ft_isalpha(char c);
int		ft_isdigit(char c);
int		ft_isalnum(char c);
char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strndup(const char *s1, int n);
void	ft_error(char *str);
void	ft_fatal(char *str);

//builtin
int		ft_cd(char **cmd);
void	ft_cd_err(char **cmd);
void	change_cdenv(char *str, int flag);
int		ft_echo(char **cmd);
int		ft_env(void);
int		ft_exit(char **cmd);
int		ft_export(char **cmd);
char	**get_new_valid_datas(char **valid_datas);
char	**env_key(char *data);
int		replace_env(char *valid_data, char **key);
int		ft_pwd(void);
int		ft_unset(char **cmd);

// parse
// list
# define S_QUOTE 1
# define D_QUOTE 2
# define REDIRECTION 3
# define COMMAND 4
# define FILENAME 5
void	add_list(t_list *list_head, t_list *new);
void	clear_list(t_list *list_head);
t_list	*last_list(t_list *list_head);
t_list	*new_list(char *string, int type);
void	push_list(t_list *list_head, t_token *token_head,
			int *prev_type, int dollar_flag);
int		size_list(t_list *list_head);
// token
void	add_token(t_token *token_head, t_token *new);
void	clear_token(t_token *token_head);
t_token	*last_token(t_token *token_head);
t_token	*new_token(char c);
char	*pop_token(t_token *token_head);
void	push_token(t_token *token_head, char c);
int		size_token(t_token *token_head);
char	*token_to_string(t_token *token_head);
// make_list
int		make_list(t_list *list_head, char *buf);
// exec_list
# define S_RIGHT 1
# define D_RIGHT 2
# define S_LEFT 3
# define D_LEFT 4

// redirect
int		heredocument(char *tag, int in_fd);
int		redirect(int oldfd, int newfd);
int		redirecting(t_list **list, int in_fd);

// signal
int		event(void);
void	sig_child(int sig);
void	sig_handler(int sig);

//utils
char	*get_filename(char **cmd);
int		check_filename(char *filename);
int		find_dollar(char *string);
char	*find_key(char *string);
int		find_pipe(char *buf);
char	*find_value(char **envs, char *key);
void	free_argv(char **datas);
char	**get_command(t_list *list_head, int in_fd);
void	do_pipe(char *buf, int in_fd);
void	minishell_main(char *buf, int in_fd);
void	minishell(char *buf, int in_fd);
int		exec_command(char **cmd);
void	valid_data_error(char **cmd, int index);
char	**make_valid_datas(char **cmd);
char	**make_unsetvalid_datas(char **cmd);
int		is_absolute_path(char **cmd);
int		is_builtin(char **cmd);
int		is_binary(char **cmd);

int		fill_value(char *new, char *value);
void	fill_changed_string(char *string, char *new, char *key, char *value);
char	*change_string(char *string, char *key, char *value);
void	manage_dollar(char **string);

#endif
