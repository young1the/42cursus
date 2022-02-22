#include "../include/cub3d.h"

static int	map_get_cell(int x, int y)
{
	t_cub	*cub;

	cub = get_cub();
	if (x >= 0 && x < cub->size->x_size && y >=0 && y < cub->size->y_size)
		return (cub->map[x][y]);
	else
		return (-1);
}

static double	get_angle_per_pixel()
{
	double	ret;
	double	fov_r;

	fov_r = deg_to_rad(FOV);
	ret = fov_r / (W_WIDTH - 1);
	return (ret);
}

typedef struct s_wall
{
	int		x;
	int		y;
	int		dir;
	double	dis;
}			t_wall;

static int	get_wall_intersection(t_wall *wall, double ray_r)
{
	int		x_step;
	int		y_step;
	static double	x_slope;
	static double	y_slope;
	double	nx;
	double	ny;
	t_cub	*cub;

	cub = get_cub();
	x_step = get_sign(cos(ray_r));
	y_step = get_sign(sin(ray_r));
	if (x_step == 0)
		x_slope = INFINITY;
	else
		x_slope = tan(ray_r);
	if (y_step == 0)
		y_slope = INFINITY;
	else
		y_slope = 1./tan(ray_r);
	if (x_step > 0)
		nx = floor(cub->player->x) + 1;
	else if (x_step < 0)
		nx = ceil(cub->player->x) - 1;
	else
		nx = cub->player->x;
	if (y_step > 0)
		ny = floor(cub->player->y) + 1;
	else if (y_step < 0)
		ny = ceil(cub->player->y) - 1;
	else
		ny = cub->player->y;

	double	f;
	double	g;
	f = INFINITY;
	g = INFINITY;
	int		hit_side;
	int		hit;

	hit = 0;
	while (!hit)
	{
		if (x_step != 0)
			f = x_slope * (nx - cub->player->x) + cub->player->y;
		if (y_step != 0)
			g = y_slope * (ny - cub->player->y) + cub->player->x;
		double	dist_v = get_distance(cub->player->x, cub->player->y, nx, f);
		double	dist_h = get_distance(cub->player->x, cub->player->y, g, ny);
		if (dist_v < dist_h)
		{
			if (x_step > 0)
				wall->x = (int)nx;
			else
				wall->x = (int)nx - 1;
			wall->y = (int)f;
			hit_side = 1;	// VERT
		}
		else
		{
			wall->x = (int)g;
			if (y_step > 0)
				wall->y = (int)ny;
			else
				wall->y = (int)ny - 1;
			hit_side = 0; // HORIZ
		}
		int	cell = map_get_cell(wall->x, wall->y);
		if (cell < 0)
			break ;
		if (cell == 1)
		{
			if (hit_side == 1)
			{
				if (x_step > 0)
					wall->dir = W;
				else
					wall->dir = E;
				wall->x = nx;
				wall->y = f;
			}
			else
			{
				if (y_step > 0)
					wall->dir = S;
				else
					wall->dir = N;
				wall->x = g;
				wall->y = ny;
			}
			hit = 1;
			break ;
		}
		if (hit_side == 1)
			nx += x_step;
		else
			ny += y_step;
	}
	return (hit);
}

static void	cast_single_ray(t_wall *wall, int i)
{
	t_cub	*cub;
	double	ray_r;
	double	fov_r;

	cub = get_cub();
	fov_r = deg_to_rad(FOV);
	ray_r = (cub->player->th + fov_r / 2) - (i * get_angle_per_pixel());
	get_wall_intersection(wall, ray_r);
	wall->dis = get_distance(cub->player->x, cub->player->y, wall->x, wall->y);
	wall->dis *= cos(cub->player->th - ray_r);
}

int	get_wall_height(t_wall *wall)
{
	double	fov_h;
	double	fov_v;
	double	fov;

	fov_h = deg_to_rad(FOV);
	fov_v = fov_h*(double)W_HEIGHT/(double)W_WIDTH;
	fov = 2.0 * wall->dis * tan(fov_v/2.0);
	return ((int)(W_HEIGHT * 1 / fov));
}

void	draw_wall(t_wall *wall, int i)
{
	int	wh;

	(void)i;
	wh = get_wall_height(wall);
}


void	ray_casting()
{
	int		i;
	t_wall	wall;

	i = 0;
	while (i < W_WIDTH)
	{
		cast_single_ray(&wall, i);

		/* test */
		printf("iter[%d] wh : ", i);
		/* test */

		draw_wall(&wall, i);
		i++;
	}
}
