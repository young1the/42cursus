#include "../../include/minishell.h"

void	push_token(t_token *token_head, char c)
{
	t_token	*new;

	new = new_token(c);
	if (new == NULL)
		ft_fatal("minishell : MALLOC FAILED!\n");
	add_token(token_head, new);
}
