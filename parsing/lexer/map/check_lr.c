#include "../../parsing.h"

static int	check_lrside(t_cub *cub, int x, int y, int *close)
{
	if (x == 0 || x + 1 == cub->size->x_size)
	{
		printf ("[%d, %d] is invalid element\n", x, y);
		return (FAILURE);
	}
	if (y == 0 || y + 1 == cub->size->y_size)
	{
		printf ("[%d, %d] is invalid element\n", x, y);
		return (FAILURE);
	}
	if (close[y - 1] && close[y] && close[y + 1])
		return (SUCCESS);
	else
	{
		printf ("[%d, %d] is invalid element\n", x, y);
		return (FAILURE);
	}
}

int	check_right(t_cub *cub)
{
	int	*close;
	int	x;
	int	y;

	close = (int *)malloc(sizeof(int) * cub->size->x_size);
	x = cub->size->x_size - 1;
	while (x >= 0)
	{
		y = cub->size->y_size - 1;
		while (y >= 0)
		{
			if (cub->map[y][x] == 1)
				close[y] = 1;
			else if (cub->map[y][x] == NULL_SPACE)
				close[y] = 0;
			else
			{
				if (check_lrside(cub, x, y, close) == FAILURE)
					return (FAILURE);
			}
			y--;
		}
		x--;
	}
	return (SUCCESS);
}

int	check_left(t_cub *cub)
{
	int	*close;
	int	x;
	int	y;

	close = (int *)malloc(sizeof(int) * cub->size->x_size);
	x = 0;
	while (x < cub->size->x_size)
	{
		y = 0;
		while (y < cub->size->y_size)
		{
			if (cub->map[y][x] == 1)
				close[y] = 1;
			else if (cub->map[y][x] == NULL_SPACE)
				close[y] = 0;
			else
			{
				if (check_lrside(cub, x, y, close) == FAILURE)
					return (FAILURE);
			}
			y++;
		}
		x++;
	}
	return (SUCCESS);
}