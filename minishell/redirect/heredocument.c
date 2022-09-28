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

static void	heredocument_child(char *tag)
{
	char	*buf;
	int		temp_fd;
	t_list	header;

	header.next = NULL;
	redirect(g_mini.stdin_fd, STDIN_FILENO);
	temp_fd = open("temp", O_RDWR | O_CREAT | O_TRUNC, 0777);
	while (42)
	{
		buf = readline("> ");
		if (g_mini.signal == 1)
		{
			close(temp_fd);
			unlink("temp");
			exit (1);
		}
		if (ft_strcmp(tag, buf) == 0)
			break ;
		heredoc_child_util(&header, buf);
		free(buf);
	}
	redirect(temp_fd, STDOUT_FILENO);
	print_heredoc(header.next);
	close(temp_fd);
	exit(0);
}

int	heredocument(char *tag, int in_fd)
{
	int			exit_num;
	pid_t		pid;

	close(in_fd);
	pid = fork();
	if (pid < 0)
		ft_fatal("minishell : FORK FAILED!\n");
	if (pid == 0)
		heredocument_child(tag);
	else
	{
		waitpid(pid, &exit_num, 0);
		g_mini.exit = exit_num >> 8;
		if (g_mini.exit == 1)
			return (-1);
	}
	return (0);
}

//open_fd = open(list->str, O_RDWR | O_CREAT | O_TRUNC, 0777);
