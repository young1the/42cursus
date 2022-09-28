#include "../../include/minishell.h"

void	clear_token(t_token *token_head)
{
	t_token	*token;
	t_token	*next;

	token = token_head->next;
	while (token != NULL)
	{
		next = token->next;
		free(token);
		token = next;
	}
	token_head->next = NULL;
}
