#include "../parsing.h"

t_list	*new_list(char *string)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->str = string;
	new->next = NULL;
	return (new);
}
