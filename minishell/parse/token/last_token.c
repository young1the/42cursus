#include "../../include/minishell.h"

t_token	*last_token(t_token *token_head)
{
	t_token	*last;

	last = token_head;
	while (last->next != NULL)
		last = last->next;
	return (last);
}
