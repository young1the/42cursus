#include "../include/minishell.h"

static void	restore_cmd(t_list **list, t_list *cmd_head)
{
	t_list	*new;
	char	*str;

	if ((*list)->type == COMMAND)
	{
		str = ft_strdup((*list)->str);
		new = new_list(str, 0);
		add_list(cmd_head, new);
		*(list) = (*list)->next;
	}
}

static char	**list_to_argv(t_list *cmd_head)
{
	int		count;
	char	**cmd;
	int		index;
	t_list	*cmd_ptr;

	count = size_list(cmd_head);
	if (count == 0)
		return (NULL);
	cmd = (char **)malloc(sizeof(char *) * count + 1);
	index = 0;
	cmd_ptr = cmd_head->next;
	while (cmd_ptr != NULL)
	{
		cmd[index] = ft_strdup(cmd_ptr->str);
		index++;
		cmd_ptr = cmd_ptr->next;
	}
	cmd[index] = NULL;
	return (cmd);
}

char	**get_command(t_list *list_head, int in_fd)
{
	t_list	*list;
	t_list	cmd_head;
	char	**cmd;

	list = list_head->next;
	cmd_head.next = NULL;
	if (list == NULL)
		return (NULL);
	while (list != NULL)
	{
		if (list->type == REDIRECTION)
		{
			if (redirecting(&list, in_fd) < 0)
				return (NULL);
		}
		else if (list->type == COMMAND)
			restore_cmd(&list, &cmd_head);
		else
			break ;
	}
	cmd = list_to_argv(&cmd_head);
	return (cmd);
}
