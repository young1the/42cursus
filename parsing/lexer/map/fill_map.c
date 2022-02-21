#include "../../parsing.h"

static int		get_map_element(char c)
{
	if (c == ' ')
		return (NULL_SPACE);
	else if (c == '0')
		return (0);
	else if (c == '1')
		return (1);
	else if (c == 'N')
		return (2);
	else if (c == 'S')
		return (3);
	else if (c == 'W')
		return (4);
	else if (c == 'E')
		return (5);
	else
		return (NULL_SPACE);
}

static void	fill_x_map(t_cub *cub, int map_index, char *str)
{
	int		i;
	int		map_element;
	
	i = 0;
	while (str[i] != '\0')
	{
		map_element = get_map_element(str[i]);
		cub->map[map_index][i] = map_element;
		i++;
	}
	while (i < cub->size->x_size)
	{
		cub->map[map_index][i] = NULL_SPACE;
		i++;
	}
	return ;
}

void	fill_map(t_cub *cub, t_list *list_ptr)
{
	int		i;

	i = 0;
	while (i < cub->size->y_size)
	{
		fill_x_map(cub, i, list_ptr->str);
		i++;
		list_ptr = list_ptr->next;
	}
	return ;
}
