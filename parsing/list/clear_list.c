#include "../parsing.h"

void	clear_list(t_list *list_head)
{
	t_list	*list;
	t_list	*next;

	list = list_head->next;
	while (list != NULL)
	{
		next = list->next;
		free(list->str);
		free(list);
		list = next;
	}
}
