#include "../include/minishell.h"

static char	**restore_cmd(t_list **list)
{
	t_list	*temp;
	int		count;
	char	**cmd;
	char	*str;

	temp = *list;
	count = 0;
	while (temp != NULL && temp->type == COMMAND)
	{
		temp = temp->next;
		count++;
	}
	cmd = (char **)malloc(sizeof(char *) * count + 1);
	temp = *list;
	count = 0;
	while (temp != NULL && temp->type == COMMAND)
	{
		str = ft_strdup(temp->str);
		cmd[count] = str;
		count++;
		temp = temp->next;
	}
	*list = temp;
	cmd[count] = NULL;
	return (cmd);
}

char	**get_command(t_list *list_head, int in_fd)
{
	t_list	*list;
	char	**cmd;

	list = list_head->next;
	cmd = NULL;
	if (list == NULL)
		return (NULL);
	while (list != NULL)
	{
		if (list->type == REDIRECTION)
		{
			if (redirecting(&list, in_fd) < 0)
			{
				free_argv(cmd);
				return (NULL);
			}
		}
		else if (list->type == COMMAND)
			cmd = restore_cmd(&list);
		else
			break ;
	}
	if (cmd == NULL)
		g_mini.exit = COMMAND_NOT_FOUND;
	return (cmd);
}
