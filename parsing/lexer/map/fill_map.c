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

static void	fill_x_map(t_cub *cub, int y, char *str)
{
	int		x;
	int		map_element;

	x = 0;
	while (str[x] != '\0')
	{
		map_element = get_map_element(str[x]);
		cub->map[x][y] = map_element;
		x++;
	}
	while (x < cub->size->x_size)
	{
		cub->map[x][y] = NULL_SPACE;
		x++;
	}
	return ;
}

void	fill_map(t_cub *cub, t_list *list_ptr)
{
	int		y;

	y = 0;
	while (y < cub->size->y_size)
	{
		fill_x_map(cub, y, list_ptr->str);
		y++;
		list_ptr = list_ptr->next;
	}
	return ;
}
