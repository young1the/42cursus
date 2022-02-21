#include "../../parsing.h"

static void	get_mapsize(t_list *list_ptr, t_cub *cub)
{
	int		x_size;
	int		y_size;
	int		len;

	x_size = 0;
	y_size = size_list(list_ptr);
	while (list_ptr != NULL)
	{
		len = ft_strlen(list_ptr->str);
		if (len > x_size)
			x_size = len;
		list_ptr = list_ptr->next;
	}
	cub->size->x_size = x_size;
	cub->size->y_size = y_size;
}

static int	allocate_map(t_cub *cub)
{
	int		i;

	cub->map = (int **)malloc(sizeof(int *) * cub->size->y_size);
	if (cub->map == NULL)
		return (FAILURE);
	i = 0;
	while (i < cub->size->y_size)
	{
		cub->map[i] = (int *)malloc(sizeof(int) * cub->size->x_size);
		if (cub->map == NULL)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

static int	check_validmap(t_cub *cub)
{
	if (check_up(cub) == FAILURE)
		return (FAILURE);
	else if (check_down(cub) == FAILURE)
		return (FAILURE);
	else if (check_left(cub) == FAILURE)
		return (FAILURE);
	else if (check_right(cub) == FAILURE)
		return (FAILURE);
	else
		return (SUCCESS);
}

int	init_map(t_list *list_ptr)
{
	t_cub	*cub;

	cub = get_cub();
	get_mapsize(list_ptr, cub);
	allocate_map(cub);
	fill_map(cub, list_ptr);
	if (check_validmap(cub) == FAILURE)
		return (FAILURE);
	return (0);
}
