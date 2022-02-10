#include "../include/minishell.h"

static void	do_pipe_checker(int pipe_checker, int pid_checker)
{
	if (pipe_checker < 0)
		ft_fatal("minishell : PIPE FAILED!\n");
	if (pid_checker < 0)
		ft_fatal("minishell : FORK FAILED!\n");
}

static char	**do_pipe_util(char *buf, int in_fd)
{
	t_list	list_head;
	char	**cmd;

	list_head.next = NULL;
	if (make_list(&(list_head), buf) == 1)
		return (NULL);
	cmd = get_command(&(list_head), in_fd);
	if (cmd == NULL)
		return (NULL);
	clear_list(&(list_head));
	return (cmd);
}

void	do_pipe(char *buf, int in_fd)
{
	int		fd[2];
	int		index;
	int		checker;
	pid_t	pid;
	char	**cmd;

	checker = pipe(fd);
	pid = fork();
	do_pipe_checker(checker, pid);
	if (pid == 0)
	{
		close(fd[0]);
		cmd = do_pipe_util(buf, in_fd);
		redirect(in_fd, STDIN_FILENO);
		redirect(fd[1], STDOUT_FILENO);
		exec_command(cmd);
		exit(0);
	}
	close(fd[1]);
	wait(NULL);
	index = find_pipe(buf) + 1;
	minishell(buf + index, fd[0]);
}

void	minishell_main(char *buf, int in_fd)
{
	t_list	list_head;
	char	**cmd;

	list_head.next = NULL;
	if (make_list(&(list_head), buf) == 1)
	{
		g_mini.exit = SYNTAX_ERROR;
		return ;
	}
	cmd = get_command(&(list_head), in_fd);
	if (cmd == NULL)
	{
		g_mini.exit = COMMAND_NOT_FOUND;
		return ;
	}
	g_mini.exit = exec_command(cmd);
	clear_list(&(list_head));
}

void	minishell(char *buf, int in_fd)
{
	t_list	list_head;
	int		exit_num;
	char	**cmd;

	list_head.next = NULL;
	if (find_pipe(buf) < 0)
	{
		redirect(in_fd, STDIN_FILENO);
		if (make_list(&(list_head), buf) == 1)
			exit (SYNTAX_ERROR);
		cmd = get_command(&(list_head), in_fd);
		if (cmd == NULL)
			exit (g_mini.exit);
		exit_num = exec_command(cmd);
		clear_list(&(list_head));
		exit (exit_num);
	}
	else
		do_pipe(buf, in_fd);
}
