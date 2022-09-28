#include "engine.h"

static int	get_t_cast(t_cub *cub, t_wall *wall, t_cast *cast, char type)
{
	wall->dist = 0;
	if (type == 'y')
	{
		cast->step = get_sign(sin(cast->ray));
		if (cast->step == 0)
			return (FAILURE);
		cast->slope = 1. / tan(cast->ray);
		if (cast->step > 0)
			cast->y = floor(cub->player->y + 1);
		else
			cast->y = ceil(cub->player->y - 1);
	}
	else
	{
		cast->step = get_sign(cos(cast->ray));
		if (cast->step == 0)
			return (FAILURE);
		cast->slope = tan(cast->ray);
		if (cast->step > 0)
			cast->x = floor(cub->player->x + 1);
		else
			cast->x = ceil(cub->player->x - 1);
	}
	return (SUCCESS);
}

static int	cast_y(t_cub *cub, t_wall *wall, double ray)
{
	t_cast	cast;

	cast.ray = ray;
	if (get_t_cast(cub, wall, &cast, 'y') == FAILURE)
		return (FAILURE);
	while (cast.y >= 0 && cast.y < cub->size->y_size)
	{
		cast.x = cast.slope * (cast.y - cub->player->y) + cub->player->x;
		if (cast.step > 0)
		{
			if (map_get_cell((int)cast.x, (int)cast.y) == 1)
				return (hit(wall, cast.x, cast.y, S));
		}
		else
		{
			if (map_get_cell((int)cast.x, (int)(cast.y - 1)) == 1)
				return (hit(wall, cast.x, cast.y, N));
		}
		cast.y += cast.step;
	}
	return (FAILURE);
}

static int	cast_x(t_cub *cub, t_wall *wall, double ray)
{
	t_cast	cast;

	cast.ray = ray;
	if (get_t_cast(cub, wall, &cast, 'x') == FAILURE)
		return (FAILURE);
	while (cast.x >= 0 && cast.x < cub->size->x_size)
	{
		cast.y = cast.slope * (cast.x - cub->player->x) + cub->player->y;
		if (cast.step > 0)
		{
			if (map_get_cell((int)cast.x, (int)cast.y) == 1)
				return (hit(wall, cast.x, cast.y, E));
		}
		else
		{
			if (map_get_cell((int)(cast.x - 1), (int)cast.y) == 1)
				return (hit(wall, cast.x, cast.y, W));
		}
		cast.x += cast.step;
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

void	ray_casting(void)
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
