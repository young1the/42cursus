#include "../parsing.h"

void	add_list(t_list *list_head, t_list *new)
{
	t_list	*tmp;

	tmp = last_list(list_head);
	tmp->next = new;
	new->next = NULL;
}
