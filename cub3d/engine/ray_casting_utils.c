#include "engine.h"

int	map_get_cell(int x, int y)
{
	t_cub	*cub;

	cub = get_cub();
	if (x >= 0 && x < cub->size->x_size && y >= 0 && y < cub->size->y_size)
		return (cub->map[x][y]);
	else
		return (-1);
}

double	get_angle_per_pixel(void)
{
	double	ret;
	double	fov_h;

	fov_h = deg_to_rad(FOV_H);
	ret = fov_h / (W_WIDTH - 1);
	return (ret);
}

void	copy_wall(t_wall *origin, t_wall *copy)
{
	copy->x = origin->x;
	copy->y = origin->y;
	copy->dir = origin->dir;
	copy->dist = origin->dist;
}

int	hit(t_wall *wall, double x, double y, int dir)
{
	t_cub	*cub;

	cub = get_cub();
	wall->x = x;
	wall->y = y;
	wall->dir = dir;
	wall->dist = get_distance(cub->player->x, cub->player->y, x, y);
	return (SUCCESS);
}
