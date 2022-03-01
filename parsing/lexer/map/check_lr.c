#include "../../parsing.h"

static int	check_lrside(t_cub *cub, int x, int y, int *close)
{
	if (x == 0 || x + 1 == cub->size->x_size)
		return (FAILURE);
	if (y == 0 || y + 1 == cub->size->y_size)
		return (FAILURE);
	if (close[y - 1] && close[y] && close[y + 1])
		return (SUCCESS);
	else
		return (FAILURE);
}

static int	check_util_y(t_cub *cub, int *close, int x, int y)
{
	if (cub->map[x][y] == 1)
		close[y] = 1;
	else if (cub->map[x][y] == NULL_SPACE)
		close[y] = 0;
	else
	{
		if (check_lrside(cub, x, y, close) == FAILURE)
		{
			free(close);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}

int	check_right(t_cub *cub)
{
	int	*close;
	int	x;
	int	y;

	close = (int *)malloc(sizeof(int) * cub->size->y_size);
	ft_memset(close, OFF, sizeof(int) * cub->size->y_size);
	x = cub->size->x_size - 1;
	while (x >= 0)
	{
		y = cub->size->y_size - 1;
		while (y >= 0)
		{
			if (check_util_y(cub, close, x, y) == FAILURE)
				return (FAILURE);
			y--;
		}
		x--;
	}
	free(close);
	return (SUCCESS);
}

int	check_left(t_cub *cub)
{
	int	*close;
	int	x;
	int	y;

	close = (int *)malloc(sizeof(int) * cub->size->y_size);
	ft_memset(close, OFF, sizeof(int) * cub->size->y_size);
	x = 0;
	while (x < cub->size->x_size)
	{
		y = 0;
		while (y < cub->size->y_size)
		{
			if (check_util_y(cub, close, x, y) == FAILURE)
				return (FAILURE);
			y++;
		}
		x++;
	}
	free(close);
	return (SUCCESS);
}
