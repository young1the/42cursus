#include "../../parsing.h"

static int	init_player(t_cub *cub, int px, int py)
{
	cub->player->x = (double)px + 0.5;
	cub->player->y = (double)py + 0.5;
	if (cub->map[px][py] == N)
		cub->player->th = deg_to_rad(270.);
	if (cub->map[px][py] == W)
		cub->player->th = deg_to_rad(180.);
	if (cub->map[px][py] == S)
		cub->player->th = deg_to_rad(90.);
	if (cub->map[px][py] == E)
		cub->player->th = deg_to_rad(0.);
	return (1);
}

int	find_player(t_cub *cub)
{
	int		x;
	int		y;
	int		check;

	x = -1;
	check = 0;
	while (++x < cub->size->x_size)
	{
		y = -1;
		while (++y < cub->size->y_size)
		{
			if (cub->map[x][y] > 1)
				check += init_player(cub, x, y);
		}
	}
	if (check != 1)
	{
		if (check < 1)
			ft_error("ERROR! no player\n");
		else if (check > 1)
			ft_error("ERROR! too many players\n");
		return (FAILURE);
	}
	else
		return (SUCCESS);
}
