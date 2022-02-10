#include "../../include/minishell.h"

int	choose_type(int *prev_type, char *string)
{
	if (*prev_type == REDIRECTION)
		return (FILENAME);
	else
	{
		if (*string == '>' || *string == '<')
			return (REDIRECTION);
		else
			return (COMMAND);
	}
}

void	push_list(t_list *list_head, t_token *token_head,
			int *prev_type, int dollar_flag)
{
	int			type;
	char		*string;
	t_list		*new;

	if (token_head->next == NULL)
		return ;
	string = pop_token(token_head);
	if (dollar_flag == TRUE)
		manage_dollar(&string);
	type = choose_type(prev_type, string);
	*prev_type = type;
	new = new_list(string, type);
	add_list(list_head, new);
}
