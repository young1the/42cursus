#include "../include/cub3d.h"

int	map_get_cell(int x, int y)
{
	t_cub	*cub;

	cub = get_cub();
	if (x >= 0 && x < cub->size->x_size && y >=0 && y < cub->size->y_size)
		return (cub->map[x][y]);
	else
		return (-1);
}

double	get_angle_per_pixel()
{
	double	ret;
	double	fov_r;

	fov_r = deg_to_rad(FOV);
	ret = fov_r / (W_WIDTH - 1);
	return (ret);
}

typedef struct s_wall
{
	double	wx;
	double	wy;
	int		wdir;
}			t_wall;

int	get_wall_intersection(t_wall *wall, double ray_r)
{
	int		x_step;
	int		y_step;
	double	x_slope;
	double	y_slope;
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
		y_slope == INFINITY;
	else
		y_slope = 1./tan(ray_r);
	if (x_step > 0)
		nx = floor(cub->player->x) + 1;
	else if (x_step < 0)
		nx = ceil(cub->player->x) - 1;
	else
		nx = cub->player->x;
	if (y_step > 0)
		nx = floor(cub->player->y) + 1;
	else if (y_step < 0)
		nx = ceil(cub->player->y) - 1;
	else
		nx = cub->player->y;
}

void	cast_single_ray(t_wall *wall, int i)
{
	t_cub	*cub;
	double	ray_r;
	double	fov_r;

	fov_r = deg_to_rad(FOV);
	ray_r = (cub->player->th + fov_r / 2) - (i * get_angle_per_pixel());
	get_wall_intersection(wall, ray_r);
}

void	ray_casting()
{
	int		i;
	double	distance;
	t_wall	wall;

	i = 0;
	int sx = 720;
	while (i < sx)
	{
		cast_single_ray(&wall, i);
		// draw_wall(&ray);
		i++;
	}
}
