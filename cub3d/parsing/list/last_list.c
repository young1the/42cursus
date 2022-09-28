#include "../parsing.h"

t_list	*last_list(t_list *list_head)
{
	t_list	*last;

	last = list_head;
	while (last->next != NULL)
		last = last->next;
	return (last);
}
