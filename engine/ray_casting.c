#include "engine.h"

static int	hit(t_wall *wall, double x, double y, int dir)
{
	t_cub	*cub;

	cub = get_cub();
	wall->x = x;
	wall->y = y;
	wall->dir = dir;
	wall->dist = get_distance(cub->player->x, cub->player->y, x, y);
	return (SUCCESS);
}

static int	cast_y(t_cub *cub, t_wall *wall, double ray)
{
	int		step;
	double	slope;
	double	x;
	double	y;

	wall->dist = 0;
	step = get_sign(sin(ray));
	if (step == 0)
		return (FAILURE);
	slope = 1./tan(ray);
	if (step > 0)
		y = floor(cub->player->y + 1);
	else
		y = ceil(cub->player->y - 1);
	while (y >= 0 && y < cub->size->y_size)
	{
		x = slope * (y- cub->player->y) + cub->player->x;
		if (step > 0)
		{
			if (map_get_cell((int)x, (int)y) == 1)
				return (hit(wall, x, y, S));
		}
		else
		{
			if (map_get_cell((int)x, (int)(y - 1)) == 1)
				return (hit(wall, x, y, N));
		}
		y += step;
	}
	return (FAILURE);
}

static int	cast_x(t_cub *cub, t_wall *wall, double ray)
{
	int		step;
	double	slope;
	double	x;
	double	y;

	wall->dist = 0;
	step = get_sign(cos(ray));
	if (step == 0)
		return (FAILURE);
	slope = tan(ray);
	if (step > 0)
		x = floor(cub->player->x + 1);
	else
		x = ceil(cub->player->x - 1);
	while (x >= 0 && x < cub->size->x_size)
	{
		y = slope * (x - cub->player->x) + cub->player->y;
		if (step > 0)
		{
			if (map_get_cell((int)x, (int)y) == 1)
				return (hit(wall, x, y, E));
		}
		else
		{
			if (map_get_cell((int)(x - 1), (int)y) == 1)
				return (hit(wall, x, y, W));
		}
		x += step;
	}
	return (FAILURE);
}

static double	cast_single_ray(t_wall *wall, int x)
{
	t_cub	*cub;
	double	ray;
	t_wall	wall_x;
	t_wall	wall_y;

	cub = get_cub();
	ray = (cub->player->th + deg_to_rad(FOV_H) / 2) - get_angle_per_pixel() * x;
	cast_x(cub, &wall_x, ray);
	cast_y(cub, &wall_y, ray);
	if (wall_x.dist == 0)
	{
		copy_wall(&wall_y, wall);
		return (ray);
	}
	if (wall_y.dist == 0)
	{
		copy_wall(&wall_x, wall);
		return (ray);
	}
	if (wall_x.dist > wall_y.dist)
		copy_wall(&wall_y, wall);
	else
		copy_wall(&wall_x, wall);
	return (ray);
}

void	ray_casting()
{
	int		x;
	double	sup;
	t_wall	wall;
	t_cub	*cub;

	x = 0;
	cub = get_cub();
	cub->img.img = mlx_new_image(cub->mlx, W_WIDTH, W_HEIGHT);
	cub->img.data = mlx_get_data_addr(cub->img.img,
	&(cub->img.bpp), &(cub->img.line_size), &(cub->img.endian));
	draw_floorceil(cub);
	while (x < W_WIDTH)
	{
		sup = cast_single_ray(&wall, x);
		wall.dist *= cos(cub->player->th - sup);
		draw_wall(&wall, x);
		x++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	return ;
}
