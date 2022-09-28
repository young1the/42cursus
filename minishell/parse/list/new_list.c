#include "../../include/minishell.h"

t_list	*new_list(char *string, int type)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->str = string;
	new->type = type;
	new->next = NULL;
	return (new);
}
