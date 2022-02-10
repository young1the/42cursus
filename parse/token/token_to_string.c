#include "../../include/minishell.h"

char	*token_to_string(t_token *token_head)
{
	t_token	*temp;
	int		len;
	int		index;
	char	*string;

	temp = token_head->next;
	len = size_token(token_head);
	string = (char *)malloc(sizeof(char) * len + 1);
	if (string == NULL)
		return (NULL);
	index = 0;
	while (temp != NULL)
	{
		string[index] = temp->c;
		index++;
		temp = temp->next;
	}
	string[index] = '\0';
	return (string);
}
