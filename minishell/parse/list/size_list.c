#include "../../include/minishell.h"

int	size_list(t_list *list_head)
{
	t_list	*list;
	int		i;

	i = 0;
	list = list_head->next;
	while (list != NULL)
	{
		list = list->next;
		i++;
	}
	return (i);
}
