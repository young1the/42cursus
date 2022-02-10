#include "../../include/minishell.h"

char	*pop_token(t_token *token_head)
{
	char	*string;

	string = token_to_string(token_head);
	if (string == NULL)
		ft_fatal("minishell : MALLOC FAILED!\n");
	clear_token(token_head);
	return (string);
}
