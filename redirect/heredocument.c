#include "../include/minishell.h"

static void	print_heredoc(t_list *header)
{
	t_list	*temp;

	while (header != NULL)
	{
		printf("%s\n", header->str);
		temp = header;
		header = header->next;
		free(temp->str);
		free(temp);
	}
}

static void	heredoc_child_util(t_list *header, char *buf)
{
	t_list	*new;
	char	*str;

	str = ft_strdup(buf);
	manage_dollar(&str);
	new = new_list(str, 0);
	add_list(header, new);
}

static void	heredocument_child(int *fd, char *tag)
{
	char	*buf;
	t_list	header;

	header.next = NULL;
	close(fd[0]);
	while (42)
	{
		buf = readline("> ");
		if (g_mini.signal == 1)
		{
			close(fd[1]);
			exit (1);
		}
		if (ft_strcmp(tag, buf) == 0)
			break ;
		heredoc_child_util(&header, buf);
		free(buf);
	}
	redirect(fd[1], STDOUT_FILENO);
	print_heredoc(header.next);
	exit(0);
}

int	heredocument(char *tag)
{
	int			fd[2];
	int			exit_num;
	pid_t		pid;

	if (pipe(fd) < 0)
		ft_fatal("minishell : PIPE FAILED!\n");
	pid = fork();
	if (pid < 0)
		ft_fatal("minishell : FORK FAILED!\n");
	if (pid == 0)
		heredocument_child(fd, tag);
	else
	{
		close(fd[1]);
		waitpid(pid, &exit_num, 0);
		g_mini.exit = exit_num >> 8;
		if (g_mini.exit == 1)
			return (-1);
		return (fd[0]);
	}
	return (-1);
}
