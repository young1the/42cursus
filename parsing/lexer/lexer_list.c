#include "../parsing.h"

static int		check_flags(int *flag)
{
	int		i;

	i = 0;
	while (i < 6)
	{
		if (flag[i] == 0)
			return (1);
		i++;
	}
	return (0);
}

int	lexer_list(t_list *list_head)
{
	t_list	*list_ptr;
	int		flag[6];

	ft_memset(flag, OFF, sizeof(int) * 6);
	list_ptr = list_head->next;
	while (list_ptr != NULL && check_flags(flag))
	{
		fill_config(list_ptr->str, flag);
		list_ptr = list_ptr->next;
	}
	if (list_ptr == NULL)
	{
		if (check_flags(flag) == 1)
		{
			printf("Error! can't find config resources\n");
			return (FAILURE);
		}
		printf("Error! can't find map resources\n");
		return (FAILURE);
	}
	if (init_map(list_ptr) == FAILURE)
	{
		printf("Error! invalid map\n");
		return (FAILURE);
	}
	return (SUCCESS);
}
