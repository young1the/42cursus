#include "../../include/minishell.h"

t_token	*new_token(char c)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (new == NULL)
		return (NULL);
	new->c = c;
	new->next = NULL;
	return (new);
}
