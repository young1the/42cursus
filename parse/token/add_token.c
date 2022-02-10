#include "../../include/minishell.h"

void	add_token(t_token *token_head, t_token *new)
{
	t_token	*tmp;

	tmp = last_token(token_head);
	tmp->next = new;
	new->next = NULL;
}
