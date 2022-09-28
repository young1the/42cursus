#include "../../include/minishell.h"

int	size_token(t_token *token_head)
{
	t_token	*token;
	int		i;

	i = 0;
	token = token_head->next;
	while (token != NULL)
	{
		token = token->next;
		i++;
	}
	return (i);
}
