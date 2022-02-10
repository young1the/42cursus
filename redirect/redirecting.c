#include "../include/minishell.h"

static void	redirecting_check(int open_fd, char *path)
{
	if (open_fd < 3)
	{
		ft_error("minishell : ");
		ft_error(path);
		ft_error(" : No such file or directory\n");
	}
	return ;
}

static int	redirecting_util(t_list *list, int flag, int in_fd)
{
	int		open_fd;

	if (flag == S_RIGHT)
	{
		open_fd = open(list->str, O_RDWR | O_CREAT, 0777);
		redirect(open_fd, STDOUT_FILENO);
	}
	if (flag == D_RIGHT)
	{
		open_fd = open(list->str, O_RDWR | O_CREAT | O_APPEND, 0777);
		redirect(open_fd, STDOUT_FILENO);
	}
	if (flag == S_LEFT)
	{
		open_fd = open(list->str, O_RDONLY, 0777);
		redirecting_check(open_fd, list->str);
		redirect(open_fd, in_fd);
	}
	if (flag == D_LEFT)
	{
		open_fd = heredocument(list->str);
		redirect(open_fd, in_fd);
	}
	return (open_fd);
}

static int	check_redirection_type(char *string)
{
	if (!ft_strcmp(">", string))
		return (S_RIGHT);
	else if (!ft_strcmp(">>", string))
		return (D_RIGHT);
	else if (!ft_strcmp("<", string))
		return (S_LEFT);
	else if (!ft_strcmp("<<", string))
		return (D_LEFT);
	else
	{
		ft_error("minishell : syntax error near unexpected token \'");
		if (string[0] != string[1])
			ft_error(string + 1);
		else
			ft_error(string + 2);
		ft_error("\'\n");
		return (-1);
	}
}

int	redirecting(t_list **list, int in_fd)
{
	t_list	*temp;
	int		redirection_type;
	int		open_fd;

	temp = *list;
	redirection_type = check_redirection_type(temp->str);
	if (temp->next == NULL || redirection_type < 0)
	{
		if (redirection_type > 0)
			ft_error
			("minishell : syntax error near unexpected token \'newline\'\n");
		return (-1);
	}
	open_fd = -1;
	if (redirection_type == S_RIGHT)
		open_fd = redirecting_util(temp->next, S_RIGHT, in_fd);
	else if (redirection_type == D_RIGHT)
		open_fd = redirecting_util(temp->next, D_RIGHT, in_fd);
	else if (redirection_type == S_LEFT)
		open_fd = redirecting_util(temp->next, S_LEFT, in_fd);
	else if (redirection_type == D_LEFT)
		open_fd = redirecting_util(temp->next, D_LEFT, in_fd);
	temp = temp->next->next;
	*list = temp;
	return (open_fd);
}
