#include "../../parsing.h"

static int	check_udside(t_cub *cub, int x, int y, int *close)
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
	if (close[x - 1] && close[x] && close[x + 1])
		return (SUCCESS);
	else
	{
		printf ("[%d, %d] is invalid element\n", x, y);
		return (FAILURE);
	}
}

int	check_up(t_cub *cub)
{
	int	*close;
	int	x;
	int	y;

	close = (int *)malloc(sizeof(int) * cub->size->x_size);
	y = 0;
	while (y < cub->size->y_size)
	{
		x = 0;
		while (x < cub->size->x_size)
		{
			if (cub->map[y][x] == 1)
				close[x] = 1;
			else if (cub->map[y][x] == NULL_SPACE)
				close[x] = 0;
			else
			{
				if (check_udside(cub, x, y, close) == FAILURE)
					return (FAILURE);
			}
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

int	check_down(t_cub *cub)
{
	int	*close;
	int	x;
	int	y;

	close = (int *)malloc(sizeof(int) * cub->size->x_size);
	y = cub->size->y_size - 1;
	while (y >= 0)
	{
		x = cub->size->x_size - 1;
		while (x >= 0)
		{
			if (cub->map[y][x] == 1)
				close[x] = 1;
			else if (cub->map[y][x] == NULL_SPACE)
				close[x] = 0;
			else
			{
				if (check_udside(cub, x, y, close) == FAILURE)
					return (FAILURE);
			}
			x--;
		}
		y--;
	}
	return (SUCCESS);
}
